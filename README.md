# raytracer-cpp

Building a ray tracer in C++, following "The Ray Tracer Challenge" by Jamis Buck

## Dependencies

- CMake 3.20+
- A C++20 compiler (GCC, Clang, or MSVC)
- Eigen 5.0 and GoogleTest 1.17 are fetched automatically at configure time

Run these commands from the repository root.

## Build with GCC or Clang

```bash
cmake -S RayTracer -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

## Build with Visual Studio

```powershell
cmake -S RayTracer -B build-msvc -G "Visual Studio 17 2022" -A x64
cmake --build build-msvc --config Debug --parallel
ctest --test-dir build-msvc -C Debug --output-on-failure
```