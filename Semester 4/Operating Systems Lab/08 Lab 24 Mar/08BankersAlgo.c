#include <stdio.h>

/* Safe state testcase */
#define N 5
#define M 4

int allocation[N][M] = {{0, 0, 1, 2},
						{1, 0, 0, 0},
						{1, 3, 5, 4},
						{0, 6, 3, 2},
						{0, 0, 1, 4}};

int max[N][M] = {{0, 0, 1, 2},
				 {1, 7, 5, 0},
				 {2, 3, 5, 6},
				 {0, 6, 5, 2},
				 {0, 6, 5, 6}};

int available[M] = {1, 5, 2, 0};

/* Unsafe state testcase */
/*
#define N 4
#define M 3

int allocation[N][M] = {{2, 1, 1},
						{2, 3, 1},
						{1, 1, 4},
						{1, 4, 2}};

int max[N][M] = {{4, 2, 2},
				 {7, 3, 10},
				 {5, 2, 13},
				 {10, 5, 4}};

int available[M] = {8, 1, 2};
*/

int finish[M], need[N][M], safeSeq[N], safeSeqI = 0;

int processCheck(int i)
{
	int j;
	if (finish[i] == 1)
		return 1;
	
	for (j = 0; j < M; j++)
		if (need[i][j] > available[j])
			return 0;
	
	return 2;
}

void printDetails(int i, int ch)
{
	int j;
	
	printf("P%d : \n", i);
	printf("Need ");
	(ch == 0) ? printf("> ") : printf("<= ");
	printf("Available \n");
	
	for (j = 0; j < M; j++)
		printf("%d ", need[i][j]);
	(ch == 0) ? printf("> ") : printf("<= ");
	for (j = 0; j < M; j++)
		printf("%d ", available[j]);
}

int bankersAlgo()
{
	int i, j, ans, flag = 0;
	
	/* step1 */
	for (i = 0; i < N; i++)
		finish[i] = 0;
	
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			need[i][j] = max[i][j] - allocation[i][j];
	
	/* step2 */
	step2:
	flag = 0;
	for (i = 0; i < N; i++)
	{
		ans = processCheck(i);
		
		/* step3 */
		if (ans == 0) /* wait process */
		{
			printDetails(i, ans);
			printf("\nWait P%d \n\n", i);
		}
		else if (ans == 2) /* execute process */
		{
			flag = 1;

			printDetails(i, 2);
			safeSeq[safeSeqI++] = i;
			
			printf("\nExecute P%d \nAvailable: ", i);
			
			for (j = 0; j < M; j++)
			{
				available[j] += allocation[i][j];
				printf("%d ", available[j]);
			}
			printf("\n\n");
			finish[i] = 1;
		}
	}
	
	if (flag == 1)
		goto step2;
}

int main()
{
	int i, flag = 1;
	bankersAlgo();
	
	/* step4 */
	for (i = 0; i < M; i++)
	{
		if (finish[i] == 0)
		{
			flag = 0;
			break;
		}
	}
	
	if (flag == 1)
	{
		printf("The system is in safe state \n");
		
		printf("Safe sequence: ");
		for (i = 0; i < safeSeqI; i++)
			printf("P%d ", safeSeq[i]);
		printf("\n");
	}
	else
	{
		printf("The system is not in safe state \n");
		
		printf("Complete processes: ");
		for (i = 0; i < safeSeqI; i++)
			printf("P%d ", safeSeq[i]);
		
		printf("\nIncomplete processes: ");
		for (i = 0; i < M; i++)
			if (finish[i] == 0)
				printf("P%d ", i);
		printf("\n");
	}
	
    return 0;
}