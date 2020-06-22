cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(vineCollection)

set(SRC_DIR src)
set(SOURCES ${SRC_DIR}/main.cpp ${SRC_DIR}/port.cpp ${SRC_DIR}/vintage_port.cpp)
set(INCLUDES include)

add_executable(testapp ${SOURCES})
target_include_directories(testapp PUBLIC ${INCLUDES})
