#pragma once

#include <Eigen/Dense>

namespace RayTracer {

// Thin wrapper over Eigen::Array3f that adds convenience
// red(), green() and blue() functions
class Color : public Eigen::Array3f
{
public:
    Color()
        : Eigen::Array3f(0.0f, 0.0f, 0.0f)
    {}

    Color(float red, float green, float blue)
        : Eigen::Array3f(red, green, blue)
    {}

    float red() const {
        return (*this)[0];
    }

    float& red() {
        return (*this)[0];
    }

    float green() const {
        return (*this)[1];
    }

    float& green() {
        return (*this)[1];
    }

    float blue() const {
        return (*this)[2];
    }

    float& blue() {
        return (*this)[2];
    }
};

}