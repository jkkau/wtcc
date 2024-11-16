cmake_minimum_required(VERSION 3.14)

project(
  wtcc
  LANGUAGES C
)

FILE(GLOB headers "${CMAKE_SOURCE_DIR}/*.h")
FILE(GLOB sources "${CMAKE_SOURCE_DIR}/*.c")

add_executable(wtcc ${sources} ${headers})