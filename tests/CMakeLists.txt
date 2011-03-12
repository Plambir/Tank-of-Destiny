cmake_minimum_required(VERSION 2.8)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

project(Tests C)

include_directories(include ${CMAKE_SOURCE_DIR}/include)

add_definitions(-DD_GNU_SOURCE=1 -DD_REENTRANT)

add_executable(default_value src/default_value.c ${CMAKE_SOURCE_DIR}/src/init.c ${CMAKE_SOURCE_DIR}/src/quit.c)
add_executable(init src/init.c ${CMAKE_SOURCE_DIR}/src/init.c ${CMAKE_SOURCE_DIR}/src/quit.c)
add_executable(init_error src/init_error.c ${CMAKE_SOURCE_DIR}/src/init.c ${CMAKE_SOURCE_DIR}/src/quit.c)

target_link_libraries(default_value SDL pthread)
target_link_libraries(init SDL pthread)
target_link_libraries(init_error SDL pthread)

add_custom_target(test
  COMMAND default_value
  COMMAND init
  COMMAND DISPLAY=error ${EXECUTABLE_OUTPUT_PATH}/init_error
  DEPENDS default_value init init_error)
