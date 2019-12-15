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

TEST(TestMatchers, TestIsSimilarMatrix)
{
    {
        const auto m1 = Eigen::Matrix4f::Random();
        const auto m2 = Eigen::Matrix4f::Identity();
        EXPECT_THAT(m1, Not(IsSimilarToMatrix(m2, kEpsilon)));
    }

    {
        const auto m1 = Eigen::Matrix4f::Identity();
        const auto m2 = Eigen::Matrix4f::Identity();
        EXPECT_THAT(m1, IsSimilarToMatrix(m2, kEpsilon));
    }

    {
        const auto m1 = Eigen::Matrix4f::Identity();
        const auto m2 = Eigen::Matrix3f::Identity();
        EXPECT_THAT(m1, Not(IsSimilarToMatrix(m2, kEpsilon)));
    }

    {
        Eigen::Matrix3f m1;
        m1 << 1.0f, 2.0f, 3.0f,
            4.0f, 5.0f, 6.0f,
            7.0f, 8.0f, 9.0f;

        Eigen::Matrix3f m2;
        m2 << 1.0f, 2.0f, 3.0f,
            4.0f, 5.0f, 6.0f,
            7.0f, 8.0f, 1.0f;

        EXPECT_THAT(m1, Not(IsSimilarToMatrix(m2, kEpsilon)));
    }
}
