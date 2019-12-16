#include "RayTracer/Transform.h"

namespace RayTracer {

namespace Transform {

Eigen::Matrix4f Translate(float x, float y, float z)
{
    Eigen::Matrix4f translateMatrix = Eigen::Matrix4f::Identity();
    translateMatrix(0, 3) = x;
    translateMatrix(1, 3) = y;
    translateMatrix(2, 3) = z;

    return translateMatrix;
}

Eigen::Matrix4f Translate(const Eigen::Vector4f v)
{
    return Translate(v.x(), v.y(), v.z());
}

} // Transform

} // RayTracer
