#include <iostream>
#include <vector>
#include <string>
#include <limits> 

using namespace std;

struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << (tasks[i].isCompleted ? "[Yes] " : "[No] ") << tasks[i].description << endl;
        }
    }

    void markTaskAsCompleted(size_t taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            cout << "Invalid task index." << endl;
            return;
        }

        tasks[taskIndex - 1].isCompleted = true;
        cout << "Task " << taskIndex << " marked as completed." << endl;
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            cout << "Invalid task index." << endl;
            return;
        }

        tasks.erase(tasks.begin() + taskIndex - 1);
        cout << "Task " << taskIndex << " removed." << endl;
    }
};

void displayMenu() {
    cout << "\nTODO List Application" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    TodoList todoList;
    int choice;
    string description;
    size_t taskIndex;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, description);
                todoList.addTask(description);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskIndex;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                todoList.markTaskAsCompleted(taskIndex);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskIndex;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                todoList.removeTask(taskIndex);
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
