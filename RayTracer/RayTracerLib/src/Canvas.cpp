#include "RayTracer/Canvas.h"

#include <algorithm>

namespace RayTracer {

const size_t kMaxColorValue = 255;
const size_t kPixelsPerLine = 5;

std::stringstream Canvas::exportToPpm() const
{
    std::stringstream ppmStream;
    ppmStream 
        << "P3" << std::endl
        << std::to_string(m_width) << " " << std::to_string(m_height) << std::endl 
        << std::to_string(kMaxColorValue) << std::endl;

    size_t pixelIdx = 0;
    size_t pixelsOnCurrentLine = 0;
    for (const auto& pixel : m_canvas) {
        for (size_t i = 0; i < 3; i++) {
            size_t colorValue = static_cast<size_t>(std::round(kMaxColorValue * std::clamp(pixel[i], 0.0f, 1.0f)));
            ppmStream << std::to_string(colorValue);
            if (i < 2) {
                ppmStream << " ";
            }
        }

        ++pixelIdx;
        ++pixelsOnCurrentLine;
        if ((pixelIdx % m_width == 0) || (pixelsOnCurrentLine % kPixelsPerLine == 0)) {
            ppmStream << std::endl;
            pixelsOnCurrentLine = 0;
        }
        else {
            ppmStream << " ";
        }
    }

    ppmStream << std::endl;
    return ppmStream;
}

}
