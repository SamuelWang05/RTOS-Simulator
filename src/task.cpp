#include "task.h"

#include <utility>

Task::Task(const int id, std::string  name, bool finished, std::function<void()> func) : id(id), name(std::move(name)), finished(finished), func(std::move(func)) {
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

void Task::setActive() {
    finished = false;
}