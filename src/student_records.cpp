#include "student_records.hpp"
#include <iostream>

using namespace std;

bool isValidArray(const Student students[], int size) {
   if (students == nullptr) {
    return false;
   }
   if ((size > 0) && (size <= 3)) {
    return true;
   }
    return false;
}

bool isValidStudentId(string id) {
    // TODO:
    // A valid ID should have at least 3 characters.
    // A valid ID should start with an uppercase letter.
    // Hint: You may compare characters directly, such as id[0] >= 'A'.
    
    // If an ID has less than 3 characters, false
    // If it starts with an uppercase, false
    // Because ASCII codes, we can check if the first letter is < or > than A and Z
    // then check the length
    char idFirst = id[0];
    if ((id.length() >= 3) && ('A' <= idFirst) && ( idFirst <= 'Z')) {
        return true;
    }
    return false;
}

bool isValidScore(double score) {
    // TODO: Return true when score is between 0 and 100, inclusive.
    if ((0 <= score) && (score <= 100)) {
        return true;
    }
    return false;
}

void printStudent(const Student& student) {
    cout << student.id << " "
         << student.name << " "
         << student.score << " "
         << determineLetterGrade(student.score)
         << endl;
}

void printStudents(const Student students[], int size) {
    if (students == nullptr || size <= 0) {
        cout << "No students to print." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        printStudent(students[i]);
    }
}

double calculateAverageScore(const Student students[], int size) {
    // TODO:
    // If the array is null or size is invalid, return 0.0.
    // Otherwise, return the average score.
    if (isValidArray(students, size)) {
        double total = 0;
        int count = 0;
        for (int i = 0; i < size; i ++) {
            count ++;
            total += students[i].score;
        }
        return total/count;
    }
    return 0.0;
}

double findHighestScore(const Student students[], int size) {
    // TODO:
    // If the array is null or size is invalid, return 0.0.
    // Otherwise, return the highest score.
    if (isValidArray(students, size)) {
        double highestSoFar = 0;
        for (int i = 0; i < size; i ++) {
            if (students[i].score >= highestSoFar) {
                highestSoFar = students[i].score;
            }
        }
        return highestSoFar;
    }
    return 0.0;
}

int findStudentById(const Student students[], int size, string targetId) {
    // TODO:
    // Search by comparing students[i].id to targetId.
    // Return the index of the matching student.
    // Return -1 if no student is found.
    int index = -1;
    if (isValidArray(students, size)) {
        
        for (int i = 0; i < size; i ++) {
            if (students[i].id == targetId) {
                index = i;
            }
        }    
    }
    return index;
}



char determineLetterGrade(double score) {
    // TODO:
    // Return 'A' for scores 90 or higher.
    // Return 'B' for scores 80 or higher.
    // Return 'C' for scores 70 or higher.
    // Return 'D' for scores 60 or higher.
    // Return 'F' otherwise.
    if (score >= 90) {
        return 'A';
    }
    else if (score >= 80) {
        return 'B';
    }
    else if (score >= 70) {
        return 'C';
    }
    else if (score >= 60) {
        return 'D';
    }
    return 'F';
}
