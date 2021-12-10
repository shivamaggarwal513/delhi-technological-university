/* Derived class constructors */
#include <iostream>
#include <string>
using namespace std;

/* Base class */
class Employee_default_info
{
protected:
    /* Data members */
    int emp_id;
    string name;
    int age;
    string designation;
    long long int contact_no;
    char department;

public:
    /* Parameterized base class constructor */
    Employee_default_info(int emp_id, string name, int age,
        string designation, long long int contact_no, char department)
    {
        this->emp_id = emp_id;
        this->name = name;
        this->age = age;
        this->designation = designation;
        this->contact_no = contact_no;
        this->department = department;
    }

    /* Function to print employee default info */
    void print()
    {
        cout << "ID                    : " << emp_id << '\n'
            << "Name                  : " << name << '\n'
            << "Age                   : " << age << '\n'
            << "Designation           : " << designation << '\n'
            << "Contact no.           : " << contact_no << '\n'
            << "Department            : " << department << '\n';
    }
};

/* Derived class */
class Employee_addinfo : public Employee_default_info
{
protected:
    /* Data members */
    int leaves_of_absence;
    long long int emergency_contact_no;

public:
    /* Parameterized derived class constructor */
    Employee_addinfo(int emp_id, string name, int age,
        string designation, long long int contact_no, char department,
        int leaves_of_absence, long long int emergency_contact_no) :
        Employee_default_info(emp_id, name, age,
            designation, contact_no, department)
    {
        this->leaves_of_absence = leaves_of_absence;
        this->emergency_contact_no = emergency_contact_no;
    }

    /* Function to print employee info */
    void print()
    {
        Employee_default_info::print();
        cout << "Leaves of absence     : " << leaves_of_absence << '\n'
            << "Emergency contact no. : " << emergency_contact_no << '\n';
    }
};

int main()
{
    int id; string name; int age;
    string desig; long long int contact; char dept;
    int leaves; long long int emergency;
    cout << "Enter employee details \n"
        << "\tID                    : "; cin >> id;
    cout << "\tName                  : "; cin >> name;
    cout << "\tAge                   : "; cin >> age;
    cout << "\tDesignation           : "; cin >> desig;
    cout << "\tContact no.           : "; cin >> contact;
    cout << "\tDepartment            : "; cin >> dept;
    cout << "\tLeaves of absence     : "; cin >> leaves;
    cout << "\tEmergency contact no. : "; cin >> emergency;

    Employee_addinfo e1(id, name, age, desig, contact, dept, leaves, emergency);

    cout << "\nEmployee details: \n";
    e1.print();
    return 0;
}