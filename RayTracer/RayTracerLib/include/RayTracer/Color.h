#pragma once

#include <Eigen/Dense>

namespace RayTracer {

template<typename TEigenArray>
class ColorMixin : public TEigenArray
{
public:
	ColorMixin(float red, float green, float blue)
		: TEigenArray(red, green, blue)
	{}

	float red() const {
		return (*this)[0];
	}

	float green() const {
		return (*this)[1];
	}

	float blue() const {
		return (*this)[2];
	}
};

using Color = ColorMixin<Eigen::Array3f>;

}