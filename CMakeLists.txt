cmake_minimum_required(VERSION 3.28)
project(output-automaton)

set(SOURCES Sources)

include_directories(Include)
add_subdirectory(${SOURCES} SourceDirectory)
link_libraries(AutomatonAndInputs)

add_executable(a.out main.cpp)