/* C++ program to calculate simple interest */
#include <iostream>
using namespace std;

int main()
{
    double p, r, t;
    cout << "Enter principal: "; cin >> p;
    cout << "Enter rate: ";      cin >> r;
    cout << "Enter time: ";      cin >> t;
    double si = (p * r * t) / 100.0;
    cout << "Simple interest: " << si << '\n';
    return 0;
}