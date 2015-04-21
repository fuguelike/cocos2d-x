LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := chipmunk_static

LOCAL_MODULE_FILENAME := libchipmunk

LOCAL_CFLAGS := -std=c99 -DCP_USE_DOUBLES=0 -DCP_ALLOW_PRIVATE_ACCESS=1
LOCAL_EXPORT_CFLAGS := -DCP_USE_DOUBLES=0 -DCP_ALLOW_PRIVATE_ACCESS=1

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
src/cpBB.c \
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
src/cpVect.c \
src/cpHastySpace.c \
src/cpMarch.c \
src/cpPolyline.c \
src/cpSpaceDebug.c \

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include/chipmunk

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include/chipmunk
LOCAL_CFLAGS := -std=c99
                                 
include $(BUILD_STATIC_LIBRARY)
