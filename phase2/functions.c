#include <stdio.h>
#include <stdlib.h> 
#include "function_def.h"

char names[MAX_STUDENTS][MAX_NAME_LENGTH];
int rollNumbers[MAX_STUDENTS];
int marks[MAX_STUDENTS][5]; // Marks in 5 subjects
int numStudents = 0; 

// array of student structs
Student *students;
//int numStudents = 0;

void addStudent() {
    if (numStudents >= MAX_STUDENTS) {
        printf("Maximum number of students reached\n");
        return;
    }

    //allocating memory for a new Student struct
    students[numStudents].marks = (int *)malloc(5 * sizeof(int));
    if (students[numStudents].marks == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter name of student: ");
    scanf("%s", students[numStudents].name);
    printf("Enter roll number: ");
    scanf("%d", &students[numStudents].rollNumber);
    printf("Enter marks in 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &students[numStudents].marks[i]);
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
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks in 5 subjects: ");
        for (int j = 0; j < 5; j++) {
            printf("%d ", students[i].marks[j]);
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
        if (students[i].rollNumber == rollToDelete) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        printf("Student with roll number %d not found!\n", rollToDelete);
    } else {
        free(students[indexToDelete].marks); // Free dynamically allocated memory
        for (int i = indexToDelete; i < numStudents - 1; i++) {
            students[i] = students[i + 1];
        }
        numStudents--;
        printf("Student with roll number %d deleted successfully!\n", rollToDelete);
    }
}

void displayStudentGrade() {
    int rollNumber;
    printf("Enter roll number of the student: ");
    scanf("%d", &rollNumber);

    int index = -1;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Student with roll number %d not found!\n", rollNumber);
        return;
    }
    char grades[5]; // Array to store grades for each subject

    for (int i = 0; i < 5; i++) {
        if (students[index].marks[i] >= 90) {
            grades[i] = 'S';
        } else if (students[index].marks[i] >= 80) {
            grades[i] = 'A';
        } else if (students[index].marks[i] >= 70) {
            grades[i] = 'B';
        } else if (students[index].marks[i] >= 60) {
            grades[i] = 'C';
        } else if (students[index].marks[i] >= 50) {
            grades[i] = 'D';
        } else if (students[index].marks[i] >= 40) {
            grades[i] = 'E';
        } else {
            grades[i] = 'F';
        }
    }
    printf("Grades for student with roll number %d:\n", rollNumber);
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: %c\n", i + 1, grades[i]);
    }
}
