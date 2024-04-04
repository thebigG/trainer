cmake_minimum_required(VERSION 3.21)

project(EXAMPLE_NOTIFY)

message("-- [INFO] Building Example")

add_executable(example_notify
    notify.cpp
    ../common/utils.cpp
)


# find_package(simpleble REQUIRED CONFIG) In the future for building with installed simpleBLE lib on the system

add_subdirectory(../SimpleBLE/simpleble ${CMAKE_BINARY_DIR}/simpleble)

target_link_libraries(example_notify simpleble::simpleble)
