#include <stdio.h>
#include <stdlib.h>
#define BSIZE 10

int S = 1;
int full = 0, empty = BSIZE, x = 0;

void producer()
{
	/* Entry code */
	S--;
	full++;
	empty--;
	
	/* Critical section */
	x++;
	printf("P%d produced \n", x);
	
	/* Exit code */
	S++;
}

void consumer()
{
	/* Entry code */
	S--;
	full--;
	empty++;
	
	/* Critical section */
	printf("P%d consumed \n", x);
	x--;
	
	/* Exit code */
	S++;
}

int main()
{
	printf("1. Producer \n2. Consumer \n");
	int choice;
	
	#pragma omp critical
	
	while (1)
	{
		printf("Choice: ");
		scanf("%d", &choice);
		
		if (choice == 1)
		{
			if (S == 1 && empty != 0) { producer(); }
			else { printf("Buffer overflow \n"); }
		}
		else if (choice == 2)
		{
			if (S == 1 && full != 0) { consumer(); }
			else { printf("Buffer underflow \n"); }
		}
		else { break; }
	}
	return 0;
}