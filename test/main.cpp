#include "task.h"
#include "scheduler.h"
#include <iostream>
#include <chrono>

void print1() {
    std::cout << "I printed 1\n";
}

void print2() {
    std::cout << "I printed 2\n";
}

void print3() {
    std::cout << "I printed 3\n";
}

int main() {
    Scheduler schedule;

    schedule.run();
}