cmake_minimum_required(VERSION 3.25)
project(car_workshop_worker_scheduler C)

set(CMAKE_C_STANDARD 17)

if (MSVC)
    add_compile_options(/W4 /WX)
else ()
    add_compile_options(-Wall -Wextra)
endif ()

add_executable(car_workshop_worker_scheduler src/main.c src/schedule.c lib/terminal.c src/constants/terminal_colors.c src/menu.c src/menu_controller.c src/error_handler.c src/file_handler.c)
