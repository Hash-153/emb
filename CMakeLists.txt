cmake_minimum_required(VERSION 3.16)
project(TitanCore_RT C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(include tests sim)

file(GLOB_RECURSE SOURCES "src/*.c" "tests/*.c" "sim/*.c")

add_executable(titan_sim ${SOURCES})

target_compile_definitions(titan_sim PRIVATE TITAN_HOST_SIMULATION=1)

if(MSVC)
    target_compile_options(titan_sim PRIVATE /W4)
else()
    target_compile_options(titan_sim PRIVATE -Wall -Wextra -pedantic)
endif()
