cmake_minimum_required(VERSION 4.2)
project(Telefoonboek C)

set(CMAKE_C_STANDARD 23)

add_executable(Telefoonboek main.c
        contact.h
        contact.c)
