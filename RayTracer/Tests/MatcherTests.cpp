#include "pch.h"

#include "Matchers.h"

const float kEpsilon = 1e-5f;
using namespace testing;

TEST(TestMatchers, TestIsSimilarVector)
{
	{
		const Eigen::Vector3f v1{ 1.0f, 2.0f, 3.0f };
		const Eigen::Vector3f v2{ 1.0f, 2.0f, 3.0f };
		EXPECT_THAT(v1, IsSimilarToVector(v2, kEpsilon));
	}

	{
		const Eigen::Vector3f v1{ 1.0f, 2.0f, 3.0f };
		const Eigen::RowVector3f v2{ 1.0f, 2.0f, 3.0f };
		EXPECT_THAT(v1, IsSimilarToVector(v2, kEpsilon));
	}

	{
		const Eigen::Vector3f v1{ 1.0f, 2.0f, 3.0f };
		const Eigen::Vector4f v2{ 1.0f, 2.0f, 3.0f, 0.0f };
		EXPECT_THAT(v1, Not(IsSimilarToVector(v2, kEpsilon)));
	}

	{
		const Eigen::Vector4f v1{ 1.0f, 2.0f, 3.0f, 1.0f };
		const Eigen::Vector4f v2{ 1.0f, 2.0f, 3.0f, 0.0f };
		EXPECT_THAT(v1, Not(IsSimilarToVector(v2, kEpsilon)));
	}
}