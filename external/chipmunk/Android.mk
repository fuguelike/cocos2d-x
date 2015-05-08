LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := chipmunk_static

LOCAL_MODULE_FILENAME := libchipmunk

LOCAL_CFLAGS := -std=c99

LOCAL_SRC_FILES := \
src/chipmunk.c \
src/cpConstraint.c \
src/cpDampedRotarySpring.c \
src/cpDampedSpring.c \
src/cpGearJoint.c \
src/cpGrooveJoint.c \
src/cpPinJoint.c \
src/cpPivotJoint.c \
src/cpRatchetJoint.c \
src/cpRotaryLimitJoint.c \
src/cpSimpleMotor.c \
src/cpSlideJoint.c \
src/cpArbiter.c \
src/cpArray.c \
src/cpBBTree.c \
src/cpBody.c \
src/cpCollision.c \
src/cpHashSet.c \
src/cpPolyShape.c \
src/cpShape.c \
src/cpSpace.c \
src/cpSpaceComponent.c \
src/cpSpaceHash.c \
src/cpSpaceQuery.c \
src/cpSpaceStep.c \
src/cpSpatialIndex.c \
src/cpSweep1D.c \
src/cpHastySpace.c \
src/cpMarch.c \
src/cpPolyline.c \
src/cpSpaceDebug.c \

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
                                 
include $(BUILD_STATIC_LIBRARY)
