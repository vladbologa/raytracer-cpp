#include <RayTracer/Canvas.h>
#include <RayTracer/Math.h>

using namespace RayTracer;

struct Projectile
{
    Vector4f position;
    Vector4f velocity;
};

struct Environment
{
    Vector4f gravity;
    Vector4f wind;
};

void Tick(Projectile& proj, const Environment& env)
{
    proj.position += proj.velocity;
    proj.velocity += env.gravity + env.wind;
}

void DrawProjectile(const Projectile& proj, Canvas& canvas)
{
    const int pixelX = static_cast<int>(std::round(proj.position.x()));
    const int pixelY = static_cast<int>(canvas.height()) - static_cast<int>(std::round(proj.position.y()));

    if (pixelX >= 0 && pixelX < canvas.width() && pixelY >= 0 && pixelY < canvas.height()) {
        canvas.pixelAt(pixelX, pixelY) = Color(1.0f, 0.0f, 0.0f);
    }
}

int main()
{
    const auto velocity = MakeVector(1.0f, 1.8f, 0.0f).normalized();
    Projectile proj{ MakePoint(0.0f, 1.0f, 0.0f), 11.25 * velocity };
    const Environment env{ MakeVector(0.0f, -0.1f, 0.0f), MakeVector(-0.01f, 0.0f, 0.0f) };

    Canvas canvas(900, 550);
    while (proj.position.y() > 0.0f) {
        Tick(proj, env);
        DrawProjectile(proj, canvas);
    }

    WriteCanvasToFile(canvas, "projectile.ppm");
}
