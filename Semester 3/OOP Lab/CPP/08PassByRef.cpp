/* Passing arguments by reference */
#include <iostream>
using namespace std;

void zeroSmaller(int& a, int& b)
{
    (a > b) ? b = 0 : a = 0;
}

int main()
{
    int n1, n2;
    cout << "Enter two numbers: "; cin >> n1 >> n2;
    zeroSmaller(n1, n2);
    cout << "Numbers after zeroSmaller: " << n1 << " " << n2 << "\n";
    return 0;
}