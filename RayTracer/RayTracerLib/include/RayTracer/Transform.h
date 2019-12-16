#pragma once

#include "Math.h"

#include <Eigen/Dense>

namespace RayTracer {

namespace Transform {

// Builds a 4x4 translation matrix from 3 scalars
Eigen::Matrix4f Translate(float x, float y, float z);

// // Builds a 4x4 translation matrix from a vector
Eigen::Matrix4f Translate(const Eigen::Vector4f v);

} // Transform

} // RayTracer
