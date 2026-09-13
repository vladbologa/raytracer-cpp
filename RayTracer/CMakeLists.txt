cmake_minimum_required(VERSION 3.20)

project(RayTracer-cpp VERSION 0.1
                      DESCRIPTION "RayTracer experiment"
                      LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	set(CMAKE_CXX_EXTENSIONS OFF)
	set(CMAKE_CXX_STANDARD 20)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)

	set_property(GLOBAL PROPERTY USE_FOLDERS ON)

	include(CTest)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(AddEigen)
include(AddGoogleTest)

if(MSVC)
	add_compile_options(/W4 /WX)
else()
	add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

option(ENABLE_CLANG_TIDY "Enable clang-tidy static analysis during build" OFF)

if(ENABLE_CLANG_TIDY)
	find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
	if(CLANG_TIDY_EXE)
		set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
		message(STATUS "clang-tidy enabled for project targets: ${CLANG_TIDY_EXE}")
	else()
		message(WARNING "ENABLE_CLANG_TIDY is ON, but clang-tidy executable was not found.")
	endif()
endif()

add_subdirectory(RayTracerLib)
add_subdirectory(apps)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(Tests)
endif()
