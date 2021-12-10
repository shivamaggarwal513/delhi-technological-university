/* Class */
#include <iostream>
using namespace std;

class student
{
private:
    int roll;
    char name[10];
    char grade;
public:
    void update();
    void display();
};

void student::update()
{
    cout << "\t Roll No.: "; cin >> roll;
    cout << "\t Name: ";     cin >> name;
    cout << "\t Grade: ";    cin >> grade;
    cout << "----------------------- \n";
}

void student::display()
{
    cout << roll << "\t"
        << name << "\t"
        << grade << "\n";
}

int main()
{
    student arr[3];
    cout << "Enter student details \n";
    for (int i = 0; i < 3; i++)
        arr[i].update();
    cout << "Roll \tName \tGrade \n";
    for (int i = 0; i < 3; i++)
        arr[i].display();
    return 0;
}