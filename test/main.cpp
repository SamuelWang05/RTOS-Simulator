#include <scheduler.h>

#include "task.h"
#include "scheduler.h"
#include "iostream"

void print1() {
    std::cout << "Printed 1\n";
}

void print2() {
    std::cout << "Printed 2\n";
}

void print3() {
    std::cout << "Printed 3\n";
}

int main() {
    Scheduler sch;

    std::function<void()> p1 = print1;
    std::function<void()> p2 = print2;
    std::function<void()> p3 = print3;

    Task task1(1, "print1", false, p1);
    Task task2(2, "print2", false, p2);
    Task task3(3, "print3", false, p3);

    sch.addTask(task1);
    sch.addTask(task2);
    sch.addTask(task3);

    sch.run();

    return 0;
}