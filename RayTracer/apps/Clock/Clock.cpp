#include <RayTracer/Canvas.h>
#include <RayTracer/Transform.h>

#include <fstream>

using namespace RayTracer;

int main()
{
    const float angleStep = EIGEN_PI / 6.0f;
    const auto firstPoint = MakePoint(0.0f, 200.0f, 0.0f);
    Canvas canvas(480, 480);
    Transformation transformation;

    for (size_t i = 0; i < 12; ++ i) {
        const auto currentPoint = transformation.matrix() * firstPoint;
        const int pixelX = (canvas.width() / 2) + static_cast<int>(std::round(currentPoint.x()));
        const int pixelY = static_cast<int>(canvas.height() / 2) - static_cast<int>(std::round(currentPoint.y()));

        canvas.pixelAt(pixelX, pixelY) = Color(1.0f, 1.0f, 1.0f);
        transformation.rotate(Axes::Z, angleStep);
    }

    WriteCanvasToFile(canvas, "clock.ppm");
}
