cmake_minimum_required(VERSION 2.8)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

project(Tests C)

include_directories(include ${CMAKE_SOURCE_DIR}/include)

aux_source_directory(${CMAKE_SOURCE_DIR}/src/core   SRC_CORE_FILES)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/script SRC_SCRIPT_FILES)

set(SRC_FILES ${SRC_CORE_FILES} ${SRC_SCRIPT_FILES})

add_definitions(-DFULL_PATH_TO_SCRIPTS="${CMAKE_CURRENT_SOURCE_DIR}/scripts" -DD_GNU_SOURCE=1 -DD_REENTRANT)

add_executable(default_value
  src/default_value.c
  ${SRC_FILES})

add_executable(init
  src/init.c
  ${SRC_FILES})

add_executable(init_error
  src/init_error.c
  ${SRC_FILES})

add_executable(open_window
  src/open_window.c
  ${SRC_FILES})

add_executable(open_window_error
  src/open_window_error.c
  ${SRC_FILES})

add_executable(main_loop
  src/main_loop.c
  ${SRC_FILES})

add_executable(context_lua_bind
  src/context_lua_bind.c
  ${SRC_FILES})

set(ALL_EXECUTABLE_TARGET
  default_value init open_window main_loop context_lua_bind)

foreach(TARGET ${ALL_EXECUTABLE_TARGET})
  target_link_libraries(${TARGET} lua SDL pthread)
endforeach(${TARGET})

add_custom_target(test
  COMMAND default_value
  COMMAND init
  COMMAND open_window
  COMMAND main_loop
  COMMAND context_lua_bind
  DEPENDS ${ALL_EXECUTABLE_TARGET})
