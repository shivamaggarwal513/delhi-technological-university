#include <stdio.h>

int main()
{
	float n1, n2, n3, n4, n5, total, average, percentage;
	printf("Enter marks of 5 subjects (0-100):\n");
	scanf_s("%f %f %f %f %f", &n1, &n2, &n3, &n4, &n5);
	total = n1 + n2 + n3 + n4 + n5;
	average = total / 5;
	percentage = average;
	printf("Total marks of all 5 subjects are %f\n", total);
	printf("Average marks are %f\n", average);
	printf("Percentage is %f percent", percentage);
	return 0;
}