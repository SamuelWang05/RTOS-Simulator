#include "scheduler.h"

void Scheduler::addTask(Task& task) {
    taskSchedule.insert({task.getPriority(), task});
}

// Runs the highest priority task
void Scheduler::run() {
    if (taskSchedule.empty()) {
        return;
    }
    (--taskSchedule.end())->second.run(); // Keys sorted in ascending order
    taskSchedule.erase((--taskSchedule.end())->first); // Remove task after it is done
}