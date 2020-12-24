cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Linal)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)
file(GLOB_RECURSE TEST_SOURCES tests/*.cpp tests/*.hpp)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
add_executable(Tests ${TEST_SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME} ${CONAN_LIBS})
target_link_libraries(Tests ${CONAN_LIBS})

file(COPY resources DESTINATION ${CMAKE_BINARY_DIR}/bin)