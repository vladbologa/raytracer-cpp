#include "RayTracer/Transform.h"

#include <Eigen/Geometry>

namespace RayTracer {

namespace Transform {

Matrix4f Translate(float x, float y, float z)
{
    Eigen::Affine3f transform;
    transform = Eigen::Translation3f(x, y, z);
    return transform.matrix();
}

Matrix4f Translate(const Vector4f v)
{
    return Translate(v.x(), v.y(), v.z());
}

} // Transform

} // RayTracer