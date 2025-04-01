#include <iostream>     // Input/output stream objects
#include <fstream>      // File stream objects
#include <sstream>      // String stream objects
#include <iomanip>      // Input/output manipulators
#include <string>       // String class and functions
#include <vector>       // Dynamic array
#include <list>         // Doubly linked list
#include <set>          // Set container
#include <map>          // Map container
#include <queue>        // Queue container
#include <stack>        // Stack container
#include <algorithm>    // Algorithms on sequences (e.g., sort, find)
#include <cmath>        // Mathematical functions
#include <ctime>        // Date and time functions
#include <cstdlib>      // General purpose functions (e.g., memory management)
#include <cstring>      // C-style string functions
#include <cctype>       // Character classification functions
#include <cassert>      // Assert function for debugging
#include <exception>    // Standard exceptions
#include <functional>   // Function objects
#include <iterator>     // Iterator classes
#include <limits>       // Numeric limits
#include <locale>       // Localization and internationalization
#include <numeric>      // Numeric operations (e.g., accumulate)
#include <random>       // Random number generators
#include <stdexcept>    // Standard exception classes
#include <typeinfo>     // Runtime type information
#include <utility>      // Utility components (e.g., std::pair)
using namespace std;

// Function to get current date and time
string getDateTime() {
    time_t now = time(0);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buffer);
}

// Function to get user information
void userInformation(const string& username, const string& password) {
    string filename = username + "_task.txt";
    ofstream file(filename, ios::app);

    if (!file) {
        cout << "Error creating file!\n";
        return;
    }

    string name, address, age;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your address: ";
    getline(cin, address);
    cout << "Enter your age: ";
    getline(cin, age);

    file << password << "\n";
    file << "Name: " << name << "\n";
    file << "Address: " << address << "\n";
    file << "Age: " << age << "\n";
    file.close();
}

// Function to sign up a new user
void signup() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;
    cin.ignore();

    userInformation(username, password);
    // cout << "Signup successful. Please proceed to login.\n";
    cout << "Signup successful. You can now log in from the main menu.\n";

}

// Function to view user data
void viewData(const string& username) {
    string filename = username + "_task.txt";
    ifstream file(filename);

    if (!file) {
        cout << "No data found for " << username << endl;
        return;
    }

    cout << "User Data:\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Function to add tasks
void addTask(const string& username) {
    string filename = username + "_task.txt";
    ofstream file(filename, ios::app);

    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    int numTasks;
    cout << "Enter number of tasks to add: ";
    cin >> numTasks;
    cin.ignore();

    for (int i = 1; i <= numTasks; ++i) {
        string task, target;
        cout << "Enter task " << i << ": ";
        getline(cin, task);
        cout << "Enter target " << i << ": ";
        getline(cin, target);

        file << "TASK " << i << ": " << task << "\n";
        file << "TARGET " << i << ": " << target << "\n";
    }

    file.close();
    cout << "Tasks added successfully!\n";
}

// Function to update task status
void updateTask(const string& username) {
    string filename = username + "_TASK.txt";
    ofstream file(filename, ios::app);

    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    string completed, notStarted, ongoing;
    cout << "Enter completed tasks: ";
    cin.ignore();
    getline(cin, completed);

    cout << "Enter not started tasks: ";
    getline(cin, notStarted);

    cout << "Enter ongoing tasks: ";
    getline(cin, ongoing);

    file << getDateTime() << "\n";
    file << "COMPLETED TASKS: " << completed << "\n";
    file << "NOT STARTED TASKS: " << notStarted << "\n";
    file << "ONGOING TASKS: " << ongoing << "\n";

    file.close();
    cout << "Task status updated successfully!\n";
}

// Function to view task updates
void viewTaskUpdate(const string& username) {
    string filename = username + "_TASK.txt";
    ifstream file(filename);

    if (!file) {
        cout << "No task updates found for " << username << endl;
        return;
    }

    cout << "Task Status:\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

// Function to log in
void login() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin.ignore();
    getline(cin, password);

    string filename = username + "_task.txt";
    ifstream file(filename);

    if (!file) {
        cout << "User not found. Please sign up.\n";
        return;
    }

    string savedPassword;
    getline(file, savedPassword);  // First line is the password
    file.close();

    if (password == savedPassword) {
        cout << "Login successful!\n";
        int choice;

        while (true) {
            cout << "1 - View your data\n";
            cout << "2 - Add task\n";
            cout << "3 - Update task\n";
            cout << "4 - View task status\n";
            cout << "5 - Logout\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    viewData(username);
                    break;
                case 2:
                    addTask(username);
                    break;
                case 3:
                    updateTask(username);
                    break;
                case 4:
                    viewTaskUpdate(username);
                    break;
                case 5:
                    cout << "Logged out successfully.\n";
                    return;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        }
    } else {
        cout << "Invalid password. Try again.\n";
        login();
    }
}

int main() {
    cout << "WELCOME TO TASK MANAGER\n";
    int choice;
    cout << "1 - Sign up\n";
    cout << "0 - Login\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        signup();
    } else if (choice == 0) {
        login();
    } else {
        cout << "Invalid choice. Exiting...\n";
    }

    return 0;
}
