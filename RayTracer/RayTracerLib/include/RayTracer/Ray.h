#pragma once

#include "Math.h"

namespace RayTracer {

// A ray, represented by an origin point and a direction vector
class Ray {
  public:
    // Constructor
    // @param origin Origin point of the ray (origin.w() must be 1.0f)
    // @param direction Direction vector of the ray (direction.w() must be 0.0f)
    Ray(const Vector4f &origin, const Vector4f &direction)
        : origin_(origin), direction_(direction) {}

    [[nodiscard]] const Vector4f &origin() const noexcept { return origin_; }

    [[nodiscard]] const Vector4f &direction() const noexcept { return direction_; }

    // Calculates the point at a given @c distance along the ray
    [[nodiscard]] Vector4f position(float distance) const { return origin_ + direction_ * distance; }

  private:
    Vector4f origin_;
    Vector4f direction_;
};

} // namespace RayTracer
