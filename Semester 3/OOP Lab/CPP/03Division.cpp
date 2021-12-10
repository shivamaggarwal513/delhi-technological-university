/* C++ Program to Find Quotient and Remainder */
#include <iostream>
using namespace std;

int main()
{
    int D, d;
    cout << "Enter dividend: "; cin >> D;
    cout << "Enter divisor: ";  cin >> d;
    int q = D / d, r = D % d;
    cout << D << " = " << d << " x " << q << " + " << r << "\n";
    cout << "Quotient: " << q << "\n";
    cout << "Remainder: " << r << "\n";
    return 0;
}