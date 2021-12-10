/* Finding element in array by Linear Search */
#include <iostream>
using namespace std;

int linSearch(int arr[], int n, int num)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == num)
            return i;
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
    int found = linSearch(a, n, k);
    (found >= 0)
        ? cout << "Element found at index: " << found << "\n"
        : cout << "Element not found \n";
    return 0;
}