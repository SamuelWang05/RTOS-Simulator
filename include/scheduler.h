#pragma once

// Cooperative scheduler

#include "vector"
#include "task.h"

#ifndef SCHEDULER_H
#define SCHEDULER_H

class Scheduler {
public:
    Scheduler() : taskList(std::vector<Task>()) {};
    explicit Scheduler(std::vector<Task> taskList);

    Scheduler(const Scheduler& rhs) = default;
    Scheduler& operator=(const Scheduler& rhs) = default;
    ~Scheduler() = default;

    void addTask(Task& task);

    void run(); // Runs active tasks in order

private:
    std::vector<Task> taskList;
};

#endif //SCHEDULER_H