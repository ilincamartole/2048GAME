#include "Timeout.h"

Timeout::Timeout() {
    start = std::chrono::high_resolution_clock::now();
}

void Timeout::startTimer() {
    start = std::chrono::high_resolution_clock::now();
}

double Timeout::getElapsedSeconds() const {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    return elapsed.count();
}
