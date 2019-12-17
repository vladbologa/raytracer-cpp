#pragma once

#include <Eigen/Core>

namespace RayTracer {

using Vector3f = Eigen::Vector3f;
using Vector4f = Eigen::Vector4f;
using Matrix4f = Eigen::Matrix4f;

// Note: Seems that Eigen uses Vector3f to represent both 3D points and vectors,
// so you have to know what your object actually represents. E.g. when applying
// transformations, you'd use t.linear() * vec for vectors, and t * p for points.
// Instead, I will use Vector4f, where the w coefficient determines whether it's
// a point (w = 1) or a vector (w = 0), and I'll use Eigen::Matrix4f to store
// transformations instead of Eigen::Transform. This way a transformation
// t * v will do the right thing regardless of v being a vector or a point.

// returns a 3D vector (w coeff is 0)
inline Vector4f Vector(float x, float y, float z) {
    return Vector4f(x, y, z, 0.0f);
}

// returns a 3D point in homogenous coordinates (w coeff is 1)
inline Vector4f Point(float x, float y, float z) {
    return Vector4f(x, y, z, 1.0f);
}

}
