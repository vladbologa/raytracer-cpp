#include "pch.h"

#include "Matchers.h"
#include "RayTracer/Math.h"

using namespace RayTracer;
const float kEpsilon = 1e-5f;

TEST(TestMath, TestPoint)
{
    const auto vec3d = MakePoint(4.0f, -4.0f, 3.0f);
    EXPECT_EQ(vec3d.x(), 4.0f);
    EXPECT_EQ(vec3d.y(), -4.0f);
    EXPECT_EQ(vec3d.z(), 3.0f);
    EXPECT_EQ(vec3d.w(), 1.0f);
}

TEST(TestMath, TestVector)
{
    const auto vec3d = MakeVector(4.0f, -4.0f, 3.0f);
    EXPECT_EQ(vec3d.x(), 4.0f);
    EXPECT_EQ(vec3d.y(), -4.0f);
    EXPECT_EQ(vec3d.z(), 3.0f);
    EXPECT_EQ(vec3d.w(), 0.0f);
}

TEST(TestMath, TestAddition)
{
    const auto point = MakePoint(3.0f, -2.0f, 5.0f);
    const auto displacement = MakeVector(-2.0f, 3.0f, 1.0f);

    const auto displacedPoint = point + displacement;
    const auto expectedPoint = MakePoint(1.0f, 1.0f, 6.0f);
    EXPECT_EQ(displacedPoint, expectedPoint);
}

TEST(TestMath, TestSubstractPoints)
{
    const auto p1 = MakePoint(3.0f, 2.0f, 1.0f);
    const auto p2 = MakePoint(5.0f, 6.0f, 7.0f);

    const auto displacement = p1 - p2;	// vector from p2 to p1
    const auto expectedDisplacement = MakeVector(-2.0f, -4.0f, -6.0f);
    EXPECT_EQ(displacement, expectedDisplacement);
}

TEST(TestMath, TestVectorNegation)
{
    const auto vec = MakeVector(1.0f, -2.0f, 3.0f);
    const auto expected = MakeVector(-1.0f, 2.0f, -3.0f);
    EXPECT_EQ(-vec, expected);
}

TEST(TestMath, TestMagnitude)
{
    const auto vec1 = MakeVector(0.0f, 0.0f, 1.0f);
    EXPECT_NEAR(vec1.norm(), 1.0f, kEpsilon);

    const auto vec2 = MakeVector(-1.0f, -2.0f, -3.0f);
    EXPECT_NEAR(vec2.norm(), sqrt(14), kEpsilon);
    EXPECT_NEAR(vec2.normalized().norm(), 1.0f, kEpsilon);
}

TEST(TestMath, TestDotProduct)
{
    const auto a = MakeVector(1.0f, 2.0f, 3.0f);
    const auto b = MakeVector(2.0f, 3.0f, 4.0f);
    EXPECT_NEAR(a.dot(b), 20.0f, kEpsilon);
}

TEST(TestMath, TestCrossProduct)
{
    const auto a = MakeVector(1.0f, 2.0f, 3.0f);
    const auto b = MakeVector(2.0f, 3.0f, 4.0f);

    const auto cross1 = a.cross3(b);
    const auto cross2 = b.cross3(a);
    EXPECT_THAT(cross1, IsSimilarToVector(-cross2, kEpsilon));

    const auto expected = MakeVector(-1.0f, 2.0f, -1.0f);
    EXPECT_THAT(cross1, IsSimilarToVector(expected, kEpsilon));
}

TEST(TestMath, TestMatrixMultiplication)
{
    Matrix4f m1;
    m1 << 1.0f, 2.0f, 3.0f, 4.0f,
        5.0f, 6.0f, 7.0f, 8.0f,
        9.0f, 8.0f, 7.0f, 6.0f,
        5.0f, 4.0f, 3.0f, 2.0f;

    Matrix4f m2;
    m2 << -2.0f, 1.0f, 2.0f, 3.0f,
        3.0f, 2.0f, 1.0f, -1.0f,
        4.0f, 3.0f, 6.0f, 5.0f,
        1.0f, 2.0f, 7.0f, 8.0f;

    Matrix4f expected;
    expected << 20.0f, 22.0f, 50.0f, 48.0f,
        44.0f, 54.0f, 114.0f, 108.0f,
        40.0f, 58.0f, 110.0f, 102.0f,
        16.0f, 26.0f, 46.0f, 42.0f;

    EXPECT_THAT(m1 * m2, IsSimilarToMatrix(expected, kEpsilon));
    EXPECT_THAT(m1 * Eigen::Matrix4f::Identity(), IsSimilarToMatrix(m1, kEpsilon));
}

TEST(TestMath, TestVectorMatrixMultiplication)
{
    Matrix4f mat;
    mat << 1.0f, 2.0f, 3.0f, 4.0f,
        2.0f, 4.0f, 4.0f, 2.0f,
        8.0f, 6.0f, 4.0f, 1.0f,
        0.0f, 0.0f, 0.0f, 1.0f;

    const auto point = MakePoint(1.0f, 2.0f, 3.0f);
    const auto expected = MakePoint(18.0f, 24.0f, 33.0f);

    EXPECT_THAT(mat * point, IsSimilarToVector(expected, kEpsilon));
}

TEST(TestMath, TestTranspose)
{
    Matrix4f mat;
    mat << 1.0f, 2.0f, 3.0f, 4.0f,
        2.0f, 4.0f, 4.0f, 2.0f,
        8.0f, 6.0f, 4.0f, 1.0f,
        0.0f, 0.0f, 0.0f, 1.0f;

    Matrix4f transpose;
    transpose << 1.0f, 2.0f, 8.0f, 0.0f,
        2.0f, 4.0f, 6.0f, 0.0f,
        3.0f, 4.0f, 4.0f, 0.0f,
        4.0f, 2.0f, 1.0f, 1.0f;

    EXPECT_THAT(mat.transpose(), IsSimilarToMatrix(transpose, kEpsilon));
    mat.transposeInPlace();
    EXPECT_THAT(mat, IsSimilarToMatrix(transpose, kEpsilon));
}

TEST(TestMath, TestInverse)
{
    {
        Matrix4f mat;
        mat << -4.0f, 2.0f, -2.0f, -3.0f,
            9.0f, 6.0f, 2.0f, 6.0f,
            0.0f, -5.0f, 1.0f, -5.0f,
            0.0f, 0.0f, 0.0f, 0.0f;

        Matrix4f result;
        bool invertible;
        mat.computeInverseWithCheck(result, invertible, kEpsilon);
        EXPECT_FALSE(invertible);
    }

    {
        Matrix4f mat;
        mat << 6.0f, 4.0f, 4.0f, 4.0f,
            5.0f, 5.0f, 7.0f, 6.0f,
            4.0f, -9.0f, 3.0f, -7.0f,
            9.0f, 1.0f, 7.0f, -6.0f;

        Matrix4f result;
        bool invertible;
        float determinant;
        mat.computeInverseAndDetWithCheck(result, determinant, invertible, kEpsilon);
        EXPECT_NEAR(determinant, -2120.0f, kEpsilon);
        EXPECT_TRUE(invertible);
    }

    {
        Matrix4f a;
        a << 3.0f, -9.0f, 7.0f, 3.0f,
            3.0f, -8.0f, 2.0f, -9.0f,
            -4.0f, 4.0f, 4.0f, 1.0f,
            -6.0f, 5.0f, -1.0f, 1.0f;

        Matrix4f b;
        b << 8.0f, 2.0f, 2.0f, 2.0f,
            3.0f, -1.0f, 7.0f, 0.0f,
            7.0f, 0.0f, 5.0f, 4.0f,
            6.0f, -2.0f, 0.0f, 5.0f;

        const auto c = a * b;

        EXPECT_THAT(c * b.inverse(), IsSimilarToMatrix(a, kEpsilon));
    }
}
