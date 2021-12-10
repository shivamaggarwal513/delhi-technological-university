/* Pointers to members */
#include <iostream>
#include <iomanip>
using namespace std;

class Student
{
public:
	/* Data members */
	char name[15];
	int age;
	float sgpa[8];
	float cgpa;

	/* Member function */
	void calculate_cgpa();
};

void Student::calculate_cgpa()
{
	int i;
	this->cgpa = 0;
	for (i = 0; i < 8 && this->sgpa[i] != 0; i++)
		this->cgpa += this->sgpa[i];
	this->cgpa /= i;
}

/* Pointers to data members */
char(Student::* ptr_name)[15] = &Student::name;
int Student::* ptr_age = &Student::age;
float(Student::* ptr_sgpa)[8] = &Student::sgpa;
float Student::* ptr_cgpa = &Student::cgpa;
/* Pointers to member function */
void (Student::* ptr_calculate_cgpa)() = &Student::calculate_cgpa;

int main()
{
	int n, i, j;
	Student arr[3];
	cout << "Enter details of 3 students \n";
	for (i = 0; i < 3; i++)
	{
		cout << "Student " << i + 1 << '\n';
		cout << "\tName: "; cin >> arr[i].*ptr_name;
		cout << "\tAge: "; cin >> arr[i].*ptr_age;
		cout << "\tNo. of semesters (<= 8): "; cin >> n;
		cout << "\tSGPAs: ";
		for (j = 0; j < n; j++)
			cin >> (arr[i].*ptr_sgpa)[j];
		for (j = n; j < 8; j++)
			(arr[i].*ptr_sgpa)[j] = 0;
		(arr[i].*ptr_calculate_cgpa)();
	}
	cout << "S.No \tName \tAge \tCGPA \n"
		<< "---------------------------- \n";
	for (i = 0; i < 3; i++)
	{
		cout << i + 1 << " \t"
			<< arr[i].*ptr_name << " \t"
			<< arr[i].*ptr_age << " \t"
			<< fixed << setprecision(2) << arr[i].*ptr_cgpa << " \n";
	}
	return 0;
}