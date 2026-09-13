#pragma once

#include "Color.h"

#include <cassert>
#include <sstream>
#include <string>
#include <vector>

namespace RayTracer {

// A rectangular grid of pixels
class Canvas {
  public:
    Canvas(size_t width, size_t height)
        : width_(width), height_(height), canvas_(width_ * height_) {}

    Canvas(const Canvas &other) = delete;
    Canvas &operator=(const Canvas &other) = delete;

    Canvas(Canvas &&other) noexcept = default;
    Canvas &operator=(Canvas &&other) noexcept = default;

    Color &pixelAt(size_t x, size_t y) noexcept {
        return const_cast<Color &>(const_cast<const Canvas *>(this)->pixelAt(x, y));
    }

    const Color &pixelAt(size_t x, size_t y) const noexcept {
        assert(x < width_);
        assert(y < height_);
        return canvas_[x + y * width_];
    }

    size_t width() const noexcept { return width_; }

    size_t height() const noexcept { return height_; }

    Canvas clone() const {
        Canvas copy(width_, height_);
        copy.canvas_ = canvas_;
        return copy;
    }

    std::stringstream exportToPpm() const;

  private:
    size_t width_;
    size_t height_;
    std::vector<Color> canvas_;
};

void WriteCanvasToFile(const Canvas &canvas, const std::string &fileName);

} // namespace RayTracer
