//DEFINING HEADER FILE 

#ifndef FUNCTION_DEF_H
#define FUNCTION_DEF_H

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int rollNumber;
    int marks[5];
} Student;

extern int numStudents;
extern Student *students;

void addStudent();
void displayStudentInfo(int rollNumberToDisplay);
void deleteStudent();
void displayStudentGrade(int rollNumberToDisplay);

#endif






/*
#ifndef FUNCTION_DEF_H
#define FUNCTION_DEF_H

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_LINE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int rollNumber;
    int *marks; 
} Student;

extern char names[MAX_STUDENTS][MAX_NAME_LENGTH];
extern int rollNumbers[MAX_STUDENTS];
extern int marks[MAX_STUDENTS][5];
extern int numStudents;

extern Student *students; // Array of Student structs

void addStudent();
void displayStudentInfo();
void deleteStudent();
void displayStudentGrade();

#endif 
*/