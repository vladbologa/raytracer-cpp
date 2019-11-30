#pragma once

#include <Eigen/Dense>

namespace RayTracer {

template<typename TEigenArray>
class ColorMixin : public TEigenArray
{
public:
    ColorMixin()
        : TEigenArray(0.0f, 0.0f, 0.0f)
    {}
    
    ColorMixin(float red, float green, float blue)
        : TEigenArray(red, green, blue)
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

using Color = ColorMixin<Eigen::Array3f>;

}