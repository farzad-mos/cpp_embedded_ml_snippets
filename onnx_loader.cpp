#include <onnxruntime_cxx_api.h>
#include <iostream>
#include <vector>

int main() {
    Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "ADAS");
    Ort::SessionOptions session_options;
    session_options.SetIntraOpNumThreads(1);

    Ort::Session session(env, "model.onnx", session_options);
    std::cout << "Model loaded successfully!" << std::endl;

    std::vector<float> input_tensor_values(3 * 224 * 224, 1.0f);
    std::vector<int64_t> input_shape = {1, 3, 224, 224};

    Ort::MemoryInfo memory_info = Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeCPU);
    Ort::Value input_tensor = Ort::Value::CreateTensor<float>(memory_info, input_tensor_values.data(), input_tensor_values.size(), input_shape.data(), input_shape.size());

    auto input_names = session.GetInputNameAllocated(0, Ort::AllocatorWithDefaultOptions());
    auto output_names = session.GetOutputNameAllocated(0, Ort::AllocatorWithDefaultOptions());

    auto output_tensors = session.Run(Ort::RunOptions{nullptr}, &input_names.get(), &input_tensor, 1, &output_names.get(), 1);

    std::cout << "Inference done!" << std::endl;
    return 0;
}