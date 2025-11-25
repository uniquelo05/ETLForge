#include "metrics.hpp"
#include <iostream>

namespace etlforge {

Metrics::Metrics() : isRunning(false) {
    // Constructor implementation
}

Metrics::~Metrics() {
    // Destructor implementation
}

void Metrics::startTimer() {
    startTime = std::chrono::high_resolution_clock::now();
    isRunning = true;
}

void Metrics::stopTimer() {
    if (isRunning) {
        endTime = std::chrono::high_resolution_clock::now();
        isRunning = false;
    }
}

double Metrics::getElapsedTime() const {
    if (isRunning) {
        std::cerr << "Timer is still running!" << std::endl;
        return 0.0;
    }
    std::chrono::duration<double> elapsed = endTime - startTime;
    return elapsed.count();
}

} // namespace etlforge