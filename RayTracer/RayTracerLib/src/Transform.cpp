#include "RayTracer/Transform.h"

#include <Eigen/Geometry>

namespace RayTracer {

namespace Transform {

Matrix4f Translation(float x, float y, float z)
{
    Eigen::Affine3f transform;
    transform = Eigen::Translation3f(x, y, z);
    return transform.matrix();
}

Matrix4f Translation(const Vector4f& v)
{
    return Translation(v.x(), v.y(), v.z());
}

} // Transform

} // RayTracer
