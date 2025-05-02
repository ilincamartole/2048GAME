

#ifndef TIMEOUT_H
#define TIMEOUT_H

#include <chrono>

class Timeout {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timeout();
    void startTimer();
    double getElapsedSeconds() const;
};

#endif // TIMEOUT_H
