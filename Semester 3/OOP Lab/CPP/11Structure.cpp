/* Structure */
#include <iostream>
using namespace std;

typedef struct student
{
    int roll;
    char name[10];
    char grade;
} student;

int main()
{
    student arr[3];
    cout << "Enter student details \n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\t Roll: ";  cin >> arr[i].roll;
        cout << "\t Name: ";  cin >> arr[i].name;
        cout << "\t Grade: "; cin >> arr[i].grade;
        cout << "----------------------- \n";
    }
    cout << "Roll \tName \tGrade \n";
    for (int i = 0; i < 3; i++)
        cout << arr[i].roll << "\t"
        << arr[i].name << "\t"
        << arr[i].grade << "\n";
    return 0;
}