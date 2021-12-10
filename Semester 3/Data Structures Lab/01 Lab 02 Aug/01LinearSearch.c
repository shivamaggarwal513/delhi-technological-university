/* Write a program to Implement Linear Search in the C programming language */
#include <stdio.h>
#include <stdlib.h>

int linSearch(int* A, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if ((*(A + i)) == k)
            return i;
    }
    return -1;
}

int main()
{
    int n, k, index;
    printf("Enter no. of elements: "); 
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter %d elements \n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    printf("Enter element to be searched: "); 
    scanf("%d", &k);
    index = linSearch(arr, n, k);
    if (index >= 0)
        printf("Element found at index: %d \n", index);
    else
        printf("Element not found \n");
    return 0;
}