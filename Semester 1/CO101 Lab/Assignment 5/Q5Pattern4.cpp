#include <stdio.h>

int main()
{
	int c = 1, k, i, j;
	for (i = 0; i < 6; i++)
	{
		for (k = 1; k < 7 - i; k++)
		{
			printf(" ");
		}
		for (j = 0; j < i + 1; j++)
		{
			if (j != 0 && i != 0)
			{
				c = c * (i - j + 1) / j;
			}
			printf("%d ", c);
		}
		printf("\n");
	}
	return 0;
}