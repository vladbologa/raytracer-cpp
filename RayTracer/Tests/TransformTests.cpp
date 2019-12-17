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
        const auto p = Point(-3.0f, 4.0f, 5.0f);
        const auto expected = Point(2.0f, 1.0f, 7.0f);

        EXPECT_THAT(transform * p, IsSimilarToVector(expected, kEpsilon));
    }

    {
        const auto transform = Transform::Translation(5.0f, -3.0f, 2.0f);
        const auto p = Point(-3.0f, 4.0f, 5.0f);
        const auto expected = Point(-8.0f, 7.0f, 3.0f);

        EXPECT_THAT(transform.inverse() * p, IsSimilarToVector(expected, kEpsilon));
    }

    {
        const auto transform = Transform::Translation(5.0f, -3.0f, 2.0f);
        const auto v = Vector(-3.0f, 4.0f, 5.0f);

        EXPECT_THAT(transform * v, IsSimilarToVector(v, kEpsilon));
    }
}

TEST(TestTransform, TestTranslationVector)
{
    {
        const auto transform = Transform::Translation(Vector(5.0f, -3.0f, 2.0f));
        const auto p = Point(-3.0f, 4.0f, 5.0f);
        const auto expected = Point(2.0f, 1.0f, 7.0f);

        EXPECT_THAT(transform * p, IsSimilarToVector(expected, kEpsilon));
    }

    {
        const auto transform = Transform::Translation(Vector(5.0f, -3.0f, 2.0f));
        const auto p = Point(-3.0f, 4.0f, 5.0f);
        const auto expected = Point(-8.0f, 7.0f, 3.0f);

        EXPECT_THAT(transform.inverse() * p, IsSimilarToVector(expected, kEpsilon));
    }

    {
        const auto transform = Transform::Translation(Vector(5.0f, -3.0f, 2.0f));
        const auto v = Vector(-3.0f, 4.0f, 5.0f);

        EXPECT_THAT(transform * v, IsSimilarToVector(v, kEpsilon));
    }
}
