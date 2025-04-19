// mini_pipeline.cpp
// Real-time image → preprocess → inference → postprocess pipeline
#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>

// Simulated frame struct
struct Frame {
    int id;
    std::vector<uint8_t> data;  // raw image bytes
};

std::queue<Frame> capture_queue;
std::queue<Frame> preprocess_queue;
std::queue<std::vector<float>> inference_queue;

std::mutex mtx1, mtx2;
std::condition_variable cv1, cv2;

bool stop = false;

// 1. Image Capture Thread
void captureThread() {
    int frame_id = 0;
    while (!stop) {
        Frame frame = {frame_id++, std::vector<uint8_t>(640*480)};
        std::this_thread::sleep_for(std::chrono::milliseconds(30)); // simulate 30 FPS
        {
            std::lock_guard<std::mutex> lock(mtx1);
            capture_queue.push(frame);
        }
        cv1.notify_one();
    }
}

// 2. Preprocessing Thread
void preprocessThread() {
    while (!stop) {
        std::unique_lock<std::mutex> lock(mtx1);
        cv1.wait(lock, [] { return !capture_queue.empty() || stop; });

        if (!capture_queue.empty()) {
            Frame raw = capture_queue.front();
            capture_queue.pop();
            lock.unlock();

            // Simulate preprocessing
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            {
                std::lock_guard<std::mutex> lock2(mtx2);
                preprocess_queue.push(raw);
            }
            cv2.notify_one();
        }
    }
}

// 3. Inference Thread
void inferenceThread() {
    while (!stop) {
        std::unique_lock<std::mutex> lock(mtx2);
        cv2.wait(lock, [] { return !preprocess_queue.empty() || stop; });

        if (!preprocess_queue.empty()) {
            Frame preprocessed = preprocess_queue.front();
            preprocess_queue.pop();
            lock.unlock();

            // Simulate inference output
            std::vector<float> output = {0.1f, 0.9f}; // dummy probabilities
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            std::cout << "Frame " << preprocessed.id << " processed: Class 1 prob = " << output[1] << std::endl;
        }
    }
}

int main() {
    std::thread t1(captureThread);
    std::thread t2(preprocessThread);
    std::thread t3(inferenceThread);

    std::this_thread::sleep_for(std::chrono::seconds(3));  // run pipeline for 3 seconds
    stop = true;

    cv1.notify_all();
    cv2.notify_all();

    t1.join();
    t2.join();
    t3.join();

    return 0;
}