#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <cmath>
#include <windows.h>
using namespace std;
struct StudentMarks
{
    string subject;
    int marks;
    StudentMarks *next = NULL;
};
struct Student
{
    string Name;
    Student *next = NULL;
    StudentMarks *MarksHead = NULL;
};
Student *Head = NULL;
Student *ChkName(string Name, bool &flag)
{
    Student *temp = Head;
    while (1)
    {
        if (temp->Name == Name)
        {
            flag = 1;
            return temp;
        }
        if (temp->next == NULL)
            break;
        temp = temp->next;
    }
    flag = 0;
    return NULL;
}
StudentMarks *getLastMarksRecord(StudentMarks *temp)
{
    while (temp->next != NULL)
        temp = temp->next;
    return temp;
}
Student *getlastStudent(Student *temp)
{
    while (temp->next != NULL)
        temp = temp->next;
    return temp;
}
void AddStudentMarksInList(Student *temp, string Subject, int marks)
{
    StudentMarks *Record = new StudentMarks;
    Record->subject = Subject;
    Record->marks = marks;
    if (temp->MarksHead == NULL)
        temp->MarksHead = Record;
    else
    {
        StudentMarks *tempMarks = getLastMarksRecord(temp->MarksHead);
        tempMarks->next = Record;
    }
}
void AddDataInStudentList(string name, string subject, int marks)
{
    Student *Record = new Student;
    Record->Name = name;
    AddStudentMarksInList(Record, subject, marks);
    if (Head == NULL)
        Head = Record;
    else
    {
        Student *temp = getlastStudent(Head);
        temp->next = Record;
    }
}
void TakeDataFromUser()
{
    string name;
    string subject;
    int marks;
    cout << "Enter Student Name : ";
    cin >> name;
    cout << "Enter Student Subject : ";
    cin >> subject;
    cout << "Enter Student Marks : ";
    cin >> marks;
    bool NameExits = 0;
    Student *temp;
    if (Head != NULL)
    {
        temp = ChkName(name, NameExits);
    }
    if (!NameExits)
    {
        AddDataInStudentList(name, subject, marks);
    }
    else
    {
        AddStudentMarksInList(temp, subject, marks);
    }
}
void gotoxy(int x, int y)
{
    COORD cursorPosition;
    cursorPosition.X = x;
    cursorPosition.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
void DisplayData()
{
    int x = 0;
    int y = 0;
    Student *temp = Head;
    while (1)
    {
        gotoxy(x, y);
        StudentMarks *marktemp = temp->MarksHead;
        cout << temp->Name;
        x += 10;
        gotoxy(x, y);

        // x += 3;
        while (1)
        {
            cout << "-> ";
            x += 3;
            cout << marktemp->subject;
            gotoxy(x, y + 1);
            cout << marktemp->marks;
            x += 10;
            gotoxy(x, y);
            // cout << "-> ";
            if (marktemp->next == NULL)
                break;
            marktemp = marktemp->next;
        }
        if (temp->next == NULL)
            break;
        temp = temp->next;
        y += 3;
        x = 0;
        cout << endl;
    }
}
int main()
{
    system("cls");
    while (1)
    {
        gotoxy(0, 20);
        TakeDataFromUser();
        system("cls");
        gotoxy(0, 0);
        DisplayData();
    }

} //..End of main