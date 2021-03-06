# cocos2d-x v3.5 Release Notes #
<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [Misc Information](#misc-information)
- [Requirements](#requirements)
  - [Runtime Requirements](#runtime-requirements)
  - [Compiler Requirements](#compiler-requirements)
  - [How to run tests](#how-to-run-tests)
    - [Mac OSX & iOS](#mac-osx-&-ios)
    - [Android](#android)
    - [Windows](#windows)
    - [Linux](#linux)
  - [How to start a new game](#how-to-start-a-new-game)
- [v3.6beta0](#v36beta0)
  - [Highlights of v3.6beta0](#highlights-of-v36beta0)
  - [Features in detail](#features-in-detail-1)
    - [3D TextureCube](#3d-texturecube)
    - [3D Skybox](#3d-skybox)
    - [Animate3D Quality Control](#animate3d-quality-control)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# Misc Information

* [Full Changelog](https://github.com/cocos2d/cocos2d-x/blob/v3/CHANGELOG)
* v3.0 Release Notes can be found here: [v3.0 Release Notes](https://github.com/cocos2d/cocos2d-x/blob/cocos2d-x-3.0/docs/RELEASE_NOTES.md)

# Requirements

## Runtime Requirements

* Android 2.3 or newer
* iOS 5.0 or newer
* OS X 10.7 or newer
* Windows 7 or newer
* Windows Phone 8 or newer
* Linux Ubuntu 14.04 or newer

## Compiler Requirements

* Xcode 5.1 or newer for iOS or Mac
* gcc 4.9 or newer for Linux
* ndk-r10c for Android
* Visual Studio 2012  or newer for Windows (win32)
* Visual Studio 2012  or newer for Windows Phone 8

## How to run tests

### Mac OSX & iOS

* Enter `cocos2d-x/build` folder, open `cocos2d_test.xcodeproj`
* Select `iOS` or `OS X` target in scheme toolbar
* Click `run` button

### Android

You can run the samples...

**Using command line:**

    $ cd cocos2d-x
    $ ./setup.py
    $ cd build
    $ ./android-build.py cpp-empty-test -p 10
    $ adb install cocos2d-x/tests/cpp-empty-test/proj.android/bin/CppEmptyTest-debug.apk

Then click item on Android device to run tests. Available value of `-p` is the API level, cocos2d-x supports from level 10.

**Using Eclipse:**

    $ cd cocos2d-x
    $ ./setup.py
    $ cd build
    $ ./android-build.py cpp-empty-test -p 10

Then

* Import cocos2d-x Android project into Eclipse, the path used to import is `cocos/2d/platform/android`
* Import `cpp-empty-test` Android project into Eclipse, the path used to import is `tests/cpp-empty-test/proj.android`
* Build `cpp-empty-test` Android project and run

### Windows

* Enter `cocos2d-x/build`, and open `cocos2d-win32.vs2012.sln`
* Select `cpp-empty-test` as running target
* Click run button


### Linux

    $ cd cocos2d-x/build
    $ ./install-deps-linux.sh
    $ cd ../..

Then

    $ mkdir build
    $ cd build
    $ cmake ../cocos2d-x
    $ make -j4

Run

    $ cd bin/cpp-empty-test
    $ ./cpp-empty-test

## How to start a new game

Please refer to this document: [ReadMe](../README.md)

# v3.6beta0

## Highlights of v3.6beta0
## Features in detail

### 3D TextureCube

TextureCube is useful for skybox and environment mapping. It uses 6 faces of a cube as map shape, and 6 pictures are projected onto the sides of a cube and stored as six square textures.

#### TexturesCube usage

```c++
auto texturecube = TextureCube::create("left.jpg", "right.jpg", "top.jpg", "bottom.jpg","front.jpg", "back.jpg");
//set texture parameters
Texture2D::TexParams tRepeatParams;
tRepeatParams.magFilter = GL_NEAREST;
tRepeatParams.minFilter = GL_NEAREST;
tRepeatParams.wrapS = GL_MIRRORED_REPEAT;
tRepeatParams.wrapT = GL_MIRRORED_REPEAT;
texturecube->setTexParameters(tRepeatParams);

//create a GLProgramState using custom shader
auto shader = GLProgram::createWithFilenames("cube_map.vert", "cube_map.frag");
auto state = GLProgramState::create(shader);
// pass the texture sampler to our custom shader, state is a pointer of GLProgramState, u_cubeTex is a uniform in shader
state->setUniformTexture("u_cubeTex", texturecube);
```

Then the shader cube_map.frag can be something like this,

```c++
varying vec3        v_reflect; //reflect direction
uniform samplerCube u_cubeTex;

void main(void)
{
    gl_FragColor = textureCube(u_cubeTex, v_reflect); //sample the color of reflection direction
}
```

For more information please refer to cpp-tests/Sprite3DTest/Sprite3DCubeMapTest.

### 3D Skybox

Skybox is a common component in 3D game. It is based on TextureCube.

Usage of skybox

```c++
// create a texture cube
auto textureCube = TextureCube::create("left.jpg", "right.jpg","top.jpg", "bottom.jpg","front.jpg", "back.jpg");
//create a skybox
auto skyBox = Skybox::create();
skyBox->retain();
//set cube texture to the skybox
skyBox->setTexture(textureCube);
addChild(_skyBox);
```

For more information please refer to cpp-tests/Sprite3DTest/Sprite3DCubeMapTest.

### Animate3D Quality Control

In order to make `Animate3D` run fast, you can use low quality animation.

```c++
std::string fileName = "Sprite3DTest/orc.c3b";
auto sprite = Sprite3D::create(fileName);
addChild(sprite);
    
auto animation = Animation3D::create(fileName);
if (animation)
{
   auto animate = Animate3D::create(animation);
   //use low quality animation
   animate->setHighQuality(false);
   sprite->runAction(RepeatForever::create(animate));
}
```

The animation quality is also configurable in config.plist, the key is cocos2d.x.3d.animate_high_quality. All the created `Animate3D` base on this key if exist. You can modify it using the above method.
