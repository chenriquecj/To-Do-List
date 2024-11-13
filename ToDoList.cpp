#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Linux and macOS
    #endif
}

void showTasks(const std::vector<std::string> &tasks) {
    std::cout << "To-Do List:" << std::endl;
    for (int i = 0; i < tasks.size(); ++i)
    {
        std::cout << i + 1 << ". " << tasks[i] << std::endl;
    }
}

void readTasksFromFile(std::string filepath, std::vector<std::string> &tasks) {
    std::string task;

    std::ifstream inputFile(filepath);
    while (getline(inputFile, task))
    {
        tasks.push_back(task);
    }
    inputFile.close();
}

void saveTasksAndClose(std::string filepath, std::vector<std::string> &tasks) {
    std::ofstream outputFile(filepath);
    for (const auto &t : tasks)
    {
        outputFile << t << std::endl;
    }
    outputFile.close();
}

void addTask(std::vector<std::string> &tasks){
    std::string task;

    std::cout << "Enter a task: ";
    std::cin.ignore(); // Clears the input buffer
    getline(std::cin, task);
    tasks.push_back(task);

    std::cout << "\nTask added succesfully!";
}

void removeTask(std::vector<std::string> &tasks){
    int taskNumber;
    showTasks(tasks);
    std::cout << "Select the number of the task you wish to remove: ";
    std::cin >> taskNumber;

    if(taskNumber <= tasks.size()){
        tasks.erase(tasks.begin() + (taskNumber - 1));
        std::cout << "Task number " << taskNumber << " removed successfully!" << std::endl;
    } else {
        std::cout << "Input number exceeds list size." << std::endl;
    }
}

int main() {

    std::vector<std::string> tasks;
    char choice;

    readTasksFromFile("tasks.txt", tasks);

    do {
        clearScreen();
        std::cout << "A - Add a task" << std::endl;
        std::cout << "V - View tasks" << std::endl;
        std::cout << "R - Remove a task" << std::endl;
        std::cout << "Q - Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 'a':
            case 'A':
                addTask(tasks);
                break;
            case 'v':
            case 'V':
                std::cin.ignore();
                showTasks(tasks);
                break;
            case 'r':
            case 'R':
                std::cin.ignore();
                removeTask(tasks);
                break;
        }
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice != 'Q' && choice != 'q');

    saveTasksAndClose("tasks.txt", tasks);

    return 0;
}