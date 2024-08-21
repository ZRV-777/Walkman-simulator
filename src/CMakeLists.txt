cmake_minimum_required(VERSION 3.27)

add_executable(modul_26_task_1 main.cpp
        ${MY_INCLUDE_DIR}/walkman.h
        ${MY_INCLUDE_DIR}/track.h
        walkman.cpp
        track.cpp
)
target_include_directories(modul_26_task_1 PUBLIC ${MY_INCLUDE_DIR})