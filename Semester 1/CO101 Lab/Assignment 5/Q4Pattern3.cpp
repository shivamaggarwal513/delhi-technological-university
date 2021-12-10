#include <stdio.h>

int main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > i; j--)
		{
			printf("  ");
		}
		for (int k = 0; k < i + 1; k++)
		{
			printf("%d ", k + i + 1);
		}
		for (int l = i; l > 0; l--)
		{
			printf("%d ", l + i);
		}
		printf("\n");
	}
	return 0;
}