cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_MODULE_PATH "E:/github/USD_Debug")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(testqt)

# QT

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# usd

add_definitions(-DNOMINMAX)

add_definitions(-DTBB_USE_DEBUG)

find_package(pxr)

add_executable(testqt
    main.cpp
    widget.cpp
    widget.h
)

# link
target_link_libraries(testqt Qt5::Widgets)

target_link_libraries(testqt usd usdImagingGL)

include_directories("C:/Users/Jack/AppData/Local/Programs/Python/Python39/include")