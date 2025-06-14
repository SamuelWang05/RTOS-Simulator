#include "scheduler.h"

void Scheduler::addTask(std::unique_ptr<Task> task) {
    taskSchedule.insert({task->getPriority(), std::move(task)});
}

// Runs the highest priority task
void Scheduler::run() {
    if (taskSchedule.empty())
        return;

    (--taskSchedule.end())->second->run(); // Keys sorted in ascending order

    if ((--taskSchedule.end())->second->getState() == done) {
        taskSchedule.erase((--taskSchedule.end())->first); // Remove task after it is done
    }
}