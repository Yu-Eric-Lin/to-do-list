
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void addTask(std::vector<std::string>& tasks, string task);
void deleteTask(std::vector<std::string>& tasks, string task);
void viewTasks(const std::vector<std::string>& tasks);
void saveTasksToFile(const std::vector<std::string>& tasks, const std::string& filename);
void loadTasksFromFile(std::vector<std::string>& tasks, const std::string& filename);

int main(){

    vector<string> tasks;
    int i = 1;
    cout << "hello world";
    while (i) {
        int input;
        string task;
        string filename;
        cout << "you have " << tasks.size() << "remaining\n";
        // take in the value form the user
        cout << "choose your option: \n 1. add task\n 2.delete a1 task\n 3.view task\n 4.save the task to file\n 5.load task from file\n 6.exit\n";
        cin >> input;
        switch (input)
        {
        case 1:
            cout << "enter the task you would like to add to the list:\n";
            cin >> task;
            addTask(tasks, task);
            continue;
        case 2:
            cout << "enter the task you would like to delete form the list:\n";
            cin >> task;
            deleteTask(tasks, task);
            continue;
        case 3:
            viewTasks(tasks);
            continue;
        case 4:
            cout << "enter the filename you would like to store the tasks:\n";
            cin >> filename;
            saveTasksToFile(tasks, filename);
            continue;
        case 5:
            cout << "enter the filenmae you would like the file to load from:\n";
            cin >> filename;
            tasks.clear();
            loadTasksFromFile(tasks, filename);
            continue;
        case 6:
            break;
        default:
            cout << "please enter the correct option.\n";
            continue;
        }
    }
    return 0;
}

void addTask(std::vector<std::string>& tasks, string task){
    tasks.push_back(task);

}

void deleteTask(std::vector<std::string>& tasks, string task){
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

void viewTasks(const std::vector<std::string>& tasks){
    for(string task: tasks){
        cout << task << endl;
    }

}

void saveTasksToFile(const std::vector<std::string>& tasks, const std::string& filename){
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
void loadTasksFromFile(std::vector<std::string>& tasks, const std::string& filename){
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

