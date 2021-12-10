/* C++ Program to Swap Two Numbers (without temporary variables) */
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter two numbers: "; cin >> a >> b;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "Numbers after swap: " << a << " " << b << "\n";
    return 0;
}