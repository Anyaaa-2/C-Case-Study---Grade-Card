#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function_def.h"

int numStudents = 0;
Student *students;

#define FILENAME "student_data.txt"

void initializeStudents() {
    students = (Student *)malloc(MAX_STUDENTS * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    FILE *file = fopen(FILENAME, "r");
    if (file != NULL) {
        while (fscanf(file, "%s %d %d %d %d %d %d", students[numStudents].name, 
                      &students[numStudents].rollNumber, 
                      &students[numStudents].marks[0], 
                      &students[numStudents].marks[1], 
                      &students[numStudents].marks[2], 
                      &students[numStudents].marks[3], 
                      &students[numStudents].marks[4]) != EOF) {
            numStudents++;
        }
        fclose(file);
    }
}

//to add student info to a text file
void addStudent() {
    if (numStudents >= MAX_STUDENTS) {
        printf("Maximum number of students reached\n");
        return;
    }

    // Getting student data
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

    // Writing the student's data to text file
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return;
    }
    fprintf(file, "%s %d", students[numStudents - 1].name, students[numStudents - 1].rollNumber);
    for (int i = 0; i < 5; i++) {
        fprintf(file, " %d", students[numStudents - 1].marks[i]);
    }
    fprintf(file, "\n");
    fclose(file);

    printf("Student added successfully!\n");
}

//to search from file and display student info 
void displayStudentInfo(int rollNumberToDisplay) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file for reading\n");
        return;
    }
    char name[MAX_NAME_LENGTH];
    int rollNumber;
    int marks[5];
    int found = 0;
    while (fscanf(file, "%s %d %d %d %d %d %d", name, &rollNumber, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]) != EOF) {
        if (rollNumber == rollNumberToDisplay) {
            printf("Name: %s, Roll Number: %d, Marks: %d %d %d %d %d\n", name, rollNumber, marks[0], marks[1], marks[2], marks[3], marks[4]);
            found = 1;
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumberToDisplay);
    }
}

//to delete student info from the text file
void deleteStudent() {
    int rollToDelete;
    printf("Enter the roll number of the student to delete: ");
    scanf("%d", &rollToDelete);

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No students in the records!\n");
        return;
    }

    int found = 0;
    char tempFilename[] = "temp_data.txt";
    FILE *tempFile = fopen(tempFilename, "w");
    if (tempFile == NULL) {
        printf("Error opening temporary file for writing\n");
        fclose(file);
        return;
    }

    char name[MAX_NAME_LENGTH];
    int rollNumber, marks[5];

    while (fscanf(file, "%s %d %d %d %d %d %d", 
                  name, &rollNumber, &marks[0], &marks[1], 
                  &marks[2], &marks[3], &marks[4]) != EOF) {
        if (rollNumber == rollToDelete) {
            found = 1;
        } else {
            fprintf(tempFile, "%s %d %d %d %d %d %d\n", 
                    name, rollNumber, marks[0], marks[1], 
                    marks[2], marks[3], marks[4]);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILENAME);
        rename(tempFilename, FILENAME);
        printf("Student with roll number %d deleted successfully!\n", rollToDelete);
        numStudents--;
    } else {
        printf("Student with roll number %d not found!\n", rollToDelete);
        remove(tempFilename);
    }
}

void displayStudentGrade(int rollNumberToDisplay) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file for reading\n");
        return;
    }
    char name[MAX_NAME_LENGTH];
    int rollNumber;
    int marks[5];
    int found = 0;
    while (fscanf(file, "%s %d %d %d %d %d %d", name, &rollNumber, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]) != EOF) {
        if (rollNumber == rollNumberToDisplay) {
            char grades[5];
            for (int i = 0; i < 5; i++) {
                if (marks[i] >= 90) {
                    grades[i] = 'S';
                } else if (marks[i] >= 80) {
                    grades[i] = 'A';
                } else if (marks[i] >= 70) {
                    grades[i] = 'B';
                } else if (marks[i] >= 60) {
                    grades[i] = 'C';
                } else if (marks[i] >= 50) {
                    grades[i] = 'D';
                } else if (marks[i] >= 40) {
                    grades[i] = 'E';
                } else {
                    grades[i] = 'F';
                }
            }
            printf("Grades for student with roll number %d:\n", rollNumber);
            for (int i = 0; i < 5; i++) {
                printf("Subject %d: %c\n", i + 1, grades[i]);
            }
            found = 1;
            break;
        }
    }
    fclose(file);
    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumberToDisplay);
    }
}




