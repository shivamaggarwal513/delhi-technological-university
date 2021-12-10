/* Write a program to Implement Binary Search */
#include <iostream>
using namespace std;

int binSearch(int* A, int start, int end, int k)
{
    if (start > end)
        return -1;
    else
    {
        int mid = (start + end) / 2;
        if (*(A + mid) == k)
            return mid;
        else if (*(A + mid) > k)
            return binSearch(A, start, mid - 1, k);
        else
            return binSearch(A, mid + 1, end, k);
    }
}

int main()
{
    int n, k, index;
    cout << "Enter no. of elements: "; cin >> n;
    int* arr = new int(n);
    cout << "Enter " << n << " elements \n";
    for (int i = 0; i < n; i++)
        cin >> *(arr + i);
    cout << "Enter element to be searched: "; cin >> k;
    index = binSearch(arr, 0, n - 1, k);
    if (index >= 0)
        cout << "Element found at index: " << index << "\n";
    else
        cout << "Element not found \n";
    return 0;
}