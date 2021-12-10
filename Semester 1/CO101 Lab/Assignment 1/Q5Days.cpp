#include <stdio.h>

int main()
{
	int days1, days, weeks, years;
	printf("Enter number of days: ");
	scanf_s("%d", &days1);
	years = days1 / 365;
	weeks = (days1 % 365) / 7;
	days = (days1 % 365) % 7;
	printf("%d days contain %d years, %d weeks, %d days", days1, years, weeks, days);
	return 0;
}