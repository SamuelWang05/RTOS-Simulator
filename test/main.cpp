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

/**
 * TODO: [x] implement FSM for tasks
 * TODO: [ ] change scheduler class to handle polymorphism (need to add unique_ptr for task)
 * TODO: [ ] use std::chrono library to simulate time (for delays, etc.)
 * TODO: [ ] add different derived tasks (UART, etc.)
 */
int main() {
    Scheduler schedule;

    schedule.run();
}