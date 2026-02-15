cmake_minimum_required(VERSION 3.10)

project(unitconverter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(unitconverter
    src/main.cpp
    src/CsvHandler.cpp
    src/JsonHandler.cpp
    src/Length.cpp
)
