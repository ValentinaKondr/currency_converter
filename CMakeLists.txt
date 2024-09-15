cmake_minimum_required(VERSION 3.5)

project(CurrencyConverter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(CurrencyConverter main.cpp ${SOURCES})

target_include_directories(CurrencyConverter PRIVATE ${CMAKE_SOURCE_DIR}/include)
