include(FetchContent)

FetchContent_Declare(
    Eigen3
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG        5.0.1
    GIT_SHALLOW    TRUE)

FetchContent_GetProperties(Eigen3)
if(NOT eigen3_POPULATED)
    FetchContent_Populate(Eigen3)

    add_library(Eigen3_Eigen INTERFACE)
    target_include_directories(Eigen3_Eigen SYSTEM INTERFACE "${eigen3_SOURCE_DIR}")
    add_library(Eigen3::Eigen ALIAS Eigen3_Eigen)
endif()
