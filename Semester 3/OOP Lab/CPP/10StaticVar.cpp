/* Static variables */
#include <iostream>
using namespace std;

static int count = 0;

void fun()
{
    ::count++;
    cout << "I've been called " << ::count << " times \n";
}

int main()
{
    int n = 1;
    cout << "Enter 0 to stop \n";
    while (n != 0)
    {
        fun();
        cin >> n;
    }
    return 0;
}