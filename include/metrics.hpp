#ifndef ETLFORGE_METRICS_HPP
#define ETLFORGE_METRICS_HPP

#include <string>
#include <chrono>

namespace etlforge {

class Metrics {
public:
    Metrics();
    ~Metrics();

    void startTimer();
    void stopTimer();
    double getElapsedTime() const;

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
    bool isRunning;
};

} // namespace etlforge

#endif // ETLFORGE_METRICS_HPP