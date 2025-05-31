#include "scheduler.h"

Scheduler::Scheduler(std::vector<Task> taskList) : taskList(std::move(taskList)) {
}

void Scheduler::addTask(Task& task) {
    taskList.push_back(task);
}

void Scheduler::run() {
    for (Task& currTask : taskList) {
        if (!currTask.getFinished()) {
            currTask.run();
        }
    }
}
