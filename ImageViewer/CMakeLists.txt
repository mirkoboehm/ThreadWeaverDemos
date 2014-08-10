# Project name
project(ImageViewer)
find_package(Qt5 COMPONENTS Core Network Xml Widgets REQUIRED)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Add the ImageViewer executable and link the ThreadWeaver framework:
add_executable(ThreadWeaver_ImageViewer 
    ComputeThumbNailJob.cpp
    QImageLoaderJob.cpp
    SMIVItem.cpp
    SMIVModel.cpp
    FileLoaderJob.cpp
    SMIV.cpp
    SMIVItemDelegate.cpp
    SMIVView.cpp
    SMIVBase.ui
)
qt5_use_modules(ThreadWeaver_ImageViewer Core Network Xml Widgets)
qt5_wrap_ui(ui_SMIVBase.h SMIVBase.ui)
target_link_libraries(ThreadWeaver_ImageViewer KF5::ThreadWeaver)

