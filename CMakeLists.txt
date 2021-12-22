cmake_minimum_required(VERSION 3.0)
project(PS5 C)

set(CMAKE_C_STANDARD 99)

add_executable(PS5 main.c node.c node.h stack.c stack.h rpn.c rpn.h errors.h convert.c convert.h errors.c)
