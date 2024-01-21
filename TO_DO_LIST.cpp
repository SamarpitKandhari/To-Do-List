#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

void menu();
void addtask(vector<Task>& tasks, const string& description);
void viewtasks(const vector<Task>& tasks);
void completedtask(vector<Task>& tasks, int taskindex);
void removetask(vector<Task>& tasks, int taskindex);

int main() {
    vector<Task> tasks;

    int choice;
    string description;

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                addtask(tasks, description);
                break;
            case 2:
                viewtasks(tasks);
                break;
            case 3:
                int taskindex;
                cout << "Enter task index to mark as completed: ";
                cin >> taskindex;
                completedtask(tasks, taskindex);
                break;
            case 4:
                cout << "Enter task index to remove: ";
                cin >> taskindex;
                removetask(tasks, taskindex);
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

void menu() {
    cout << "\n===== To-Do List Manager =====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "==============================" << endl;
    cout << "Enter your choice: ";
}

void addtask(vector<Task>& tasks, const string& description) {
    tasks.push_back(Task(description));
    cout << "Task added successfully!" << endl;
}

void viewtasks(const vector<Task>& tasks) {
    cout << "\n===== Tasks =====" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << setw(3) << i + 1 << ". ";
        cout << (tasks[i].completed ? "[X] " : "[ ] ");
        cout << tasks[i].description << endl;
    }
    cout << "===================" << endl;
}

void completedtask(vector<Task>& tasks, int taskindex) {
    if (taskindex >= 1 && static_cast<size_t>(taskindex) <= tasks.size()) {
        tasks[taskindex - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task index. Please try again." << endl;
    }
}

void removetask(vector<Task>& tasks, int taskindex) {
    if (taskindex >= 1 && static_cast<size_t>(taskindex) <= tasks.size()) {
        tasks.erase(tasks.begin() + taskindex - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task index. Please try again." << endl;
    }
}
