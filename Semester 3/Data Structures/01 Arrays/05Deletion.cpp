/* Deleting element in array at an index */
#include <iostream>
using namespace std;

int deleteElement(int arr[], int* n, int index)
{
    int del = arr[index];
    for (int i = index; i < *n; i++)
        arr[i] = arr[i + 1];
    arr[*n - 1] = 0;
    (*n)--;
    return del;
}

int main()
{
    int n, arr[10], index;
    cout << "Enter the array size (<= 10): "; cin >> n;
    cout << "Enter " << n << " elements \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter element index to be deleted: "; cin >> index;
    cout << "Element deleted: " << deleteElement(arr, &n, index) << "\n";
    cout << "Array after deletion: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}