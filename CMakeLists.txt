cmake_minimum_required(VERSION 3.11)

project("Tank Of Destiny")

set(BIN_NAME tankofdestiny)

project(${BIN_NAME} CXX)

aux_source_directory(src SRC_FILES)

add_executable(${BIN_NAME} ${SRC_FILES})

find_library(GLFW glfw)
target_link_libraries(${BIN_NAME} ${GLFW})

set_property(TARGET ${BIN_NAME} PROPERTY CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall")

# Run program
add_custom_target(run ${BIN_NAME})
