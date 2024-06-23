cmake_minimum_required(VERSION 3.28)

project(iamnotaway
        VERSION 0.0.1
        LANGUAGES CXX)

set(SOURCES main.cpp)

add_executable(iamnotaway ${SOURCES})
target_link_options(iamnotaway PRIVATE -mwindows)
