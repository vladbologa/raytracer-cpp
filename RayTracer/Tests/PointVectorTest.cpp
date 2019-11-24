#include "pch.h"

#include "../RayTracerLib/Math.h"

using namespace RayTracer;

TEST(TestMath, TestPoint) 
{
	const auto vec3d = Point(4.0f, -4.0f, 3.0f);
	EXPECT_EQ(vec3d.x(), 4.0f);
	EXPECT_EQ(vec3d.y(), -4.0f);
	EXPECT_EQ(vec3d.z(), 3.0f);
	EXPECT_EQ(vec3d.w(), 1.0f);
}

TEST(TestMath, TestVector) 
{
	const auto vec3d = Vector(4.0f, -4.0f, 3.0f);
	EXPECT_EQ(vec3d.x(), 4.0f);
	EXPECT_EQ(vec3d.y(), -4.0f);
	EXPECT_EQ(vec3d.z(), 3.0f);
	EXPECT_EQ(vec3d.w(), 0.0f);
}

TEST(TestMath, TestAddition)
{
	const auto point = Point(3.0f, -2.0f, 5.0f);
	const auto displacement = Vector(-2.0f, 3.0f, 1.0f);

	const auto displacedPoint = point + displacement;
	const auto expectedPoint = Point(1.0f, 1.0f, 6.0f);
	EXPECT_EQ(displacedPoint, expectedPoint);
}

TEST(TestMath, TestSubstractPoints)
{
	const auto p1 = Point(3.0f, 2.0f, 1.0f);
	const auto p2 = Point(5.0f, 6.0f, 7.0f);

	const auto displacement = p1 - p2;	// vector from p2 to p1
	const auto expectedDisplacement = Vector(-2.0f, -4.0f, -6.0f);
	EXPECT_EQ(displacement, expectedDisplacement);
}

TEST(TestMath, TestVectorNegation)
{
	const auto vec = Vector(1.0f, -2.0f, 3.0f);
	const auto expected = Vector(-1.0f, 2.0f, -3.0f);
	EXPECT_EQ(-vec, expected);
}