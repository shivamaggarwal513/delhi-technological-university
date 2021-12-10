/* Swap int, char, float using Function Overloading */
#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}

void swap(float& a, float& b)
{
    float temp = a;
    a = b;
    b = temp;
}

int main()
{
    int i1, i2; char c1, c2; float f1, f2;
    cout << "Enter two integers: "; cin >> i1 >> i2;
    swap(i1, i2);
    cout << "Integers after swapping: " << i1 << " " << i2 << "\n";

    cout << "Enter two characters: "; cin >> c1 >> c2;
    swap(c1, c2);
    cout << "Characters after swapping: " << c1 << " " << c2 << "\n";

    cout << "Enter two floats: "; cin >> f1 >> f2;
    swap(f1, f2);
    cout << "Floats after swapping: " << f1 << " " << f2 << "\n";
    return 0;
}