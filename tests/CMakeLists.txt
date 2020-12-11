#####################################################################################################
#### Setting up versioning with CMake, the version is chosen based on modern cmake.               ###
#### It is important to keep the minimum version above 3.12 as this project uses CMake features   ###
#### from this release, and also because it might cause linker errors on lower versions on MacOS. ###
####                                                                                              ###
#### See: https://cliutils.gitlab.io/modern-cmake/chapters/basics.html                            ###
#####################################################################################################
#cmake_minimum_required(VERSION 3.12...3.18)
#
#
#
#####################################################################################################
#### Settings properties used in this cmake file                                                  ###
#####################################################################################################
#set(TEST_EXECUTABLE_NAME Linal_tests)
#
#
#
#####################################################################################################
#### Using CMake 3.12+ GLOB feature for finding source files                                      ###
#### Create the tests executable with the modules included to tests them                            ###
#####################################################################################################
#file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS ./src/*.cpp)
#add_executable(${TEST_EXECUTABLE_NAME} ${TEST_SOURCES})
##target_link_libraries(${TEST_EXECUTABLE_NAME} PRIVATE Linal)
##target_link_libraries(${TEST_EXECUTABLE_NAME} PRIVATE game)



####################################################################################################
### Add all the different tests for ctest                                                        ###
####################################################################################################
add_test(NAME ${TEST_EXECUTABLE_NAME} COMMAND ${TEST_EXECUTABLE_NAME})