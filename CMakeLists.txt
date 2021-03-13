cmake_minimum_required(VERSION 3.1)

project(OLAS VERSION 1.0)

configure_file(OLASConfig.h.in OLASConfig.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(Adder)
#######################################################
#   git submodule update init when compile
#
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.gitmodules")
#if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.gitmodu*") # add "*" can't work 
    option(GIT_SUBMODULE "Check submodules during build" ON)
	message(STATUS "Submodule update")
	execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive 
			        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
					RESULT_VARIABLE GIT_SUBMOD_RESULT)
	if(NOT GIT_SUBMOD_RESULT EQUAL "0")
	    message(FATAL_ERROR "git submodule update --init failed, please check")
	endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/modules/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodule was not downloaded... please check")
endif()
#######################################################
add_subdirectory(modules/glfw)


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
