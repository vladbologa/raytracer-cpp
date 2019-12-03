#pragma once

#include "Color.h"

#include <cassert>
#include <vector>
#include <string>
#include <sstream>

namespace RayTracer {

// A rectangular grid of pixels
class Canvas
{
public:
    Canvas(size_t width, size_t height)
        : m_width(width), m_height(height), m_canvas(m_width* m_height)
    {}

    Canvas(Canvas& other) = default;
    Canvas& operator=(Canvas& other) = default;

    Canvas(Canvas&& other) noexcept = default;
    Canvas& operator=(Canvas&& other) noexcept = default;

    Color& pixelAt(size_t x, size_t y) noexcept
    {
        return const_cast<Color&>(const_cast<const Canvas*>(this)->pixelAt(x, y));
    }

    const Color& pixelAt(size_t x, size_t y) const noexcept
    {
        assert(x < m_width); assert(y < m_height);
        return m_canvas[x + y * m_width];
    }

    size_t width() const noexcept
    {
        return m_width;
    }

    size_t height() const noexcept
    {
        return m_height;
    }

    std::stringstream exportToPpm() const;

private:
    size_t m_width;
    size_t m_height;
    std::vector<Color> m_canvas;
};

}