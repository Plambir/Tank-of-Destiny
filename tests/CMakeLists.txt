cmake_minimum_required(VERSION 2.8)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

project(Tests C)

include_directories(include ${CMAKE_SOURCE_DIR}/include)

add_executable(default_value src/default_value.c ${CMAKE_SOURCE_DIR}/src/init.c ${CMAKE_SOURCE_DIR}/src/quit.c)

add_custom_target(test
  COMMAND default_value)
