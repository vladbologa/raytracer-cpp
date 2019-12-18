add_executable(Projectile Projectile.cpp)
target_compile_features(Projectile PRIVATE cxx_std_17)

target_link_libraries(Projectile PRIVATE RayTracerLib)
