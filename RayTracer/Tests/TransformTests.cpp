#include "pch.h"

#include "Matchers.h"
#include "RayTracer/Transform.h"
#include "RayTracer/Math.h"

using namespace RayTracer;
const float kEpsilon = 1e-5f;

TEST(TestTransform, TestTranslationScalars)
{
    {
        const auto transform = Transform::Translation(5.0f, -3.0f, 2.0f);
        const auto p = MakePoint(-3.0f, 4.0f, 5.0f);
        const auto expected = MakePoint(2.0f, 1.0f, 7.0f);

        EXPECT_THAT(transform * p, IsSimilarToVector(expected, kEpsilon));
    }

    {
        const auto transform = Transform::Translation(5.0f, -3.0f, 2.0f);
        const auto p = MakePoint(-3.0f, 4.0f, 5.0f);
        const auto expected = MakePoint(-8.0f, 7.0f, 3.0f);

        EXPECT_THAT(transform.inverse() * p, IsSimilarToVector(expected, kEpsilon));
    }

    {
        const auto transform = Transform::Translation(5.0f, -3.0f, 2.0f);
        const auto v = MakeVector(-3.0f, 4.0f, 5.0f);

        EXPECT_THAT(transform * v, IsSimilarToVector(v, kEpsilon));
    }
}

TEST(TestTransform, TestTranslationVector)
{
    {
        const auto transform = Transform::Translation(MakeVector(5.0f, -3.0f, 2.0f));
        const auto p = MakePoint(-3.0f, 4.0f, 5.0f);
        const auto expected = MakePoint(2.0f, 1.0f, 7.0f);

        EXPECT_THAT(transform * p, IsSimilarToVector(expected, kEpsilon));
    }

    {
        const auto transform = Transform::Translation(MakeVector(5.0f, -3.0f, 2.0f));
        const auto p = MakePoint(-3.0f, 4.0f, 5.0f);
        const auto expected = MakePoint(-8.0f, 7.0f, 3.0f);

        EXPECT_THAT(transform.inverse() * p, IsSimilarToVector(expected, kEpsilon));
    }

    {
        const auto transform = Transform::Translation(MakeVector(5.0f, -3.0f, 2.0f));
        const auto v = MakeVector(-3.0f, 4.0f, 5.0f);

        EXPECT_THAT(transform * v, IsSimilarToVector(v, kEpsilon));
    }
}

TEST(TestTransform, TestScalingScalars)
{
    // scaling applied to point
    {
        const auto transform = Transform::Scaling(2.0f, 3.0f, 4.0f);
        const auto p = MakePoint(-4.0f, 6.0f, 8.0f);
        const auto expected = MakePoint(-8.0f, 18.0f, 32.0f);

        EXPECT_THAT(transform * p, IsSimilarToVector(expected, kEpsilon));
    }

    // scaling applied to vector
    {
        const auto transform = Transform::Scaling(2.0f, 3.0f, 4.0f);
        const auto p = MakeVector(-4.0f, 6.0f, 8.0f);
        const auto expected = MakeVector(-8.0f, 18.0f, 32.0f);

        EXPECT_THAT(transform * p, IsSimilarToVector(expected, kEpsilon));
    }

    // scaling with inverse
    {
        const auto transform = Transform::Scaling(2.0f, 3.0f, 4.0f);
        const auto p = MakeVector(-4.0f, 6.0f, 8.0f);
        const auto expected = MakeVector(-2.0f, 2.0f, 2.0f);

        EXPECT_THAT(transform.inverse() * p, IsSimilarToVector(expected, kEpsilon));
    }

    // reflection
    {
        const auto transform = Transform::Scaling(-1.0f, 1.0f, 1.0f);
        const auto p = MakePoint(-4.0f, 6.0f, 8.0f);
        const auto expected = MakePoint(4.0f, 6.0f, 8.0f);

        EXPECT_THAT(transform * p, IsSimilarToVector(expected, kEpsilon));
    }
}

TEST(TestTransform, TestScalingVector)
{
    // scaling applied to point
    {
        const auto transform = Transform::Scaling(MakeVector(2.0f, 3.0f, 4.0f));
        const auto p = MakePoint(-4.0f, 6.0f, 8.0f);
        const auto expected = MakePoint(-8.0f, 18.0f, 32.0f);

        EXPECT_THAT(transform * p, IsSimilarToVector(expected, kEpsilon));
    }

    // scaling applied to vector
    {
        const auto transform = Transform::Scaling(MakeVector(2.0f, 3.0f, 4.0f));
        const auto p = MakeVector(-4.0f, 6.0f, 8.0f);
        const auto expected = MakeVector(-8.0f, 18.0f, 32.0f);

        EXPECT_THAT(transform * p, IsSimilarToVector(expected, kEpsilon));
    }

    // scaling with inverse
    {
        const auto transform = Transform::Scaling(MakeVector(2.0f, 3.0f, 4.0f));
        const auto p = MakeVector(-4.0f, 6.0f, 8.0f);
        const auto expected = MakeVector(-2.0f, 2.0f, 2.0f);

        EXPECT_THAT(transform.inverse() * p, IsSimilarToVector(expected, kEpsilon));
    }

    // reflection
    {
        const auto transform = Transform::Scaling(MakeVector(-1.0f, 1.0f, 1.0f));
        const auto p = MakePoint(-4.0f, 6.0f, 8.0f);
        const auto expected = MakePoint(4.0f, 6.0f, 8.0f);

        EXPECT_THAT(transform * p, IsSimilarToVector(expected, kEpsilon));
    }
}

TEST(TestTransform, TestRotateX)
{
    {
        const auto p = MakePoint(0.0f, 1.0f, 0.0f);

        const auto transform90 = Transform::Rotation(Transform::Axes::X, EIGEN_PI / 2.0f);
        const auto expected90 = MakePoint(0.0f, 0.0f, 1.0f);
        EXPECT_THAT(transform90 * p, IsSimilarToVector(expected90, kEpsilon));

        const auto transform45 = Transform::Rotation(Transform::Axes::X, EIGEN_PI / 4.0f);
        const auto expected45 = MakePoint(0.0f, sqrt(2.0f) / 2.0f, sqrt(2.0f) / 2.0f);
        EXPECT_THAT(transform45 * p, IsSimilarToVector(expected45, kEpsilon));

        const auto expectedInv45 = MakePoint(0.0f, sqrt(2.0f) / 2.0f, -sqrt(2.0f) / 2.0f);
        EXPECT_THAT(transform45.inverse() * p, IsSimilarToVector(expectedInv45, kEpsilon));
    }
}

TEST(TestTransform, TestRotateY)
{
    {
        const auto p = MakePoint(0.0f, 0.0f, 1.0f);

        const auto transform90 = Transform::Rotation(Transform::Axes::Y, EIGEN_PI / 2.0f);
        const auto expected90 = MakePoint(1.0f, 0.0f, 0.0f);
        EXPECT_THAT(transform90 * p, IsSimilarToVector(expected90, kEpsilon));

        const auto transform45 = Transform::Rotation(Transform::Axes::Y, EIGEN_PI / 4.0f);
        const auto expected45 = MakePoint(sqrt(2.0f) / 2.0f, 0.0f, sqrt(2.0f) / 2.0f);
        EXPECT_THAT(transform45 * p, IsSimilarToVector(expected45, kEpsilon));
    }
}

TEST(TestTransform, TestRotateZ)
{
    {
        const auto p = MakePoint(0.0f, 1.0f, 0.0f);

        const auto transform90 = Transform::Rotation(Transform::Axes::Z, EIGEN_PI / 2.0f);
        const auto expected90 = MakePoint(-1.0f, 0.0f, 0.0f);
        EXPECT_THAT(transform90 * p, IsSimilarToVector(expected90, kEpsilon));

        const auto transform45 = Transform::Rotation(Transform::Axes::Z, EIGEN_PI / 4.0f);
        const auto expected45 = MakePoint(-sqrt(2.0f) / 2.0f, sqrt(2.0f) / 2.0f, 0.0f);
        EXPECT_THAT(transform45 * p, IsSimilarToVector(expected45, kEpsilon));
    }
}

TEST(TestTransform, TestShearing)
{
    const auto p = MakePoint(2.0f, 3.0f, 4.0f);

    {
        const auto transform = Transform::Shearing(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        const auto expected = MakePoint(5.0f, 3.0f, 4.0f);
        EXPECT_THAT(transform * p, IsSimilarToVector(expected, kEpsilon));
    }

    {
        const auto transform = Transform::Shearing(0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        const auto expected = MakePoint(6.0f, 3.0f, 4.0f);
        EXPECT_THAT(transform * p, IsSimilarToVector(expected, kEpsilon));
    }

    {
        const auto transform = Transform::Shearing(0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
        const auto expected = MakePoint(2.0f, 5.0f, 4.0f);
        EXPECT_THAT(transform * p, IsSimilarToVector(expected, kEpsilon));
    }

    {
        const auto transform = Transform::Shearing(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
        const auto expected = MakePoint(2.0f, 7.0f, 4.0f);
        EXPECT_THAT(transform * p, IsSimilarToVector(expected, kEpsilon));
    }

    {
        const auto transform = Transform::Shearing(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        const auto expected = MakePoint(2.0f, 3.0f, 6.0f);
        EXPECT_THAT(transform * p, IsSimilarToVector(expected, kEpsilon));
    }

    {
        const auto transform = Transform::Shearing(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
        const auto expected = MakePoint(2.0f, 3.0f, 7.0f);
        EXPECT_THAT(transform * p, IsSimilarToVector(expected, kEpsilon));
    }
}
