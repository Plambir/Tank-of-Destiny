cmake_minimum_required(VERSION 3.11)

project("Tank Of Destiny")

set(BIN_NAME tankofdestiny)

project(${BIN_NAME} C)

aux_source_directory(src SRC_FILES)

add_executable(${BIN_NAME} ${SRC_FILES})

target_link_libraries(${BIN_NAME})

set_property(TARGET ${BIN_NAME} PROPERTY C_STANDARD 99)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall")

# Run program
add_custom_target(run ${BIN_NAME})
