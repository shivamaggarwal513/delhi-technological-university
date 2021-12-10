#include <stdio.h>

int main()
{
	float a;
	printf("Enter a number: ");
	scanf_s("%f", &a);
	int b = a;
	printf("Rightmost digit of the integral part of %f is %i", a, b % 10);
	return 0;
}