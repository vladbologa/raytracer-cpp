#pragma once

#include <Eigen/Dense>

namespace RayTracer {

inline Eigen::Vector4f Vector(float x, float y, float z) {
    return Eigen::Vector4f(x, y, z, 0.0f);
}

inline Eigen::Vector4f Point(float x, float y, float z) {
    return Eigen::Vector4f(x, y, z, 1.0f);
}

}