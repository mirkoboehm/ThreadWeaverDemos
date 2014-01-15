# For more information see the CMake documentation:
# http://www.cmake.org/cmake/help/documentation.html
# http://techbase.kde.org/Development/Tutorials/CMake
cmake_minimum_required(VERSION 2.8.12)
# find KDE's extra cmake modules:
find_package(ECM 0.0.9 REQUIRED NO_MODULE)

# Project name
project(HelloWorld)

# Tell CMake we will be using C++ 11:
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

# Find and link the ThreadWeaver framework:
find_package(KF5ThreadWeaver ${KF5_VERSION} REQUIRED)

# Add the HelloWorld executable and link the ThreadWeaver library to it
add_executable(ThreadWeaver_HelloWorld HelloWorld.cpp)
target_link_libraries(ThreadWeaver_HelloWorld KF5::ThreadWeaver)

# Add the HelloWorldRaw executable...
# add_executable(ThreadWeaver_HelloWorldRaw HelloWorldRaw.cpp)
# target_link_libraries(ThreadWeaver_HelloWorldRaw KF5::ThreadWeaver)
