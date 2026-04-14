cmake_minimum_required(VERSION 3.10)
project(EAE_Firmware)

set(CMAKE_CXX_STANDARD 17)

add_executable(cooling_app
    src/main.cpp
    src/controller.cpp
    src/state_machine.cpp
    src/can_sim.cpp
)


enable_testing()

add_executable(test_controller
    test/test_controller.cpp
    test/test_main.cpp
    src/controller.cpp
)

target_include_directories(test_controller PRIVATE src)

target_link_libraries(test_controller gtest gtest_main pthread)

add_test(NAME ControllerTest COMMAND test_controller)