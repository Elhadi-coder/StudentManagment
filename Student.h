#ifndef STUDENT_H
#define STUDENT_H

typedef struct
{
    char Fname[100], Lname[100];
    int Age, Id;
    float Mark[3], Average;
} Student;

int GetChoice();
void ExecuteChoice(int choice);
void PrintMenu();
int CountStudent1();
int CheckID(int ID);
void AddStudent();
void PrintAllStudent();
void TheGoatStudentInfo();
void SearchStudentWithID(int ID);
void DeleteStudentByID(int ID);
void CountStudents();
void PrintFoesAverage(int foas);
void DeleteCurrentList();

#endif