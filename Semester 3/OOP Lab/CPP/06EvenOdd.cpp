/* C++ Program to Check Whether Number is Even or Odd */
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: "; cin >> n;
    (n % 2 == 0)
        ? cout << "Even\n"
        : cout << "Odd\n";
    return 0;
}