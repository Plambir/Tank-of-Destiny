cmake_minimum_required(VERSION 2.8)

set(BIN_NAME tankofdestiny)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_C_FLAGS "-g -O0 -Wall -Wextra -Werror -pedantic -pedantic-errors")

project(${BIN_NAME} C)

aux_source_directory(src SRC_FILES)

include_directories(include)

add_executable(${BIN_NAME} ${SRC_FILES})

# Run program
add_custom_target(run ${BIN_NAME})

# Removing all files which created cmake
add_custom_target(clean_all rm -rf CMakeCache.txt
  CMakeFiles cmake_install.cmake Makefile bin)