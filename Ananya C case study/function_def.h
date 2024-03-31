//DEFINING HEADER FILE 

#ifndef FUNCTION_DEF_H
#define FUNCTION_DEF_H
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

extern char names[MAX_STUDENTS][MAX_NAME_LENGTH];
extern int rollNumbers[MAX_STUDENTS];
extern int marks[MAX_STUDENTS][5];
extern int numStudents;


void addStudent();
void displayStudentInfo();
void deleteStudent();
void displayGrade(int studentIndex);

#endif

