/**
* Non-preemptive priority scheduler
*/

#pragma once

#include "map"
#include "task.h"
#include <chrono>

#ifndef SCHEDULER_H
#define SCHEDULER_H

class Scheduler {
public:
    Scheduler() : taskSchedule(std::map<int, std::unique_ptr<Task>>()) {}; explicit Scheduler(std::vector<Task> taskList);
    Scheduler(const Scheduler& rhs) = default;
    Scheduler& operator=(const Scheduler& rhs) = default;
    ~Scheduler() = default;

    void addTask(std::unique_ptr<Task> task);

    void run(); // Runs only the first task in the schedule

private:
    std::map<int, std::unique_ptr<Task>> taskSchedule;
};

#endif //SCHEDULER_H