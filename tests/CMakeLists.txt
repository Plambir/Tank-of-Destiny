cmake_minimum_required(VERSION 2.8)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

project(Tests C)

include_directories(include ${CMAKE_SOURCE_DIR}/include)

add_definitions(-DD_GNU_SOURCE=1 -DD_REENTRANT)

set(INIT_QUIT ${CMAKE_SOURCE_DIR}/src/init.c ${CMAKE_SOURCE_DIR}/src/quit.c)
set(STUB_SDL_QUIT_AND_GET_ERROR src/stub_sdl_quit.c src/stub_sdl_get_error.c)
set(STUB_SDL_INIT src/stub_sdl_init.c)
set(STUB_SDL_INIT_ERROR src/stub_sdl_init_error.c)

add_executable(default_value src/default_value.c ${INIT_QUIT} ${STUB_SDL_QUIT_AND_GET_ERROR} ${STUB_SDL_INIT})
add_executable(init src/init.c ${INIT_QUIT} ${STUB_SDL_QUIT_AND_GET_ERROR} ${STUB_SDL_INIT})
add_executable(init_error src/init_error.c ${INIT_QUIT} ${STUB_SDL_QUIT_AND_GET_ERROR} ${STUB_SDL_INIT_ERROR})

add_custom_target(test
  COMMAND default_value
  COMMAND init
  COMMAND init_error
  DEPENDS default_value init init_error)
