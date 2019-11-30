#include "pch.h"

#include "Matchers.h"
#include "RayTracer/Color.h"

using namespace RayTracer;

const float kEpsilon = 1e-5f;

TEST(TestColor, TestConstructor)
{
	const auto color = Color(0.5f, 0.4f, 0.3f);
	EXPECT_EQ(color.red(), 0.5f);
	EXPECT_EQ(color.green(), 0.4f);
	EXPECT_EQ(color.blue(), 0.3f);
}

TEST(TestColor, TestAddition)
{
	const auto c1 = Color(0.9f, 0.6f, 0.75f);
	const auto c2 = Color(0.7f, 0.1f, 0.25f);
	const auto expected = Color(1.6f, 0.7f, 1.0f);

	EXPECT_THAT(c1 + c2, IsSimilarToVector(expected, kEpsilon));
}

TEST(TestColor, TestSubtraction)
{
	const auto c1 = Color(0.9f, 0.6f, 0.75f);
	const auto c2 = Color(0.7f, 0.1f, 0.25f);
	const auto expected = Color(0.2f, 0.5f, 0.5f);

	EXPECT_THAT(c1 - c2, IsSimilarToVector(expected, kEpsilon));
}

TEST(TestColor, TestScalarMultiplication)
{
	const auto color = Color(0.2f, 0.3f, 0.4f);
	const auto expected = Color(0.4f, 0.6f, 0.8f);

	EXPECT_THAT(color * 2, IsSimilarToVector(expected, kEpsilon));
}

TEST(TestColor, TestMultiplication)
{
	const auto c1 = Color(1.0f, 0.2f, 0.4f);
	const auto c2 = Color(0.9f, 1.0f, 0.1f);
	const auto expected = Color(0.9f, 0.2f, 0.04f);

	EXPECT_THAT(c1 * c2, IsSimilarToVector(expected, kEpsilon));
}
