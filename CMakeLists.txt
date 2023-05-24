cmake_minimum_required(VERSION 3.25)
project(car_workshop_worker_scheduler C)

set(CMAKE_C_STANDARD 17)

add_compile_options(-Wall -Wextra)

add_executable(car_workshop_worker_scheduler src/main.c src/schedule.c lib/terminal.c src/constants/terminal_colors.c)
