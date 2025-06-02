#include <scheduler.h>

#include "task.h"
#include "scheduler.h"
#include <iostream>

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

    Task task1(1, 0, "print1", false, print1);
    Task task2(2, 1, "print2", false, print2);
    Task task3(3, 2, "print3", false, print3);

    schedule.addTask(task1);
    schedule.addTask(task2);

    schedule.run();
    schedule.addTask(task3);
    schedule.run();
    schedule.run();
}