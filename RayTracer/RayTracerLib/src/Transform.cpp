#include "RayTracer/Transform.h"

#include <Eigen/Geometry>

namespace {
using RayTracer::Transform::Axes;

Eigen::Vector3f getAxisVector(Axes axis)
{
    switch (axis)
    {
    case Axes::X:
        return Eigen::Vector3f::UnitX();
    case Axes::Y:
        return Eigen::Vector3f::UnitY();
    case Axes::Z:
        return Eigen::Vector3f::UnitZ();
    }

    return Eigen::Vector3f::Zero();
}
}

namespace RayTracer {

namespace Transform {

Matrix4f Translation(float x, float y, float z)
{
    Eigen::Affine3f transform{ Eigen::Translation3f(x, y, z) };
    return transform.matrix();
}

Matrix4f Translation(const Vector4f& v)
{
    return Translation(v.x(), v.y(), v.z());
}

Matrix4f Scaling(float x, float y, float z)
{
    Eigen::Affine3f transform{ Eigen::Scaling(x, y, z) };
    return transform.matrix();
}

Matrix4f Scaling(const Vector4f& v)
{
    return Scaling(v.x(), v.y(), v.z());
}

Matrix4f Rotation(Axes axis, float angle)
{
    Eigen::Affine3f transform{ Eigen::AngleAxisf(angle, getAxisVector(axis)) };
    return transform.matrix();
}

Matrix4f Shearing(float xy, float xz, float yx, float yz, float zx, float zy)
{
    Matrix4f transformationMatrix = Matrix4f::Identity();
    transformationMatrix(0, 1) = xy;
    transformationMatrix(0, 2) = xz;
    transformationMatrix(1, 0) = yx;
    transformationMatrix(1, 2) = yz;
    transformationMatrix(2, 0) = zx;
    transformationMatrix(2, 1) = zy;

    return transformationMatrix;
}

} // Transform

} // RayTracer
