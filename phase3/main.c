#include <stdio.h>
#include <stdlib.h>
#include "function_def.h"
#include "functions.c"

int main() {
    initializeStudents();

    int choice, roll;
    while(1) {
        printf("\nGrade Card Calculator\n");
        printf("1. Add a student\n");
        printf("2. Display student info\n");
        printf("3. Delete a student\n");
        printf("4. Display student grade\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                printf("Enter roll no: ");
                scanf("%d", &roll);
                displayStudentInfo(roll);
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                printf("Enter roll no: ");
                scanf("%d", &roll);
                displayStudentGrade(roll);
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

