cmake_minimum_required(VERSION 2.8)

project(AdderCal)

file(GLOB SRCS *.cpp)

add_library(${PROJECT_NAME}  ${SRCS})

