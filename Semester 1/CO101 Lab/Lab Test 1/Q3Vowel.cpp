#include <stdio.h>

int main()
{
	char a;
	printf("Enter a character: ");
	scanf_s("%c", &a);

	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'
		|| a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
	{
		printf("Entered character '%c' is a vowel", a);
	}
	else
	{
		printf("Entered character '%c' is not a vowel", a);
	}
	return 0;
}