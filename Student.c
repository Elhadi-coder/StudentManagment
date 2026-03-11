
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include "Student.h"

int GetChoice()
{
    int choice;

    printf("Enter your choice (0 - 9): ");

    do
    {
        scanf("%d", &choice);
        while (getchar() != '\n')
            ;

        printf("\033[F");
        printf("\033[K");

        if (choice < 0 || choice > 9)
        {
            printf("Invalid choice! Please enter a number between 0 and 9: ");
        }

    } while (choice < 0 || choice > 9);

    printf("-------------------------------------------\n");
    printf("\nPress Enter to continue...");
    getchar();
    system("CLS");
    printf("-------------------------------------------\n");

    return choice;
}

void ExecuteChoice(int choice)
{
    int ID;

    switch (choice)
    {
    case 1:
        AddStudent();
        break;

    case 2:
        PrintAllStudent();
        break;

    case 3:
        TheGoatStudentInfo();
        break;

    case 4:
        printf("Give Me The Student Id : ");
        scanf("%d", &ID);
        while (getchar() != '\n')
            ; // تنظيف الـ buffer
        SearchStudentWithID(ID);
        break;

    case 5:
        printf("Give Me The Student Id : ");
        scanf("%d", &ID);
        while (getchar() != '\n')
            ;
        DeleteStudentByID(ID);
        break;

    case 6:
        CountStudents();
        break;

    case 7:
        PrintFoesAverage(1);
        break;

    case 8:
        PrintFoesAverage(0);
        break;

    case 9:
        DeleteCurrentList();
        break;
    }
}

void PrintMenu()
{
    printf("*********************************************\n");
    printf("*            STUDENT MANAGEMENT SYSTEM     *\n");
    printf("*********************************************\n");
    printf("* 1. Add a New Student                      *\n");
    printf("* 2. Print All Students                     *\n");
    printf("* 3. Print Students by Major                *\n");
    printf("* 4. Search for a Student by ID             *\n");
    printf("* 5. Delete a Student by ID                 *\n");
    printf("* 6. Count Total Students                   *\n");
    printf("* 7. Show Successful Students               *\n");
    printf("* 8. Show Failed Students                   *\n");
    printf("* 9. Start a New List (Delete Current Data) *\n");
    printf("* 0. Exit Program                           *\n");
    printf("*********************************************\n");
}

int CheckID(int ID)
{

    Student st;

    char Line[300];

    FILE *f;

    f = fopen("Bankey.txt", "r");

    if (f == NULL)
    {

        printf("File Not Found \n");
        return 0;
    }

    while (fgets(Line, sizeof(Line), f) != NULL)

    {
        Line[strcspn(Line, "\n")] = '\0';
        if (sscanf(Line, "%[^|]|%[^|]|%d|%f|%f|%f|%f|%d", st.Fname, st.Lname, &st.Age, &st.Mark[0], &st.Mark[1], &st.Mark[2], &st.Average, &st.Id) == 8)

        {

            if (st.Id == ID)
            {
                fclose(f);
                return 1;
            }
        }
    }

    fclose(f);

    return 0;
}

void AddStudent()
{
    int i;
    Student st;
    st.Average = 0;
    FILE *f;
    f = fopen("Bankey.txt", "a");

    if (f == NULL)
    {
        printf("File Not Found ");
        return;
    }

    ;
    printf("The %d Student (New Student) :\n", CountStudent1());

    printf("Give ME The Student First Name :");

    fgets(st.Fname, sizeof(st.Fname), stdin);

    printf("\033[F");
    printf("\033[K");

    printf("Give ME The Student Last Name :");

    fgets(st.Lname, sizeof(st.Lname), stdin);

    printf("\033[F");
    printf("\033[K");

    st.Fname[strcspn(st.Fname, "\n")] = '\0';

    st.Lname[strcspn(st.Lname, "\n")] = '\0';

    printf("Give Me The Student Age :");

    scanf("%d", &st.Age);

    printf("\033[F");
    printf("\033[K");

    do
    {

        printf("Give Me The Student ID (Privet ID For All Student):");
        scanf("%d", &st.Id);
        system("cls ");
        printf("\033[F");
        printf("\033[K");
        if (CheckID(st.Id) == 1)
        {
            printf("Error: ID already exists. Enter a different ID.\n");
        }

    } while (CheckID(st.Id) == 1);

    printf("Give Me The Student Marks (A Mark Between 0 and 20 ): \n");

    for (i = 0; i < 3; i++)
    {
        do
        {

            printf("The %d Mark :", i + 1);

            scanf("%f", &st.Mark[i]);

            printf("\033[F");
            printf("\033[K");

        } while (st.Mark[i] < 0 || st.Mark[i] > 20);
    }
    fprintf(f, "%s|%s|%d|", st.Fname, st.Lname, st.Age);

    for (i = 0; i < 3; i++)
    {
        fprintf(f, "%.2f|", st.Mark[i]);
        st.Average += st.Mark[i];
    }

    fprintf(f, "%.2f|%d|\n", st.Average / 3, st.Id);
    fclose(f);
}

void PrintAllStudent()

{

    int i, Counter = 1;

    Student st;

    char Line[300];

    FILE *f;

    f = fopen("Bankey.txt", "r");

    if (f == NULL)

    {

        printf("File Not Found \n");
        return;
    }

    while (fgets(Line, sizeof(Line), f) != NULL)
    {

        Line[strcspn(Line, "\n")] = '\0';

        if (sscanf(Line, "%[^|]|%[^|]|%d|%f|%f|%f|%f|%d", st.Fname, st.Lname, &st.Age, &st.Mark[0], &st.Mark[1], &st.Mark[2], &st.Average, &st.Id) == 8)

        {
            printf("-The %d Student : ************************** \n", Counter);
            printf(" ******************************************* \n");
            printf("|The First Name :%s                              \n", st.Fname);
            printf("|The Last name :%s                              \n", st.Lname);
            printf("|The Age :%d                                \n", st.Age);

            for (i = 0; i < 3; i++)

            {

                printf("|The %d Mark : %.2f                         \n", i + 1, st.Mark[i]);
            }

            printf("|The Average Is :%.2f                       \n", st.Average);

            printf("|The Id :%d                                 \n", st.Id);
            printf(" ******************************************* \n\n\n");
            Counter++;
            printf(" ******************************************* \n");
        }
        else
        {
            printf(" Failed to read student data on line: %s\n", Line);
        }
    }

    fclose(f);
}

void SearchStudentWithID(int ID)
{

    int i;

    Student st;

    char Line[300];

    FILE *f;

    f = fopen("Bankey.txt", "r");

    if (f == NULL)

    {

        printf("File Not Found \n");

        return;
    }

    while (fgets(Line, sizeof(Line), f) != NULL)

    {
        Line[strcspn(Line, "\n")] = '\0';

        if (sscanf(Line, "%[^|]|%[^|]|%d|%f|%f|%f|%f|%d", st.Fname, st.Lname, &st.Age, &st.Mark[0], &st.Mark[1], &st.Mark[2], &st.Average, &st.Id) == 8)
        {

            if (ID == st.Id)

            {
                printf(" ******************************************* \n");
                printf("|The First Name :%s                              \n", st.Fname);
                printf("|The Last name :%s                              \n", st.Lname);
                printf("|The Age :%d                                \n", st.Age);

                for (i = 0; i < 3; i++)

                {

                    printf("|The %d Mark : %.2f                         \n", i + 1, st.Mark[i]);
                }

                printf("|The Average Is :%.2f                       \n", st.Average);

                printf("|The Id :%d                                 \n", st.Id);
                printf(" ******************************************* \n\n\n");
                printf(" ******************************************* \n");

                fclose(f);

                return;
            }
        }
    }

    fclose(f);

    printf("No student found with ID %d.\n", ID);
}

void TheGoatStudentInfo()
{

    float TheHighestMark = 0;

    int SaveID = -3;

    Student st;

    char Line[300];

    FILE *f;

    f = fopen("Bankey.txt", "r");

    if (f == NULL)

    {

        printf("File Not Found \n");

        return;
    }

    while (fgets(Line, sizeof(Line), f) != NULL)

    {
        if (sscanf(Line, "%[^|]|%[^|]|%d|%f|%f|%f|%f|%d", st.Fname, st.Lname, &st.Age, &st.Mark[0], &st.Mark[1], &st.Mark[2], &st.Average, &st.Id) == 8)
        {

            if (TheHighestMark < st.Average)

            {

                TheHighestMark = st.Average;

                SaveID = st.Id;
            }
        }
    }
    if (SaveID == -3)
    {
        printf("No student data found.\n");
        return;
    }
    fclose(f);
    printf(" ******************************************* \n");
    printf("  * The Major Student Info :            **** \n");
    printf(" ******************************************* \n");

    SearchStudentWithID(SaveID);
}

void DeleteStudentByID(int ID)
{
    int found = 0;
    Student st;

    char Line[300];

    FILE *f, *Shamplz;

    f = fopen("Bankey.txt", "r");

    if (f == NULL)

    {

        printf("File Not Found \n");

        return;
    }

    Shamplz = fopen("save.txt", "w");

    if (Shamplz == NULL)

    {
        fclose(f);
        printf("File Not Found \n");

        return;
    }

    while (fgets(Line, sizeof(Line), f) != NULL)

    {
        Line[strcspn(Line, "\n")] = '\0';

        if (sscanf(Line, "%[^|]|%[^|]|%d|%f|%f|%f|%f|%d", st.Fname, st.Lname, &st.Age, &st.Mark[0], &st.Mark[1], &st.Mark[2], &st.Average, &st.Id) == 8)
        {

            if (st.Id == ID)

            {
                found = 1;
                continue;
            }

            fprintf(Shamplz, "%s\n", Line);
        }
    }

    fclose(f);

    fclose(Shamplz);

    remove("Bankey.txt");

    rename("save.txt", "Bankey.txt");

    if (found)
        printf("Student Deleted Successfully.\n");
    else
        printf("No student found with ID %d.\n", ID);
}

void CountStudents()
{
    FILE *f;
    int Count = 0;
    char Line[200];
    f = fopen("Bankey.txt", "r");
    if (f == NULL)
    {

        printf("File Not Found \n");
        return;
    }
    while (fgets(Line, sizeof(Line), f) != NULL)
    {
        Count++;
    }
    fclose(f);

    if (Count == 0)
        printf("No students found in the file.\n");
    else
        printf("We have %d student(s).\n", Count);
    printf("----------------------------------------\n");
}

int CountStudent1()
{
    FILE *f;
    int Count = 1;
    char Line[200];
    f = fopen("Bankey.txt", "r");
    if (f == NULL)
    {
        printf("File not found.\n");
        return -1;
    }
    while (fgets(Line, sizeof(Line), f) != NULL)
    {
        Count++;
    }
    fclose(f);
    return Count;
}

// fors : Failed Or Secssful
// fors : Failed Or Secssful
void PrintFoesAverage(int fors)
{
    int i;
    Student st;
    char Line[300];
    FILE *f;
    f = fopen("Bankey.txt", "r");
    if (f == NULL)
    {
        printf("File Not Found \n");
        return;
    }
    while (fgets(Line, sizeof(Line), f) != NULL)
    {
        if (sscanf(Line, "%[^|]|%[^|]|%d|%f|%f|%f|%f|%d", st.Fname, st.Lname, &st.Age, &st.Mark[0], &st.Mark[1], &st.Mark[2], &st.Average, &st.Id) == 8)
        {
            if (st.Average >= 10 && fors == 1)
            {
                printf("The FName :%s\nThe Lname %s  \nThe Age :%d \n", st.Fname, st.Lname, st.Age);
                for (i = 0; i < 3; i++)
                {
                    printf("The %d Mark : %.2f\n", i + 1, st.Mark[i]);
                }
                printf("The Average Is :%.2f\n", st.Average);
                printf("The Id :%d\n", st.Id);
            }

            else if (st.Average < 10 && fors == 0)
            {
                printf("The FName :%s\nThe Lname %s  \nThe Age :%d \n", st.Fname, st.Lname, st.Age);
                for (i = 0; i < 3; i++)
                {
                    printf("The %d Mark : %.2f\n", i + 1, st.Mark[i]);
                }
                printf("The Average Is :%.2f\n", st.Average);
                printf("The Id :%d\n", st.Id);
            }
        }
        printf("----------------------------\n");
    }

    fclose(f);
}

void DeleteCurrentList()
{

    char confirm;
    printf("Are you sure you want to delete all students? ( y (yes) / n (No)): ");
    scanf(" %c", &confirm);
    while (getchar() != '\n')
        ;

    if (confirm != 'y' && confirm != 'Y')
    {
        return;
    }

    FILE *f;
    f = fopen("Bankey.txt", "w");
    if (f == NULL)
    {
        printf("File Not Found \n");
        return;
    }
    fclose(f);
    printf("All students deleted successfully.\n");
    Sleep(1000);
    AddStudent();
}