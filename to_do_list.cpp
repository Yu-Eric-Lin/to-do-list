
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void addTask(vector<string>& tasks, string task);
void deleteTask(vector<string>& tasks, string task);
void viewTasks(const vector<string>& tasks);
void saveTasksToFile(const vector<string>& tasks, const string& filename);
void loadTasksFromFile(vector<string>& tasks, const string& filename);

int main() {
    vector<string> tasks;
    cout << "Welcome to the To-Do List App!\n";
    while (true) {  // Use a loop that runs indefinitely until the user chooses to exit
        int input;
        string task;
        string filename;
        cout << "You have " << tasks.size() << " tasks remaining.\n";
        // Take input from the user
        cout << "Choose your option:\n"
             << "1. Add task\n"
             << "2. Delete a task\n"
             << "3. View tasks\n"
             << "4. Save tasks to file\n"
             << "5. Load tasks from file\n"
             << "6. Exit\n";
        cin >> input;

        switch (input) {
            case 1:
                cout << "Enter the task you would like to add to the list:\n";
                cin.ignore();  // Clear the input buffer
                getline(cin, task);  // Use getline to allow spaces in the task
                addTask(tasks, task);
                break;
            case 2:
                cout << "Enter the task you would like to delete from the list:\n";
                cin.ignore();  // Clear the input buffer
                getline(cin, task);  // Use getline to allow spaces in the task
                deleteTask(tasks, task);
                break;
            case 3:
                viewTasks(tasks);
                break;
            case 4:
                cout << "Enter the filename you would like to store the tasks:\n";
                cin >> filename;
                saveTasksToFile(tasks, filename);
                break;
            case 5:
                cout << "Enter the filename you would like to load tasks from:\n";
                cin >> filename;
                tasks.clear();
                loadTasksFromFile(tasks, filename);
                break;
            case 6:
                cout << "Exiting the program. Goodbye!\n";
                return 0;  // Exit the program
            default:
                cout << "Please enter a valid option.\n";
                break;
        }
    }
    return 0;
}

void addTask(vector<string>& tasks, string task){
    tasks.push_back(task);

}

void deleteTask(vector<string>& tasks, string task){
    int i = 0;
    int j = 0;
    for (auto t: tasks){
        if(t == task){
            tasks.erase(tasks.begin() + i);
            j = 1;
            break;
        }
        i++;
    }
    if (j == 0){
        cout << "task doesn't exist";
    }

}

void viewTasks(const vector<string>& tasks){
    for(string task: tasks){
        cout << task << endl;
    }

}

void saveTasksToFile(const vector<string>& tasks, const string& filename){
    ofstream outputfile(filename);
    if (outputfile.is_open()){
        for (auto task: tasks){
            outputfile << task << endl;
        }
        outputfile.close();
    }
    else{
        cout << "unable to open the file provided" << endl;
    }

}
void loadTasksFromFile(vector<string>& tasks, const string& filename){
    ifstream inputfile;
    string task;
    inputfile.open(filename);
    if (inputfile.is_open()){
        while(getline(inputfile, task)){
            tasks.push_back(task);
        }
        inputfile.close();
    }
    else{
        cout << "unable to open the file provided" << endl;
    }
}

