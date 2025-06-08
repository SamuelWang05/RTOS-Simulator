#include "task.h"
#include <utility>

Task::Task(const int id, const int priority, std::string name, State state)
    : id(id), priority(priority), name(std::move(name)), state(state) {
}

void Task::run() {
    switch (state) {
        case running:
            doRunning();
            break;
        case wait:
            doWait();
            break;
        case done:
            doDone();
            break;
    }
}

State Task::getState() const {
    return state;
}

int Task::getPriority() const {
    return priority;
}

void Task::setActive() {
    state = running;
}