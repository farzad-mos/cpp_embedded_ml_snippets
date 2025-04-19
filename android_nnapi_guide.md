# Android Automotive + NNAPI for Inference

## Goal
Run optimized ML models on Android Automotive OS using NNAPI and ML accelerators.

---

## Architecture Overview

1. **App Layer** → Your ML app (Java/Kotlin)
2. **NNAPI HAL** → Hardware Abstraction Layer
3. **Drivers / DSP** → Snapdragon Neural Processor, GPU, etc.

---

## Android NNAPI (Neural Networks API)

```java
NeuralNetworksCompilation.createForDevice(model, device);
NeuralNetworksExecution.compute();
```

- Executes on DSP if supported (e.g. Hexagon, Adreno)
- Use `TFLite Delegate` to target NNAPI backend

---

## Example with TensorFlow Lite

1. Add TFLite dependency:

```gradle
implementation 'org.tensorflow:tensorflow-lite:2.11.0'
```

2. Load model and enable NNAPI

```java
Interpreter.Options options = new Interpreter.Options();
options.setUseNNAPI(true);
Interpreter interpreter = new Interpreter(modelBuffer, options);
```

3. Run Inference

```java
float[][] input = new float[1][INPUT_SIZE];
float[][] output = new float[1][OUTPUT_SIZE];
interpreter.run(input, output);
```

---

## Debugging & Optimization

- Use `adb shell dumpsys nnapi` to check device and driver support
- Enable verbose logs: `setprop debug.nn.vlog 1`
- Convert model to TFLite using Python converter

---

## Resources

- [NNAPI Overview](https://developer.android.com/ndk/guides/neuralnetworks)
- [TFLite + NNAPI](https://www.tensorflow.org/lite/performance/nnapi)
- [AAOS Docs](https://source.android.com/devices/automotive)