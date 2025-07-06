#include "scheduler.h"
#include <chrono>

Scheduler::Scheduler() : taskSchedule(std::multimap<int, std::unique_ptr<Task>>()) {};

void Scheduler::addTask(std::unique_ptr<Task> task) {
    taskSchedule.insert({task->getPriority(),std::move(task)});
}

void Scheduler::start() {
    running = true;
    runLoop();
}

void Scheduler::stop() {
    std::unique_lock<std::mutex> lock(schedulerLock);
    currTask->taskYield();
    running = false;
}

void Scheduler::runLoop() {
    while (running) {
        std::lock_guard<std::mutex> lock(schedulerLock);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

/**
void Scheduler::run() {


    // TODO -- add simulated tick to do non-preemptive scheduling

    if (taskSchedule.empty()) {
        return;
    }

    auto currTask = --taskSchedule.end();

    currTask->second->taskRun();

    if (currTask->second->getComplete()) {
       taskSchedule.erase(currTask);
    }
}
*/