cmake_minimum_required(VERSION 3.7)
project(EjerciciosArchivos)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Notas.h Notas.cpp)
add_executable(EjerciciosArchivos ${SOURCE_FILES})