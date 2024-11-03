cmake_minimum_required(VERSION 3.28)
project(output-automaton)

set(SOURCES Sources)

include_directories(Include)

add_executable(out main.cpp ${SOURCES}/Automaton.cpp)