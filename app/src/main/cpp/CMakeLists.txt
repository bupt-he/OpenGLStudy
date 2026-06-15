# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

# Declares the project name. The project name can be accessed via ${ PROJECT_NAME},
# Since this is the top level CMakeLists.txt, the project name is also accessible
# with ${CMAKE_PROJECT_NAME} (both CMake variables are in-sync within the top level
# build script scope).
project("ndkopenglstudy")

#包含目录，包含三方库的头文件夹，以及自定义的头文件夹
#包含的目录顺序，会影响编译的结果

# 传统的配合方式
# include_directories:告诉编译器去哪里找**头**文件（自定义目录）
# file：自动收集所有源文件（*.cpp）
# add_library: 用收集的源文件构建库

# 现代方式 target_include_directories + 显式源文件 + add_library
##1. 显式列出源文件（推荐）
# set(SOURCES
#    src/main.cpp
#    src/render/opengl.cpp
#    src/render/shader.cpp
#    src/util/logger.cpp
#)
## 2. 创建库目标
#add_library(myengine SHARED ${SOURCES})
## 3. 为目标精确添加头文件路径
#target_include_directories(myengine
#    PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/include/public  # 暴露给依赖方
#    PRIVATE
#        ${CMAKE_CURRENT_SOURCE_DIR}/include/private # 仅 myengine 内部使用
#        ${CMAKE_CURRENT_SOURCE_DIR}/third_party/glm
#)
include_directories(
        base
        render
        sample
        utils
)

file(GLOB src-files
        ${CMAKE_SOURCE_DIR}/*.cpp
        ${CMAKE_SOURCE_DIR}/render/*.cpp
        ${CMAKE_SOURCE_DIR}/utils/*.cpp
        ${CMAKE_SOURCE_DIR}/sample/*.cpp
        ${CMAKE_SOURCE_DIR}/base/*.cpp
)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
#
# In this top level CMakeLists.txt, ${CMAKE_PROJECT_NAME} is used to define
# the target library name; in the sub-module's CMakeLists.txt, ${PROJECT_NAME}
# is preferred for the same purpose.
#
# In order to load a library into your app from Java/Kotlin, you must call
# System.loadLibrary() and pass the name of the library defined here;
# for GameActivity/NativeActivity derived applications, the same library name must be
# used in the AndroidManifest.xml file.


add_library(
        ${CMAKE_PROJECT_NAME}
        SHARED
        ${src-files}
)

#add_library(${CMAKE_PROJECT_NAME} SHARED
#        # List C/C++ source files with relative paths to this CMakeLists.txt.
#        native-lib.cpp)


find_library(
        log-lib
        log
)

# Specifies libraries CMake should link to your target library. You
# can link libraries from various origins, such as libraries defined in this
# build script, prebuilt third-party libraries, or Android system libraries.
target_link_libraries(${CMAKE_PROJECT_NAME}
        # List libraries link to the target library
        android
        ${log-lib}
        GLESv3
)