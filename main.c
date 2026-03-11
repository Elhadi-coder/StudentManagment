
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "Student.h"

int main()
{
    // fors : Failed Or Secssful
    int choice;
    system("cls ");

    printf("*********************************************\n");
    printf("*       Welcome to Student Management System       *\n");
    printf("*              Developed by Mohamed             *\n");
    printf("*********************************************\n");
    printf("\nPress Enter to continue...");
    getchar();
    system("cls ");
    do
    {

        PrintMenu();

        choice = GetChoice();

        ExecuteChoice(choice);

    } while (choice != 0);
    printf("Thank you for using the Student Management System. Goodbye!\n");
    return 0;
}
