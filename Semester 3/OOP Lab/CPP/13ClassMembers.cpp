/* Class members */
#include <iostream>
using namespace std;

class employee
{
private:
    int number;
    char name[15];
    float basic, DA, IT, netSalary;

public:
    void updateDetails();
    void displayDetails();
    float findNetSalary(float basic, float DA, float IT);
};

void employee::updateDetails()
{
    cout << "\t Number: ";             cin >> number;
    cout << "\t Name: ";               cin >> name;
    cout << "\t Basic: ";              cin >> basic;
    cout << "\t Dearness Allowance: "; cin >> DA;
    cout << "\t Income Tax: ";         cin >> IT;
    cout << "---------------------------------- \n";
}

void employee::displayDetails()
{
    cout << "\n Employee Details \n"
        << "\t Number             : " << number << "\n"
        << "\t Name               : " << name << "\n"
        << "\t Basic              : " << basic << "\n"
        << "\t Dearness Allowance : " << DA << "\n"
        << "\t Income Tax         : " << IT << "\n"
        << "\t Net Salary         : " << findNetSalary(basic, DA, IT) << "\n";
}

float employee::findNetSalary(float basic, float DA, float IT)
{
    netSalary = basic + DA - IT;
    return netSalary;
}

int main()
{
    employee E;
    cout << "Enter employee details \n";
    E.updateDetails();
    E.displayDetails();
    return 0;
}