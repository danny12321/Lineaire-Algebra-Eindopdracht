cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("Linal")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} tests/src/test1.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${CONAN_LIBS} )

#file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
#
#enable_testing()
#add_subdirectory(tests)
#add_subdirectory(src)