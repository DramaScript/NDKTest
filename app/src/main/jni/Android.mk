LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := NdkTools
LOCAL_SRC_FILES := NdkTools.cpp
include $(BUILD_SHARED_LIBRARY)