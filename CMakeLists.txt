cmake_minimum_required(VERSION 3.23)
project(project3_nhom_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(project3_nhom_1
        findByID.c
        findByPosition.c
        findBySalary.c
        findByYear.c
        input.c
        main.c
        menu.c
        showData.c
        struct.h)
