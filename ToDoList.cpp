#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void showTasks(const std::vector<std::string> &tasks) {
    std::cout << "To-Do List:" << std::endl;
    for (int i = 0; i < tasks.size(); ++i)
    {
        std::cout << i + 1 << ". " << tasks[i] << std::endl;
    }
}

void readTasksFromFile(std::string filepath, std::vector<std::string> &tasks) {
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

    std::cout << "Enter a task: ";
    std::cin.ignore(); // Clears the input buffer
    getline(std::cin, task);
    tasks.push_back(task);
}

std::string task;

int main() {

    std::vector<std::string> tasks;
    char choice;

    readTasksFromFile("tasks.txt", tasks);

    do {
        std::cout << "A - Add a task" << std::endl;
        std::cout << "V - View tasks" << std::endl;
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
                showTasks(tasks);
                break;
        }

    } while (choice != 'Q' && choice != 'q');

    saveTasksAndClose("tasks.txt", tasks);

    return 0;
}