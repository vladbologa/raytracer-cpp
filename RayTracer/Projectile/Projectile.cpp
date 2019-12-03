#include <RayTracer/Canvas.h>
#include <RayTracer/Math.h>

#include <fstream>

using namespace RayTracer;

struct Projectile
{
    Eigen::Vector4f position;
    Eigen::Vector4f velocity;
};

struct Environment
{
    Eigen::Vector4f gravity;
    Eigen::Vector4f wind;
};

void tick(Projectile& proj, const Environment& env)
{
    proj.position += proj.velocity;
    proj.velocity += env.gravity + env.wind;
}

void drawProjectile(const Projectile& proj, Canvas& canvas)
{
    const int pixelX = static_cast<int>(std::round(proj.position.x()));
    const int pixelY = static_cast<int>(canvas.height()) - static_cast<int>(std::round(proj.position.y()));

    if (pixelX >= 0 && pixelX < canvas.width() && pixelY >= 0 && pixelY < canvas.height()) {
        canvas.pixelAt(pixelX, pixelY) = Color(1.0f, 0.0f, 0.0f);
    }
}

void writeCanvasToFile(const Canvas& canvas, const std::string& fileName)
{
    auto ppmStream = canvas.exportToPpm();
    std::ofstream fout("out.ppm");
    fout << ppmStream.rdbuf();
}

int main()
{
    const auto velocity = Vector(1.0f, 1.8f, 0.0f).normalized();
    Projectile proj{ Point(0.0f, 1.0f, 0.0f), 11.25 * velocity };
    const Environment env{ Vector(0.0f, -0.1f, 0.0f), Vector(-0.01f, 0.0f, 0.0f) };

    Canvas canvas(900, 550);
    while (proj.position.y() > 0.0f) {
        tick(proj, env);
        drawProjectile(proj, canvas);
    }

    writeCanvasToFile(canvas, "out.ppm");
}
