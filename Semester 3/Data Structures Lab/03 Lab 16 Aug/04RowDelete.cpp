/* Write a program to delete a given row in the two-dimensional array */
#include <iostream>
using namespace std;

int main()
{
    int arr[10][10], r, c, k;
    cout << "Enter no. of rows (<= 10): "; cin >> r;
    cout << "Enter no. of columns (<= 10): "; cin >> c;
    cout << "Enter " << r * c << " elements \n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> arr[i][j];
    cout << "Enter row to be deleted: "; cin >> k;
    for (int i = k; i < r - 1; i++)
        for (int j = 0; j < c; j++)
            arr[i][j] = arr[i + 1][j];
    r--;
    cout << "Array after deletion of row " << k << "\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    return 0;
}