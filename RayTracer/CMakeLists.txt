cmake_minimum_required(VERSION 3.15)

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
include(AddGoogleTest)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_subdirectory(RayTracerLib)
add_subdirectory(Projectile)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(Tests)
endif()


