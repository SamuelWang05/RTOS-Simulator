/**
* Preemptive priority scheduler - manages all task threads, tick control, and task switching
*/

#pragma once

#include "map"
#include "task.h"
#include <chrono>

class Scheduler {
public:
    Scheduler();

    void addTask(std::unique_ptr<Task> task);
    void start();
    void stop();

private:
    void runLoop();
    std::atomic<bool> running = true;
    std::jthread schedulerThread;

    std::multimap<int, std::unique_ptr<Task>> taskSchedule;
    std::mutex schedulerLock;

    Task* currTask;
    bool taskShouldRun = false;
    bool taskComplete = false;
};