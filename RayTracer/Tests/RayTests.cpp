#include "pch.h"

#include "Matchers.h"
#include "RayTracer/Ray.h"

using namespace RayTracer;
const float kEpsilon = 1e-5f;

TEST(TestRay, TestConstructor)
{
    const auto origin = MakePoint(1.0f, 2.0f, 3.0f);
    const auto direction = MakeVector(4.0f, 5.0f, 6.0f);

    const auto ray = Ray(origin, direction);
    EXPECT_THAT(ray.origin(), IsSimilarToVector(origin, kEpsilon));
    EXPECT_THAT(ray.direction(), IsSimilarToVector(direction, kEpsilon));
}

TEST(TestRay, TestPosition)
{
    {
        const auto ray = Ray(MakePoint(2.0f, 3.0f, 4.0f), MakeVector(1.0f, 0.0f, 0.0f));
        EXPECT_THAT(ray.position(1.0f), IsSimilarToVector(MakePoint(3.0f, 3.0f, 4.0f), kEpsilon));
        EXPECT_THAT(ray.position(-1.0f), IsSimilarToVector(MakePoint(1.0f, 3.0f, 4.0f), kEpsilon));
        EXPECT_THAT(ray.position(2.5f), IsSimilarToVector(MakePoint(4.5f, 3.0f, 4.0f), kEpsilon));
    }

    {
        const auto ray = Ray(MakePoint(2.0f, 3.0f, 4.0f), MakeVector(3.0f, -1.0f, 2.0f));
        EXPECT_THAT(ray.position(2.0f), IsSimilarToVector(MakePoint(8.0f, 1.0f, 8.0f), kEpsilon));
    }

}