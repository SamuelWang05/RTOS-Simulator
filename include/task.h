/**
 * A base class for any tasks that can be added to the scheduler
 */

#pragma once
#include <string>

/**
* In order to simulate RTOS systems, FSM will be used
*/
enum State {
    running,
    wait,
    done
};

class Task {
public:
    Task() : id(0), priority(0), name(""), state(wait) {};
    explicit Task(int id, int priority, std::string name, State state);

    Task(const Task& rhs) = default;
    Task& operator=(const Task& rhs) = default;
    virtual ~Task() = default;

    void run();

    // Methods to be run depending on the state
    virtual void doRunning() = 0;
    virtual void doWait() = 0;
    virtual void doDone() = 0;

    [[nodiscard]] State getState() const;
    [[nodiscard]] int getPriority() const;
    void setActive();

private:
    int id;
    int priority; // 0 (lowest) -> inf. (highest)
    std::string name;
    State state;
};