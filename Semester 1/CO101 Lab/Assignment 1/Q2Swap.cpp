#include <stdio.h>

int main()
{
	int n1, n2, temp;
	printf("Enter two integers:\n");
	scanf_s("%d %d", &n1, &n2);
	temp = n1;
	n1 = n2;
	n2 = temp;
	printf("Two integers after swaping are %d and %d", n1, n2);
	return 0;
}