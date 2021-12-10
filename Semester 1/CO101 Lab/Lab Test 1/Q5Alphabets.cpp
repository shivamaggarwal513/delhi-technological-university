#include <stdio.h>

int main()
{
	char a;
	printf("Enter a character: ");
	scanf_s("%c", &a);
	if (a >= 'A' && a <= 'Z')
	{
		printf("Entered character '%c' is uppercase\n", a);
		a += 32;
		printf("Character in lowercase is '%c'", a);
	}
	else
	{
		printf("Entered character '%c' is lowercase\n", a);
		a -= 32;
		printf("Character in uppercase is '%c'", a);
	}
	return 0;
}