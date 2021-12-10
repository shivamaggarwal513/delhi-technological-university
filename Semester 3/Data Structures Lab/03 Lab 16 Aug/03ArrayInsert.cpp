/* Write a program to insert an element at the mid-position in the one-dimensional array */
#include <iostream>
using namespace std;

void insertMid(int* &A, int &n, int &k)
{
    for (int i = n; i > n / 2; i--)
        *(A + i) = *(A + i - 1);
    *(A + n / 2) = k;
}

int main()
{
    int n, k;
    cout << "Enter no. of elements: "; cin >> n;
    int* arr = new int(n + 1);
    cout << "Enter " << n << " elements \n";
    for (int i = 0; i < n; i++)
        cin >> *(arr + i);
    cout << "Enter element to be inserted: "; cin >> k;
    insertMid(arr, n, k);
    n++;
    cout << "Array after insertion at mid \n";
    for (int i = 0; i < n; i++)
        cout << *(arr + i) << " ";
    return 0;
}