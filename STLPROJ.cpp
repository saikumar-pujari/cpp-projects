#include <bits/stdc++.h>
using namespace std;

// 🎨 ANSI Color Codes for console styling
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

struct Task {
    int id;
    string description;
    bool completed;
};

// 🧾 MENU DISPLAY
void showMenu() {
    cout << BLUE << "\n========= 📋 TASK MANAGER MENU =========\n" << RESET;
    cout << "1. ➕ Add Task\n";
    cout << "2. 👀 View Tasks\n";
    cout << "3. ✅ Mark Task as Completed\n";
    cout << "4. ❌ Delete Task\n";
    cout << "5. 🚪 Exit\n";
    cout << YELLOW << "Enter your choice: " << RESET;
}

// ➕ Add a new task
void addTask(vector<Task>& tasks, int& idCounter) {
    Task newTask;
    newTask.id = idCounter++;
    cout << CYAN << "Enter task description: " << RESET;
    cin.ignore();
    getline(cin, newTask.description);

    for (const auto& task : tasks) {
        if (task.description == newTask.description) {
            cout << RED << "⚠️ Task already exists.\n" << RESET;
            return;
        }
    }

    newTask.completed = false;
    tasks.push_back(newTask);
    cout << GREEN << "✅ Task added successfully!\n" << RESET;
}

// 👀 View all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << RED << "📭 No tasks to show.\n" << RESET;
        return;
    }

    vector<Task> sortedTasks = tasks;
    sort(sortedTasks.begin(), sortedTasks.end(), [](const Task& a, const Task& b) {
        return a.description < b.description;
    });

    cout << BLUE << "\n========= YOUR TASKS =========\n" << RESET;
    for (const auto& task : sortedTasks) {
        cout << "🆔 ID: " << task.id
             << " | 📌 " << task.description
             << " | Status: " << (task.completed ? GREEN "✅ Completed" : YELLOW "⏳ Pending") << RESET << endl;
    }
}

// ✅ Mark a task as completed
void markAsDone(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << RED << "📭 No task to update.\n" << RESET;
        return;
    }

    int id;
    cout << CYAN << "Enter task ID to mark as completed: " << RESET;
    cin >> id;

    for (auto& task : tasks) {
        if (task.id == id) {
            if (task.completed) {
                cout << YELLOW << "⚠️ Task is already completed.\n" << RESET;
            } else {
                task.completed = true;
                cout << GREEN << "✅ Task marked as completed.\n" << RESET;
            }
            return;
        }
    }

    cout << RED << "❌ Task with ID " << id << " not found.\n" << RESET;
}

// ❌ Delete a task
void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << RED << "📭 No task to delete.\n" << RESET;
        return;
    }

    int id;
    cout << CYAN << "Enter task ID to delete: " << RESET;
    cin >> id;

    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            cout << GREEN << "🗑️ Task with ID " << id << " deleted successfully.\n" << RESET;
            return;
        }
    }

    cout << RED << "❌ Task with ID " << id << " not found.\n" << RESET;
}

// 🚀 Main function
int main() {
    vector<Task> tasks;
    int choice;
    int idCounter = 1;

    cout << GREEN << "✅ Welcome to the Stylish Task Manager! 🧠\n" << RESET;

    while (true) {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "❌ Invalid input. Please enter a number between 1 and 5.\n" << RESET;
            continue;
        }

        switch (choice) {
            case 1:
                cout << YELLOW << "👉 Add Task selected\n" << RESET;
                addTask(tasks, idCounter);
                break;
            case 2:
                cout << YELLOW << "👉 View Tasks selected\n" << RESET;
                viewTasks(tasks);
                break;
            case 3:
                cout << YELLOW << "👉 Mark Task as Completed selected\n" << RESET;
                markAsDone(tasks);
                break;
            case 4:
                cout << YELLOW << "👉 Delete Task selected\n" << RESET;
                deleteTask(tasks);
                break;
            case 5:
                cout << GREEN << "👋 Exiting Task Manager. Have a productive day!\n" << RESET;
                return 0;
            default:
                cout << RED << "❌ Invalid choice. Try again.\n" << RESET;
        }
    }

    return 0;
}
