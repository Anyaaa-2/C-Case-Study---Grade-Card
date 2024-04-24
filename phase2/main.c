#include <stdio.h>
#include <stdlib.h>
#include "function_def.h"


int main() {
    students = (Student *)malloc(MAX_STUDENTS * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int n;
    while(1) {
        printf("\nGrade Card Calculator\n");
        printf("1. Add a student\n");
        printf("2. Display student info\n");
        printf("3. Delete a student\n");
        printf("4. Display student grade\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudentInfo();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                displayStudentGrade();
                break;
            case 5:
                printf("Exiting\n");
                free(students);
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

       
