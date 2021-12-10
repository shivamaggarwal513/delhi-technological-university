/* Member functions */
#include <iostream>
using namespace std;

class employee
{
private:
    int number;
    char name[15];
    float basic, DA, IT, grossSalary, netSalary;

public:
    void updateDetails();
    void displayDetails();
    float findNetSalary();
};

void employee::updateDetails()
{
    cout << "\t Number: "; cin >> number;
    cout << "\t Name: ";   cin >> name;
    cout << "\t Basic: ";  cin >> basic;
    cout << "--------------------- \n";
}

void employee::displayDetails()
{
    cout << number << "\t"
        << name << "\t"
        << basic << "\t"
        << DA << "\t"
        << IT << "\t"
        << grossSalary << "\t"
        << netSalary << "\n";
}

float employee::findNetSalary()
{
    DA = 0.52 * basic;
    grossSalary = basic + DA;
    IT = 0.3 * grossSalary;
    netSalary = basic + DA - IT;
    return netSalary;
}

int main()
{
    int n;
    cout << "Enter no. of employees: "; cin >> n;
    employee* E = new employee[n];
    cout << "Enter employee details \n";
    for (int i = 0; i < n; i++)
    {
        (E + i)->updateDetails();
        (E + i)->findNetSalary();
    }
    cout << "Number \tName \tBasic \tDA \tIT \tGross \tNet Salary \n"
        << "---------------------------------------------------------- \n";
    for (int i = 0; i < n; i++)
        (E + i)->displayDetails();
    return 0;
}