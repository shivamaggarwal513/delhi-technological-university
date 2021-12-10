/* Finding element in array by Binary Search */
#include <iostream>
using namespace std;

int binSearch(int arr[], int n, int num)
{
    int beg = 0, mid, end = n - 1;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] > num)
            end = mid - 1;
        else if (arr[mid] < num)
            beg = mid + 1;
    }
    return -1;
}

int main()
{
    int n, a[10], k;
    cout << "Enter the array size (<= 10): "; cin >> n;
    cout << "Enter " << n << " elements \n";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter element to be searched: "; cin >> k;
    int found = binSearch(a, n, k);
    (found >= 0)
        ? cout << "Element found at index: " << found << "\n"
        : cout << "Element not found \n";
    return 0;
}