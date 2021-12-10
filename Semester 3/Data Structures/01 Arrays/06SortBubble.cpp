#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j, flag;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

int main()
{
    int arr[10], n;
    cout << "Enter the array size (<= 10): "; cin >> n;
    cout << "Enter " << n << " elements \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bubbleSort(arr, n);
    cout << "Array after bubble sort: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}