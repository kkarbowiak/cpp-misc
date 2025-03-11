cmake_minimum_required(VERSION 3.15)

project("msvc-view-error" LANGUAGES CXX)

add_executable(view)
target_sources(view PRIVATE main.cpp)
target_compile_features(view PRIVATE cxx_std_20)
