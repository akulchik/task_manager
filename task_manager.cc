#include "task_manager.h"


void TaskManager::add_task(const std::string &name, task_fn_t task_fn) {
    if (name.empty()) {
        std::cout << "Name for a task function cannot be empty.\n";
        std::abort();
    }
    if (name == "exit") {
        std::cout << "Name 'exit' is reserved.\n";
        std::abort();
    }

    if (tasks_.find(name) != tasks_.end()) {
        std::cout << "Name '" << name << "' is already taken by another"
                  << " function.\n";
        std::abort();
    }

    tasks_.emplace(name, task_fn);
}


void TaskManager::event_loop() {
    std::string name;
    while (true) {
        std::cout << "Enter task name (type 'exit' to stop): ";
        std::getline(std::cin, name);
        if (name == "exit") {
            break;
        } else if (name.empty()) {
            continue;
        } else if (tasks_.find(name) == tasks_.end()) {
            std::cout << "Cannot run unregistered task '" << name << "'.\n";
        } else {
            run_task(name);
        }
        std::cout << "\n";
        std::cin.get();
    }
}


void TaskManager::run_task(const std::string &name, bool display_name = true) {
    if (display_name) std::cout << "-*=*- " << name << " -*=*-\n";
    tasks_[name]();
}
