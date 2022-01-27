/* Program to implement of SJF scheduling */
#include <stdio.h>

void swap(int *a, int *b) { int temp = *a; *a = *b; *b = temp; }

void SJFScheduling(int n, int table[][6])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (table[j][1] > table[j + 1][1])
                for (int k = 0; k < 5; k++)
                    swap(&table[j][k], &table[j + 1][k]);
    
    int temp, val, i, j, k, low;
	table[0][3] = table[0][1] + table[0][2];
	table[0][5] = table[0][2];
	table[0][4] = 0;

	for (i = 1; i < n; i++)
	{
		temp = table[i - 1][3];
		low = table[i][2];
		for (j = i; j < n; j++)
			if (temp >= table[j][1] && low >= table[j][2])
				low = table[j][2], val = j;
		
		table[val][3] = temp + table[val][2];
		table[val][5] = table[val][3] - table[val][1];
		table[val][4] = table[val][5] - table[val][2];
		
		for (k = 0; k < 6; k++)
			swap(&table[val][k], &table[i][k]);
	}
}

int main()
{
    int n, i, table[10][6];
    float avgWT = 0, avgTAT = 0;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    
    printf("Enter %d process IDs: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &table[i][0]);
    
    printf("Enter %d arrival times: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &table[i][1]);
    
    printf("Enter %d burst times: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &table[i][2]);
    
    SJFScheduling(n, table);
    
    printf("\nPID \tArrival \tBurst \tWaiting \tTurnAround \n");
    for (i = 0; i < n; i++)
    {
        printf("%d \t%d \t\t%d \t%d \t\t%d \n", table[i][0], table[i][1], table[i][2], table[i][4], table[i][5]);
        avgWT += table[i][4];
        avgTAT += table[i][5];
    }

    avgWT = (float)avgWT / (float)n;
    avgTAT = (float)avgTAT / (float)n;
    
    printf("\nAverage waiting time: %.2f \n", avgWT);
    printf("Average turn around time: %.2f \n", avgTAT);
        
	return 0;
}