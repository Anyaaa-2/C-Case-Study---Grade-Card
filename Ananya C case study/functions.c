
#include <stdio.h>
#include "function_def.h"

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

char names[MAX_STUDENTS][MAX_NAME_LENGTH];
int rollNumbers[MAX_STUDENTS];
int marks[MAX_STUDENTS][5]; // Marks in 5 subjects
int numStudents = 0; 

void addStudent() {
    if (numStudents >= MAX_STUDENTS) {
        printf("Maximum number of students reached!\n");
        return;
    }

    printf("Enter name of student: ");
    scanf("%s", names[numStudents]);
    printf("Enter roll number: ");
    scanf("%d", &rollNumbers[numStudents]);
    printf("Enter marks in 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &marks[numStudents][i]);
    }
    
    numStudents++;
    printf("Student added successfully!\n");
}

void displayStudentInfo() {
    if (numStudents == 0) {
        printf("No students in the records!\n");
        return;
    }

    printf("Student Info:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s\n", names[i]);
        printf("Roll Number: %d\n", rollNumbers[i]);
        printf("Marks in 5 subjects: ");
        for (int j = 0; j < 5; j++) {
            printf("%d ", marks[i][j]);
        }
        printf("\n");
    }
}

void deleteStudent() {
    if (numStudents == 0) {
        printf("No students in the records!\n");
        return;
    }

    int rollToDelete;
    printf("Enter the roll number of the student to delete: ");
    scanf("%d", &rollToDelete);

    int indexToDelete = -1;
    for (int i = 0; i < numStudents; i++) {
        if (rollNumbers[i] == rollToDelete) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        printf("Student with roll number %d not found!\n", rollToDelete);
    } else {
        for (int i = indexToDelete; i < numStudents - 1; i++) {
            rollNumbers[i] = rollNumbers[i + 1];
            for (int j = 0; j < 5; j++) {
                marks[i][j] = marks[i + 1][j];
            }
        }
        numStudents--;
        printf("Student with roll number %d deleted successfully!\n", rollToDelete);
    }
}

void displayGrade(int studentIndex) {
    // Calculate total marks
    int totalMarks = 0;
    for (int i = 0; i < 5; i++) {
        totalMarks += marks[studentIndex][i];
    }

    // Calculate grade
    char grade;
    float percentage = (float)totalMarks / 500 * 100;
    if (percentage >= 90) {
        grade = 'S';
    } else if (percentage >= 80) {
        grade = 'A';
    } else if (percentage >= 70) {
        grade = 'B';
    } else if (percentage >= 60) {
        grade = 'C';
    } else if (percentage >= 50) {
        grade = 'D';
    } else if (percentage >= 40) {
        grade = 'E';
    } else {
        grade = 'F';
    }

    printf("Grade: %c\n", grade);
}


