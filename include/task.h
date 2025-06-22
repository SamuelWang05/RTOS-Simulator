/**
 * Using concurrent threads to simulate tasks in RTOS on real hardware
 */

#pragma once
#include <string>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

class Task {
public:
    explicit Task(int id, int priority, std::string name, std::function<void(Task&)> func);

    void taskRun();
    void taskYield();
    void taskComplete();

    [[nodiscard]] int getPriority() const;
    [[nodiscard]] bool getRunStatus() const;
    [[nodiscard]] bool getComplete() const;
private:
    int id;
    int priority; // 0 (lowest) -> inf. (highest)
    std::string name;
    std::function<void(Task&)> func;

    std::mutex taskLock;
    std::condition_variable conditionVar;
    std::jthread taskThread;

    bool shouldRun = false;
    bool complete = false;
};