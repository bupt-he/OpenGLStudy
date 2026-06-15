//
// Created by yobin_he on 2026/6/14.
//

#ifndef NDKOPENGLSTUDY_LOGUTILS_H
#define NDKOPENGLSTUDY_LOGUTILS_H

#include <android/log.h>

#define LOG_TAG "yobin"

#define  LOGCATE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  LOGCATV(...)  __android_log_print(ANDROID_LOG_VERBOSE,LOG_TAG,__VA_ARGS__)
#define  LOGCATD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGCATI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)


#define GO_CHECK_GL_ERROR(...)   LOGCATE("CHECK_GL_ERROR %s glGetError = %d, line = %d, ",  __FUNCTION__, glGetError(), __LINE__)

#define DEBUG_LOGCATE(...) LOGCATE("DEBUG_LOGCATE %s line = %d",  __FUNCTION__, __LINE__)



#endif //NDKOPENGLSTUDY_LOGUTILS_H
