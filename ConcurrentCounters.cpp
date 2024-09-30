#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // Mutex for thread synchronization

void countUp() {
    for (int i = 0; i <= 20; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Count Up: " << i << std::endl;
    }
}

void countDown() {
    for (int i = 20; i >= 0; --i) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Count Down: " << i << std::endl;
    }
}

int main() {
    // Create and run the first thread (count up to 20)
    std::thread t1(countUp);

    // Wait for the first thread to finish
    t1.join();

    // Create and run the second thread (count down to 0)
    std::thread t2(countDown);

    // Wait for the second thread to finish
    t2.join();

    return 0;
}