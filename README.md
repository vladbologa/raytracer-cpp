# raytracer-cpp

Building a ray tracer in C++, following "The Ray Tracer Challenge" by Jamis Buck

## Dependencies

- CMake 3.20+
- A C++17 compiler (GCC, Clang, or MSVC)
- Eigen 5.0 and GoogleTest 1.17 are fetched automatically at configure time

## Build

```bash
cmake -S RayTracer -B RayTracer/build -DCMAKE_BUILD_TYPE=Debug
cmake --build RayTracer/build
ctest --test-dir RayTracer/build --output-on-failure
```

On Windows with MinGW (no Visual Studio required):

```powershell
cmake -S RayTracer -B RayTracer/build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug
cmake --build RayTracer/build
ctest --test-dir RayTracer/build --output-on-failure
```