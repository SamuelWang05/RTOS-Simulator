#pragma once

// Non-preemptive priority scheduler

#include "map"
#include "task.h"

#ifndef SCHEDULER_H
#define SCHEDULER_H

class Scheduler {
public:
    Scheduler() : taskSchedule(std::map<int, Task>()) {}; explicit Scheduler(std::vector<Task> taskList);
    Scheduler(const Scheduler& rhs) = default;
    Scheduler& operator=(const Scheduler& rhs) = default;
    ~Scheduler() = default;

    void addTask(Task& task);

    void run(); // Runs active tasks in order

private:
    std::map<int, Task> taskSchedule;
};

#endif //SCHEDULER_H