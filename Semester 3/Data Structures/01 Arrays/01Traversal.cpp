/* Determine smallest element in an array */
#include <iostream>
using namespace std;

int minElement(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

int main()
{
    int n, a[10];
    cout << "Enter the array size (<= 10): "; cin >> n;
    cout << "Enter " << n << " elements \n";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Smallest element is: " << minElement(a, n) << "\n";
    return 0;
}