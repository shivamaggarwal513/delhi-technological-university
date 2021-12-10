#include <stdio.h>

void main()
{
	int amount, hundreds, fifties, tens, remaining;
	printf("Enter the amount to be withdrawn: ");
	scanf_s("%d", &amount);
	hundreds = amount / 100;
	fifties = (amount % 100) / 50;
	tens = ((amount % 100) % 50) / 10;
	remaining = ((amount % 100) % 50) % 10;
	printf("%d amount contain %d 100s, %d 50s, %d 10s\n", amount, hundreds, fifties, tens);
	printf("Remaining amount: %d", remaining);
}