cmake_minimum_required(VERSION 3.20)

project(RayTracer-cpp VERSION 0.1
                      DESCRIPTION "RayTracer experiment"
                      LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	set(CMAKE_CXX_EXTENSIONS OFF)
	set(CMAKE_CXX_STANDARD 17)

	set_property(GLOBAL PROPERTY USE_FOLDERS ON)

	include(CTest)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(AddEigen)
include(AddGoogleTest)

add_subdirectory(RayTracerLib)
add_subdirectory(apps)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(Tests)
endif()
