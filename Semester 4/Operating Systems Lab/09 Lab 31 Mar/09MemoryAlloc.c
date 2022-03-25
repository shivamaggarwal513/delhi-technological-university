#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647

int nM, nP, *memBlockSize, *temp1, *processSize, *temp2;

void copyData()
{
	int i;
	for (i = 0; i < nM; i++)
		memBlockSize[i] = temp1[i];
	for (i = 0; i < nP; i++)
		processSize[i] = temp2[i];
}

void firstFit()
{
	copyData();
	printf("\n*************** First Fit *************** \n");
	
	int i, j, flag;
	
	for (i = 0; i < nP; i++)
	{
		flag = 0;
		
		/* finding first block that is big enough */
		for (j = 0; j < nM; j++)
		{
			if (processSize[i] <= memBlockSize[j])
			{
				flag = 1;
				printf("%d \t\t%d(%d) \t\t%d \n", processSize[i], memBlockSize[j], j + 1, memBlockSize[j] - processSize[i]);
				memBlockSize[j] -= processSize[i];
				break;
			}
		}
		
		/* no such block found */
		if (flag == 0)
		{
			printf("%d \t\tNOT ALLOCATED \n", processSize[i]);
			break;
		}
	}
}

void bestFit()
{
	copyData();
	printf("\n*************** Best Fit *************** \n");
	
	int i, j, minSize, minIndex;
	
	for (i = 0; i < nP; i++)
	{
		minSize = INT_MAX;
		minIndex = 0;
		
		/* finding smallest block that is big enough */
		for (j = 0; j < nM; j++)
		{
			if (processSize[i] <= memBlockSize[j] && minSize > memBlockSize[j])
			{
				minSize = memBlockSize[j];
				minIndex = j;
			}
		}
		
		if (minSize != INT_MAX)
		{
			printf("%d \t\t%d(%d) \t\t%d \n", processSize[i], minSize, minIndex + 1, minSize - processSize[i]);
				memBlockSize[minIndex] -= processSize[i];
		}
		else /* no such block found */
		{
			printf("%d \t\tNOT ALLOCATED \n", processSize[i]);
			break;
		}
	}
}

void worstFit()
{
	copyData();
	printf("\n*************** Worst Fit *************** \n");
	
	int i, j, maxSize, maxIndex;
	
	for (i = 0; i < nP; i++)
	{
		maxSize = 0;
		maxIndex = 0;
		
		/* finding largest block */
		for (j = 0; j < nM; j++)
		{
			if (maxSize < memBlockSize[j])
			{
				maxSize = memBlockSize[j];
				maxIndex = j;
			}
		}
		
		if (processSize[i] <= maxSize)
		{
			printf("%d \t\t%d(%d) \t\t%d \n", processSize[i], maxSize, maxIndex + 1, maxSize - processSize[i]);
				memBlockSize[maxIndex] -= processSize[i];
		}
		else /* block not large enough */
		{
			printf("%d \t\tNOT ALLOCATED \n", processSize[i]);
			break;
		}
	}
}

int main()
{
	int i;
	
	printf("Enter no. of memory blocks: ");
	scanf("%d", &nM);
	memBlockSize = (int *)malloc(nM * sizeof(int));
	temp1 = (int *)malloc(nM * sizeof(int));
	printf("Enter sizes of %d memory blocks: ", nM);
	for (i = 0; i < nM; i++)
		scanf("%d", &temp1[i]);
	
	printf("Enter no. of processes: ");
	scanf("%d", &nP);
	processSize = (int *)malloc(nP * sizeof(int));
	temp2 = (int *)malloc(nP * sizeof(int));
	printf("Enter sizes of %d processes: ", nP);
	for (i = 0; i < nP; i++)
		scanf("%d", &temp2[i]);
	
	printf("\nProcess \tMemory(No.) \tRemaining \n");
	firstFit();
	bestFit();
	worstFit();
	
	free(memBlockSize);
	free(temp1);
	free(processSize);
	free(temp2);
	
	return 0;
}