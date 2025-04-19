# Embedded C++ for ADAS ML – Starter Pack

This package contains essential C++ examples for deploying machine learning on embedded systems (ADAS, Snapdragon SoCs, etc.). Here's a guide to help you get started:

---

## 1. ONNX Model Loader (`onnx_loader.cpp`)

**Purpose:** Load and run an ONNX model using the ONNX Runtime C++ API.

### How to Use:
1. Install [ONNX Runtime](https://onnxruntime.ai/docs/build/eps.html#c-and-c).
2. Compile:
    ```bash
    g++ onnx_loader.cpp -o onnx_loader -lonnxruntime
    ```
3. Run (make sure a `model.onnx` file exists in the same directory):
    ```bash
    ./onnx_loader
    ```

### Learn More:
- ONNX Runtime C++ API: https://onnxruntime.ai/docs/api/c/
- Sample ONNX models: https://github.com/onnx/models

---

## 2. Thread Scheduling on QNX/Linux (`thread_scheduling.cpp`)

**Purpose:** Demonstrates real-time thread execution using POSIX `pthread`.

### How to Use:
```bash
g++ thread_scheduling.cpp -o thread_demo -pthread
./thread_demo
```

### Key Concepts:
- Multi-threading in embedded systems
- POSIX APIs work across Linux, QNX, and embedded RTOS

### Learn More:
- POSIX Threads: https://man7.org/linux/man-pages/man7/pthreads.7.html

---

## 3. Embedded C++ Idioms (`cpp_embedded_cheatsheet.cpp`)

**Purpose:** Reference for modern C++ techniques used in embedded environments.

### Topics Covered:
- Smart pointers (RAII)
- Const correctness
- Templates
- Inline functions

### Learn More:
- C++ Smart Pointers: https://en.cppreference.com/w/cpp/memory
- C++ Guidelines for Embedded: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines

---

## Recommended Next Steps

- Learn CMake: https://cmake.org/cmake/help/latest/guide/tutorial/index.html
- Practice with OpenCV in C++: https://docs.opencv.org/master/d9/df8/tutorial_root.html
- Understand Real-Time Systems: https://www.freertos.org/
- Dive into QNX Development: https://www.qnx.com/developers/docs/

---

Feel free to expand this with:
- OpenCV preprocessing for camera frames
- TensorRT deployment
- Memory usage profiling (Valgrind, gprof)