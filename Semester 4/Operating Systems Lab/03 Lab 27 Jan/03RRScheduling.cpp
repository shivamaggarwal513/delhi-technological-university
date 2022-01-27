/* Program to implement round robin scheduling */
#include <iostream>
#include <iomanip>
using namespace std;

class Process
{
public:
	int PID;
	int burstTime;
	int remainingBurstTime;
	int turnAroundTime;
	int waitingTime;

	Process(int burstTime = 0)
	{
		remainingBurstTime = burstTime;
		turnAroundTime = 0;
		waitingTime = 0;
	}
};

void findWaitingTime(Process table[], int n, int quanta)
{
	int t = 0, i;

	while (1)
	{
		bool done = true;

		for (i = 0; i < n; i++)
		{
			if (table[i].remainingBurstTime > 0)
			{
				done = false;

				if (table[i].remainingBurstTime > quanta)
				{
					t += quanta;
					table[i].remainingBurstTime -= quanta;
				}
				else
				{
					t += table[i].remainingBurstTime;
					table[i].waitingTime = t - table[i].burstTime;
					table[i].remainingBurstTime = 0;
				}
			}
		}

		if (done == true)
			break;
	}
}

void RRScheduling(Process table[], int n, int quanta)
{
	int i;
	float avgWT = 0, avgTAT = 0;
	findWaitingTime(table, n, quanta);
	for (i = 0; i < n; i++)
		table[i].turnAroundTime = table[i].burstTime + table[i].waitingTime;

	cout << "\nPID \tBurst \tWaiting \tTurnAround \n";
    for (i = 0; i < n; i++)
    {
		cout << table[i].PID << " \t"
			<< table[i].burstTime << " \t"
			<< table[i].waitingTime << " \t\t"
			<< table[i].turnAroundTime << " \n";
        avgWT += table[i].waitingTime;
        avgTAT += table[i].turnAroundTime;
    }

    avgWT = (float)avgWT / (float)n;
    avgTAT = (float)avgTAT / (float)n;
    
	cout << fixed << setprecision(2) 
		<< "\nAverage waiting time: " << avgWT << " \n"
		<< "Average turn around time: " << avgTAT << " \n";
}

int main()
{
	int n, i, quanta;
    cout << "Enter no. of processes: "; cin >> n;

	Process *table = new Process[n];
    
    cout << "Enter " << n << " process IDs: ";
    for (i = 0; i < n; i++)
        cin >> table[i].PID;
    
    cout << "Enter " << n << " burst times: ";
    for (i = 0; i < n; i++)
        cin >> table[i].burstTime, table[i].remainingBurstTime = table[i].burstTime;
    
    cout << "Enter value of 1 time quanta: "; cin >> quanta;

    RRScheduling(table, n, quanta);
    
	delete []table;
	return 0;
}