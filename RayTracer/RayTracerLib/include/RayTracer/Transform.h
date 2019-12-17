#pragma once

#include "Math.h"

#include <Eigen/Core>

namespace RayTracer {

enum class Axes {
    X,
    Y,
    Z
};

// Stores a transformation matrix
//
// Initially stores the identity matrix. Transformations can be
// subsequently applied to it, using the provided member functions.
//
// Provides a fluent API, that allows the transformations to be
// declared in their natural order (as opposed to them being
// in reverse order, as when multiplying several transformation
// matrices to a point).
class Transformation
{
public:
    // get an identity transformation
    static Transformation IdentityTransformation();

    // get the transformation matrix
    const Matrix4f& matrix() const;

    // apply translation to the existing transformation
    Transformation& translate(float x, float y, float z);

    // apply translation to the existing transformation
    Transformation& translate(const Vector4f& v);

    // apply scaling to the existing transformation
    Transformation& scale(float x, float y, float z);

    // apply rotation to the existing transformation
    Transformation& rotate(Axes axis, float angle);

    // apply shearing to the existing transformation
    Transformation& shear(float xy, float xz, float yx, float yz, float zx, float zy);

private:
    Matrix4f matrix_ = Matrix4f::Identity();;
};

namespace Transform {

// Builds a 4x4 translation matrix from 3 scalars
Matrix4f Translation(float x, float y, float z);

// Builds a 4x4 translation matrix from a vector
Matrix4f Translation(const Vector4f& v);

// Builds a 4x4 scaling matrix from 3 scalars
Matrix4f Scaling(float x, float y, float z);

// Builds a 4x4 rotation matrix, rotating along the given axis
Matrix4f Rotation(Axes axis, float angle);

// Builds a 4x4 shearing matrix
Matrix4f Shearing(float xy, float xz, float yx, float yz, float zx, float zy);

} // Transform

} // RayTracer
