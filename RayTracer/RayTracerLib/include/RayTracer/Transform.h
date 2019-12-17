#pragma once

#include "Math.h"

#include <Eigen/Core>

namespace RayTracer {

namespace Transform {

// Builds a 4x4 translation matrix from 3 scalars
Matrix4f Translation(float x, float y, float z);

// // Builds a 4x4 translation matrix from a vector
Matrix4f Translation(const Vector4f& v);

} // Transform

} // RayTracer
