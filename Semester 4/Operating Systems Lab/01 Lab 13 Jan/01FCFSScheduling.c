/* Program to implement of FCFS scheduling */
#include <stdio.h>

void FCFSScheduling(int *burstTime, int n)
{
    int *waitingTime = (int *)malloc(n * sizeof(int));
    int *turnAroundTime = (int *)malloc(n * sizeof(int));

    waitingTime[0] = 0;
    turnAroundTime[0] = burstTime[0];
    int totalWaitingTime = 0, totalTurnAroundTime = turnAroundTime[0];

    for (int i = 1; i < n; i++)
    {
        waitingTime[i] = turnAroundTime[i - 1];
        turnAroundTime[i] = waitingTime[i] + burstTime[i];
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }

    float averageWaitingTime = (float)totalWaitingTime / (float)n;
    float averageTurnAroundTime = (float)totalTurnAroundTime / (float)n;

    printf("\nS.No. \tBurst Time \tWaiting Time \tTurnAround Time \n");
    for (int i = 0; i < n; i++)
        printf("%d. \t%d \t\t%d \t\t%d \n", i + 1, burstTime[i], waitingTime[i], turnAroundTime[i]);

    printf("\nAverage waiting time: %.2f \n", averageWaitingTime);
    printf("Average turn around time: %.2f \n", averageTurnAroundTime);

    free(waitingTime);
    free(turnAroundTime);
}

int main()
{
    int n;
    printf("Enter no. of processes: "); 
    scanf("%d", &n);
    int *burstTime = (int *)malloc(n * sizeof(int));

    printf("Enter burst times of %d processes: \n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &burstTime[i]);
    
    FCFSScheduling(burstTime, n);

    free(burstTime);
    return 0;
}