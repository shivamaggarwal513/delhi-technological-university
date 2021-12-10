/* Inline functions */
#include <iostream>
using namespace std;

inline int add(int a, int b)
{
    int sum = a + b;
    return sum;
}

int main()
{
    int n1, n2;
    cout << "Enter two numbers: "; cin >> n1 >> n2;
    cout << n1 << " + " << n2 << " = " << add(n1, n2) << "\n";
    return 0;
}