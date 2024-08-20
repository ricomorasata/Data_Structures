

cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_STANDARD 99 CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O2")

set(EXECUTABLE_OUTPUT_PATH ./bin)

project(main LANGUAGES C)

include_directories(${CMAKE_SOURCE_DIR}/headers)


file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/sources/*.c)


# add_library(arma SHARED IMPORTED) 

# set_target_properties(arma PROPERTIES
#   					IMPORTED_LOCATION "/usr/lib/x86_64-linux-gnu/libarmadillo.so"
#   					INTERFACE_INCLUDE_DIRECTORIES "/usr/include/"
# 					)

add_executable(main ${SOURCES})

target_link_libraries(main m) 

