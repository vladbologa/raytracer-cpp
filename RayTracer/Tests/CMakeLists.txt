set(Tests_HEADERS
    pch.h
	Matchers.h)
set(Tests_SRCS
    main.cpp
	pch.cpp
	CanvasTests.cpp
	ColorTests.cpp
	MatcherTests.cpp
	LinearAlgebraTests.cpp
	RayTests.cpp
	TransformTests.cpp)

add_executable(TestRayTracerCpp ${Tests_HEADERS} ${Tests_SRCS})

target_link_libraries(TestRayTracerCpp 
	PRIVATE RayTracerLib gtest gmock gtest_main)

include(GoogleTest)
gtest_discover_tests(TestRayTracerCpp
                TEST_PREFIX "TestRayTracerCpp."
                PROPERTIES FOLDER "Tests")

target_compile_features(TestRayTracerCpp PUBLIC cxx_std_17)
