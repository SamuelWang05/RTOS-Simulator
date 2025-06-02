#include "task.h"

#include <utility>

Task::Task(const int id, const int priority, std::string  name, bool finished, std::function<void()> func) : id(id), priority(priority), name(std::move(name)), finished(finished), func(std::move(func)) {
}

void Task::run() {
    func();
    this->finished = true;
}

void Task::yield() {
}

void Task::sleep(int time) {
}


bool Task::getFinished() const {
    return finished;
}

int Task::getPriority() const {
    return priority;
}

void Task::setActive() {
    finished = false;
}