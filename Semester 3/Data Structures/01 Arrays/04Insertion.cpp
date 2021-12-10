/* Inserting element in array at an index */
#include <iostream>
using namespace std;

void insertElement(int arr[], int* n, int num, int index)
{
    for (int i = *n; i >= index; i--)
        arr[i] = arr[i - 1];
    arr[index] = num;
    (*n)++;
}

int main()
{
    int n, arr[10], k, index;
    cout << "Enter the array size (< 10): "; cin >> n;
    cout << "Enter " << n << " elements \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter element to be inserted: "; cin >> k;
    cout << "Enter index: "; cin >> index;
    insertElement(arr, &n, k, index);
    cout << "Array after insertion: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}