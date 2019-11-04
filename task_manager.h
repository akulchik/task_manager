#ifndef TASK_MANAGER_TASK_MANAGER_H_
#define TASK_MANAGER_TASK_MANAGER_H_

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>


typedef void (*task_fn_t)();


class TaskManager {
public:
    // public constructors
    static TaskManager& get_instance() {
        static TaskManager instance;
        return instance;
    };

    TaskManager(TaskManager const&) = delete;
    void operator=(TaskManager const&) = delete;

    // public interface
    void add_task(const std::string&, task_fn_t);
    void event_loop();
    void run_task(const std::string&, bool display_name = true);

private:
    // private constructor
    TaskManager() = default;

    std::map<std::string, task_fn_t> tasks_;
};

#endif // TASK_MANAGER_TASK_MANAGER_H_
