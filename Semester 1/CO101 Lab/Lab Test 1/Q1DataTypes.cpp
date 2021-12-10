#include <stdio.h>

int main()
{
	int n;
	printf("Enter a number: ");
	scanf_s("%i", &n);

	printf("Decimal value is: %d\n", n);
	printf("Octal value is: %o\n", n);
	printf("Hexadecimal value is (Alphabet in small letters): %x\n", n);
	printf("Hexadecimal value is (Alphabet in capital letters): %X\n", n);
	return 0;
}