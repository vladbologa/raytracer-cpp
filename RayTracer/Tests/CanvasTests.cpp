#include "pch.h"

#include "Matchers.h"
#include "RayTracer/Canvas.h"

#include <type_traits>

using namespace RayTracer;

const float kEpsilon = 1e-5f;

static_assert(std::is_nothrow_move_constructible_v<Canvas>);
static_assert(std::is_nothrow_move_assignable_v<Canvas>);

TEST(TestCanvas, TestDefaultConstructor)
{
    const size_t width = 1920;
    const size_t height = 1080;
    const Canvas canvas(width, height);
    const auto expectedColor = Color(0.0f, 0.0f, 0.0f);

    EXPECT_EQ(canvas.height(), height);
    EXPECT_EQ(canvas.width(), width);

    for (size_t i = 0; i < width; i++) {
        for (size_t j = 0; j < height; j++) {
            EXPECT_THAT(canvas.pixelAt(i, j), IsSimilarToVector(expectedColor, kEpsilon));
        }
    }
}

TEST(TestCanvas, TestSetter)
{
    const size_t width = 30;
    const size_t height = 40;
    Canvas canvas(width, height);

    const auto& pixelColor = canvas.pixelAt(2, 3);
    EXPECT_THAT(pixelColor, IsSimilarToVector(Color(0.0f, 0.0f, 0.0f), kEpsilon));
    canvas.pixelAt(2, 3) = Color(0.2f, 0.3f, 0.4f);
    EXPECT_THAT(pixelColor, IsSimilarToVector(Color(0.2f, 0.3f, 0.4f), kEpsilon));
}

#ifndef NDEBUG
TEST(TestCanvasDeathTest, TestOutOfBounds)
{
    const size_t width = 30;
    const size_t height = 40;
    {
        Canvas canvas(width, height);
        EXPECT_EXIT(canvas.pixelAt(width, 0) = Color(), ::testing::ExitedWithCode(3), "Assertion failed");
        EXPECT_EXIT(canvas.pixelAt(0, height) = Color(), ::testing::ExitedWithCode(3), "Assertion failed");
    }

    {
        const Canvas canvas(width, height);
        EXPECT_EXIT(canvas.pixelAt(width, 0), ::testing::ExitedWithCode(3), "Assertion failed");
        EXPECT_EXIT(canvas.pixelAt(0, height), ::testing::ExitedWithCode(3), "Assertion failed");
    }
}
#endif // NDEBUG