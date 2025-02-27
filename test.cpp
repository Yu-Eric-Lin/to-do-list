#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include "to_do_list.cpp"
using namespace std;

// // Function declarations (same as your original code)
// void addTask(vector<string>& tasks, const string& task);
// void deleteTask(vector<string>& tasks, const string& task);
// void viewTasks(const vector<string>& tasks);
// void saveTasksToFile(const vector<string>& tasks, const string& filename);
// void loadTasksFromFile(vector<string>& tasks, const string& filename);

// Test function to check if two vectors are equal
bool areVectorsEqual(const vector<string>& v1, const vector<string>& v2) {
    if (v1.size() != v2.size()) return false;
    for (size_t i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

// Test function to print the result of a test
void printTestResult(const string& testName, bool passed) {
    cout << testName << ": " << (passed ? "PASSED" : "FAILED") << endl;
}

// Test cases
void testAddTask() {
    vector<string> tasks;
    addTask(tasks, "Buy groceries");
    addTask(tasks, "Finish C++ project");

    vector<string> expected = {"Buy groceries", "Finish C++ project"};
    bool passed = areVectorsEqual(tasks, expected);
    printTestResult("testAddTask", passed);
}

void testDeleteTask() {
    vector<string> tasks = {"Buy groceries", "Finish C++ project", "Call mom"};
    deleteTask(tasks, "Finish C++ project");

    vector<string> expected = {"Buy groceries", "Call mom"};
    bool passed = areVectorsEqual(tasks, expected);
    printTestResult("testDeleteTask", passed);
}

void testSaveAndLoadTasks() {
    vector<string> tasks = {"Buy groceries", "Finish C++ project", "Call mom"};
    string filename = "test_tasks.txt";

    // Save tasks to file
    saveTasksToFile(tasks, filename);

    // Load tasks from file
    vector<string> loadedTasks;
    loadTasksFromFile(loadedTasks, filename);

    bool passed = areVectorsEqual(tasks, loadedTasks);
    printTestResult("testSaveAndLoadTasks", passed);
}

void testDeleteNonExistentTask() {
    vector<string> tasks = {"Buy groceries", "Finish C++ project"};
    deleteTask(tasks, "Non-existent task");

    vector<string> expected = {"Buy groceries", "Finish C++ project"};
    bool passed = areVectorsEqual(tasks, expected);
    printTestResult("testDeleteNonExistentTask", passed);
}

void testAddEmptyTask() {
    vector<string> tasks;
    addTask(tasks, "");  // Adding an empty task

    vector<string> expected = {""};
    bool passed = areVectorsEqual(tasks, expected);
    printTestResult("testAddEmptyTask", passed);
}

int main() {
    // Run all test cases
    testAddTask();
    testDeleteTask();
    testSaveAndLoadTasks();
    testDeleteNonExistentTask();
    testAddEmptyTask();

    return 0;
}