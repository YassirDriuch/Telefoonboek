cmake_minimum_required(VERSION 3.5)
project(Telefoonboek C)

set(CMAKE_C_STANDARD 11)

add_executable(Telefoonboek main.c
        contact.h
        contact.c)
