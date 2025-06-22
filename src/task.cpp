#include "task.h"
#include <chrono>

using namespace std::chrono_literals;

Task::Task(int id, int priority, std::string name, std::function<void(Task&)> func)
    : id(id), priority(priority), name(std::move(name)), func(func) {

    taskThread = std::jthread([&]() {
        while (!complete) {
            std::unique_lock<std::mutex> lock(taskLock);
            conditionVar.wait(lock,[this](){return shouldRun || complete;});

            if (complete) break;

            shouldRun = false;
            func(*this);
        }
    });
}

void Task::taskRun() {
    std::unique_lock<std::mutex> lock(taskLock);
    shouldRun = true;
    conditionVar.notify_one();
}

void Task::taskYield() {
    std::unique_lock<std::mutex> lock(taskLock);
    shouldRun = false;
    conditionVar.wait(lock, [this](){return shouldRun;});
}

void Task::taskComplete() {
    std::unique_lock<std::mutex> lock(taskLock);
    complete = true;
    conditionVar.notify_one();
}

int Task::getPriority() const {
    return priority;
}

bool Task::getRunStatus() const {
    return shouldRun;
}

bool Task::getComplete() const {
    return complete;
}