# Project name
project(SequenceDemo)
find_package(Qt5 COMPONENTS Core Network Xml Widgets REQUIRED)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Add the SequenceDemo executable and link the ThreadWeaver framework:
add_executable(ThreadWeaver_SequenceDemo 
    LatestUpdateRetriever.cpp
    Parser.cpp
    SequenceDemo.cpp
    main.cpp
    SequenceDemo.ui
)
qt5_use_modules(ThreadWeaver_SequenceDemo Core Network Xml Widgets)
qt5_wrap_ui(ui_SequenceDemo.h SequenceDemo.ui)
target_link_libraries(ThreadWeaver_SequenceDemo KF5::ThreadWeaver)

