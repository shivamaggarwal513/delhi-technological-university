#include <stdio.h>
#include <stdlib.h>

void FCFSScheduling(int *arrivalTime, int *burstTime, int n)
{
    int *waitingTime = (int *)malloc(n * sizeof(int));
    int *turnAroundTime = (int *)malloc(n * sizeof(int));
    int *completionTime = (int *)malloc(n * sizeof(int));

    waitingTime[0] = 0;
    completionTime[0] = burstTime[0];
    turnAroundTime[0] = burstTime[0];
    int totalWaitingTime = 0, totalTurnAroundTime = turnAroundTime[0];
    int t = burstTime[0];

    for (int i = 1; i < n; i++)
    {
        if (t < arrivalTime[i])
            t = arrivalTime[i--];
        else
        {
            completionTime[i] = t + burstTime[i];
            turnAroundTime[i] = completionTime[i] - arrivalTime[i];
            waitingTime[i] = turnAroundTime[i] - burstTime[i];
            
            totalWaitingTime += waitingTime[i];
            totalTurnAroundTime += turnAroundTime[i];

            t += burstTime[i];
        }
    }

    float averageWaitingTime = (float)totalWaitingTime / (float)n;
    float averageTurnAroundTime = (float)totalTurnAroundTime / (float)n;

    printf("\nS.No. \tArrival \tBurst \tCompletion \tTurnAround \tWaiting \n");
    for (int i = 0; i < n; i++)
        printf("%d. \t%d \t\t%d \t%d \t\t%d \t\t%d \n", i + 1, arrivalTime[i], burstTime[i], completionTime[i], turnAroundTime[i], waitingTime[i]);

    printf("\nAverage waiting time: %.2f \n", averageWaitingTime);
    printf("Average turn around time: %.2f \n", averageTurnAroundTime);

    free(waitingTime);
    free(turnAroundTime);
    free(completionTime);
}

int main()
{
    int n;
    printf("Enter no. of processes: "); 
    scanf("%d", &n);

    int *arrivalTime = (int *)malloc(n * sizeof(int));
    printf("Enter arrival times of %d processes in ascending order: \n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arrivalTime[i]);
    
    int *burstTime = (int *)malloc(n * sizeof(int));
    printf("Enter burst times of %d processes: \n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &burstTime[i]);
    
    FCFSScheduling(arrivalTime, burstTime, n);

    free(arrivalTime);
    free(burstTime);
    return 0;
}