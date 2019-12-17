#pragma once

#include "Math.h"

#include <Eigen/Core>

namespace RayTracer {

namespace Transform {

enum class Axes {
    X,
    Y,
    Z
};

// Builds a 4x4 translation matrix from 3 scalars
Matrix4f Translation(float x, float y, float z);

// // Builds a 4x4 translation matrix from a vector
Matrix4f Translation(const Vector4f& v);

// Builds a 4x4 scaling matrix from 3 scalars
Matrix4f Scaling(float x, float y, float z);

// // Builds a 4x4 scaling matrix from a vector
Matrix4f Scaling(const Vector4f& v);

// Builds a 4x4 rotation matrix, rotating along the given axis
Matrix4f Rotation(Axes axis, float angle);

} // Transform

} // RayTracer
