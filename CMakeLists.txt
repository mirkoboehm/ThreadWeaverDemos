# Top level CMake file for ThreadWeaverDemos
cmake_minimum_required(VERSION 2.8.12)
find_package(ECM 0.0.9 REQUIRED NO_MODULE)
# Project name
project(ThreadWeaverDemos)

# Tell CMake we will be using C++ 11:
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

# Find and link the ThreadWeaver framework:
find_package(KF5ThreadWeaver ${KF5_VERSION} REQUIRED)

add_subdirectory(HelloWorld)
add_subdirectory(HelloWorldRaw)
add_subdirectory(SequenceDemo)
add_subdirectory(ImageViewer)
