#pragma once
#include "string"
#include "functional"

#ifndef TASK_H
#define TASK_H

class Task {
public:
    Task() : id(0), name(""), finished(false), func(std::function<void()>()) {};
    explicit Task(int id, std::string name, bool finished, std::function<void()> func);

    Task(const Task& rhs) = default;
    Task& operator=(const Task& rhs) = default;
    ~Task() = default;

    void run();
    void yield();
    void sleep(int time);

    [[nodiscard]] bool getFinished() const;
    void setActive();

private:
    int id;
    std::string name;
    bool finished;         // Has task finished?
    std::function<void()> func;    // The actual function the task will execute
};

#endif //TASK_H