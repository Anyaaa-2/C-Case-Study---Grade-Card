#include <stdio.h>
#include "function_def.h"

int main() {
    int n;
    int rollToDisplay; 
    while (1) {
        printf("\nGrade Card Calculator\n");
        printf("1. Add a student\n");
        printf("2. Display student info\n");
        printf("3. Display grade of a student\n"); 
        printf("4. Delete a student\n");
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
              
                printf("Enter the roll number of the student: ");
                scanf("%d", &rollToDisplay);
                
                int indexToDisplay = -1;
                for (int i = 0; i < numStudents; i++) {
                    if (rollNumbers[i] == rollToDisplay) {
                        indexToDisplay = i;
                        break;
                    }
                }
                if (indexToDisplay == -1) {
                    printf("Student with roll number %d not found!\n", rollToDisplay);
                } else {
                    displayGrade(indexToDisplay); 
                }
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}






