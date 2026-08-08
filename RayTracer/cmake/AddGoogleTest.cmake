include(FetchContent)

FetchContent_Declare(googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             v1.17.0
        GIT_SHALLOW         TRUE)

FetchContent_GetProperties(googletest)
FetchContent_MakeAvailable(googletest)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

set_target_properties(gtest gtest_main gmock gmock_main
    PROPERTIES FOLDER "Extern")
