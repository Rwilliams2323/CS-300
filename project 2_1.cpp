// Project Two – ABCU Advising Assistant
// Author: Ronald Williams
// SNHU – CS 300

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Course structure to hold course details
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Global hash table to store course objects
unordered_map<string, Course> courseTable;

// Function to split a string by delimiter
vector<string> Split(const string& line, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(line);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to load course data into the hash table
void LoadData(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error: Could not open file " << fileName << endl;
        return;
    }

    courseTable.clear();

    string line;
    while (getline(file, line)) {
        vector<string> tokens = Split(line, ',');

        if (tokens.size() < 2) {
            cout << "Skipping invalid line: " << line << endl;
            continue;
        }

        Course course;
        course.courseNumber = tokens[0];
        course.courseTitle = tokens[1];

        for (size_t i = 2; i < tokens.size(); ++i) {
            course.prerequisites.push_back(tokens[i]);
        }

        courseTable[course.courseNumber] = course;
    }

    file.close();
    cout << "Courses loaded successfully.\n";
}

// Function to print all courses in alphanumeric order
void PrintAllCourses() {
    if (courseTable.empty()) {
        cout << "No courses loaded.\n";
        return;
    }

    vector<string> courseNumbers;
    for (const auto& pair : courseTable) {
        courseNumbers.push_back(pair.first);
    }

    sort(courseNumbers.begin(), courseNumbers.end());

    for (const string& number : courseNumbers) {
        cout << number << ": " << courseTable[number].courseTitle << endl;
    }
}

// Function to print details of a specific course
void PrintCourseDetails(const string& courseNumber) {
    if (courseTable.find(courseNumber) == courseTable.end()) {
        cout << "Course not found: " << courseNumber << endl;
        return;
    }

    Course course = courseTable[courseNumber];
    cout << course.courseNumber << ": " << course.courseTitle << endl;

    if (course.prerequisites.empty()) {
        cout << "Prerequisites: None" << endl;
    }
    else {
        cout << "Prerequisites: ";
        for (size_t i = 0; i < course.prerequisites.size(); ++i) {
            cout << course.prerequisites[i];
            if (i < course.prerequisites.size() - 1) cout << ", ";
        }
        cout << endl;
    }
}

// Display menu and handle user input
void ShowMenu() {
    int choice;
    string fileName;
    string courseNumber;

    do {
        cout << "\nMenu Options:\n";
        cout << "1. Load Data Structure\n";
        cout << "2. Print Course List\n";
        cout << "3. Print Course\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline

        switch (choice) {
        case 1:
            cout << "Enter file name: ";
            getline(cin, fileName);
            LoadData(fileName);
            break;
        case 2:
            PrintAllCourses();
            break;
        case 3:
            cout << "Enter course number: ";
            getline(cin, courseNumber);
            PrintCourseDetails(courseNumber);
            break;
        case 9:
            cout << "Goodbye.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 9);
}

int main() {
    ShowMenu();
    return 0;
}
