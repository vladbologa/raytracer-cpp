#pragma once

#include <Eigen/Core>

namespace RayTracer {

// Thin wrapper over Eigen::Array3f that adds convenience
// red(), green() and blue() functions
class Color : public Eigen::Array3f {
  public:
    Color() : Eigen::Array3f(0.0f, 0.0f, 0.0f) {}

    Color(float red, float green, float blue) : Eigen::Array3f(red, green, blue) {}

    [[nodiscard]] float red() const noexcept { return (*this)[0]; }

    [[nodiscard]] float &red() noexcept { return (*this)[0]; }

    [[nodiscard]] float green() const noexcept { return (*this)[1]; }

    [[nodiscard]] float &green() noexcept { return (*this)[1]; }

    [[nodiscard]] float blue() const noexcept { return (*this)[2]; }

    [[nodiscard]] float &blue() noexcept { return (*this)[2]; }
};

} // namespace RayTracer
