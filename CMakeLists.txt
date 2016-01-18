cmake_minimum_required(VERSION 2.6)
project(generalpurposeio)

add_executable(generalpurposeio main.cpp)

install(TARGETS generalpurposeio RUNTIME DESTINATION bin)
