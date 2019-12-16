set(RayTracerCpp_HEADERS 
	include/RayTracer/Canvas.h
	include/RayTracer/Color.h
	include/RayTracer/Math.h
	include/RayTracer/Transform.h)
set(RayTracerCpp_SRCS
	src/Canvas.cpp
	src/Transform.cpp)

add_library(RayTracerLib ${RayTracerCpp_SRCS} ${RayTracerCpp_HEADERS})

target_include_directories(RayTracerLib PUBLIC include)

target_link_libraries(RayTracerLib PUBLIC Eigen3::Eigen)

target_compile_features(RayTracerLib PUBLIC cxx_std_17)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/include/RayTracer"
    PREFIX "Header Files"
    FILES ${RayTracerCpp_HEADERS})
