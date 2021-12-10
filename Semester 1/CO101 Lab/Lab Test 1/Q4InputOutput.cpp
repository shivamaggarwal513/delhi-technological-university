#include <stdio.h>

int main()
{
	int a, b, c, d, e, f, g, h, i, j;
	printf("Enter ten numbers: ");
	scanf_s("%i %i %i %i %i %i %i %i %i %i", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);
	printf("%i, %i, %i \n%i, %i, %i \n%i, %i, %i \n%i", a, b, c, d, e, f, g, h, i, j);
	return 0;
}