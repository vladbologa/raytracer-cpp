add_executable(Clock Clock.cpp)
target_compile_features(Clock PRIVATE cxx_std_17)

target_link_libraries(Clock PRIVATE RayTracerLib)
