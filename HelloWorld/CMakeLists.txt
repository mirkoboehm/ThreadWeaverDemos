# For more information see the CMake documentation:
# http://www.cmake.org/cmake/help/documentation.html
# http://techbase.kde.org/Development/Tutorials/CMake

# Project name
project(HelloWorld)

# Look for the KArchive module
find_package(KF5ThreadWeaver ${KF5_VERSION} REQUIRED)

# Add the HelloWorld executable and link the ThreadWeaver library to it
add_executable(ThreadWeaver_HelloWorld HelloWorld.cpp)
target_link_libraries(ThreadWeaver_HelloWorld KF5::ThreadWeaver)

# Add the HelloWorldRaw executable...
add_executable(ThreadWeaver_HelloWorldRaw HelloWorldRaw.cpp)
target_link_libraries(ThreadWeaver_HelloWorldRaw KF5::ThreadWeaver)
