cmake_minimum_required(VERSION 3.30)
project(rtos_sim)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(rtos_sim
        test/main.cpp
        src/task.cpp
        src/scheduler.cpp
)