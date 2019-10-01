cmake_minimum_required(VERSION 3.1.0)
project(QRoboticsCenter)

set(QRC_VERSION 5.0.0)
set(IS_RELEASE 1)

# option(SOME_OPTION "What this option is doing" OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
  set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 REQUIRED
  Core
  PrintSupport
  Gui
  Widgets
)

add_executable(QRoboticsCenter
  QRoboticsCenter/.ui
  mainwindow.cpp
  main.cpp
  resources.qrc
)

target_link_libraries(helloworld Qt5::Widgets)
