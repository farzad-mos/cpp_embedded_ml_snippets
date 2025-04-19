# Embedded Linux (Yocto) for ML Engineers

## Goal
Understand how to build and use a custom Linux OS image (via Yocto Project) for ML/ADAS embedded development.

---

## What is Yocto?
Yocto is a set of tools for creating custom Linux distributions for embedded devices.

- Highly configurable (add only what you need)
- Supports cross-compilation for ARM platforms like Snapdragon
- Used in automotive ECUs and smart devices

---

## Basic Concepts

### 1. Layers
Layers are modular collections of recipes (software build instructions).

- meta-openembedded: extra utilities and packages
- meta-ml: includes TensorFlow Lite, ONNX, etc.

### 2. Recipes
BitBake scripts (with `.bb` or `.bbappend` extensions) to build packages.

Example:
```bash
bitbake core-image-minimal
```

### 3. Machine Configuration
Defines your hardware target (e.g. `qemuarm64`, `snapdragon-armv8`).

---

## Step-by-step: Build a Minimal Image

```bash
git clone git://git.yoctoproject.org/poky
cd poky
source oe-init-build-env
bitbake core-image-minimal
```

This will build a minimal Linux image for your target board.

---

## Integrating ML Inference

Add the meta-ml layer:
```bash
git clone https://github.com/ros/meta-ml.git ../meta-ml
bitbake tensorflow-lite
bitbake onnxruntime
```

Deploy the built image to your board using SD card or USB.

---

## Debugging & Tools
- `bitbake -e <recipe>` → environment variables
- `devtool` → modify recipes and rebuild quickly
- Add GDB, strace, htop to your image

```bash
IMAGE_INSTALL_append = " gdb strace htop"
```

---

## Resources
- [Yocto Project Documentation](https://docs.yoctoproject.org)
- [meta-ml layer](https://github.com/ros/meta-ml)