//
// Created by Isaac Lee on 4/6/26.
//

#ifndef ERRORSTATEKALMANFILTER_TIMER_H
#define ERRORSTATEKALMANFILTER_TIMER_H

#include <chrono>

class Timer {
public:
    void start() {
        startTime = std::chrono::high_resolution_clock::now();
    }

    void stop() {
        endTime = std::chrono::high_resolution_clock::now();
    }

    long long getTime() const {
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        return duration.count();
    }

    double getTimeSeconds() const {
        auto duration = std::chrono::duration<double>(endTime - startTime);
        return duration.count();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
};

#endif //ERRORSTATEKALMANFILTER_TIMER_H