cmake_minimum_required(VERSION 3.1)

project(OLAS)

add_subdirectory(Adder)
add_subdirectory(modules/glfw)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC Adder/)
#######################################################
# the below all wrong ...
#
#target_include_directories(${PROJECT_NAME}  Adder/) 
#
#######################################################

target_include_directories(${PROJECT_NAME} PUBLIC modules/glfw/include)

target_link_libraries(${PROJECT_NAME} AdderCal)
#######################################################
# the below all wrong ...
#
#target_link_libraries(${PROJECT_NAME} lAdderCal)
#target_link_libraries(${PROJECT_NAME} libAdderCal)
#target_link_libraries(${PROJECT_NAME} libAdderCal.a)
#
#######################################################
target_link_libraries(${PROJECT_NAME} glfw)
