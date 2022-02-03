/* Program to implement priority scheduling */
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class Process
{
public:
	int PID;
    int arrivalTime;
	int burstTime;
	int remainingBurstTime;
	int responseTime;
	int priority;
	int outTime;
	int inTime;
};

void insertQueue(Process table[], Process value, int *size, int *t)
{
	int i = *size;
	table[*size] = value;
	if (table[*size].inTime == -1)
		table[*size].inTime = *t;
	*size += 1;

	while (i != 0 && table[(i - 1) / 2].priority > table[i].priority)
    {
		Process temp = table[(i - 1) / 2];
		table[(i - 1) / 2] = table[i];
		table[i] = temp;
		i = (i - 1) / 2;
	}
}

void orderProcesses(Process table[], int* size, int i)
{
	int small = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < *size && table[left].priority < table[small].priority)
		small = left;
	if (right < *size && table[right].priority < table[small].priority)
		small = right;

	if (small != i)
    {
		Process temp = table[small];
		table[small] = table[i];
		table[i] = temp;
		orderProcesses(table, size, small);
	}
}

Process findHighest(Process table[], int *size, int *t)
{
	Process min = table[0];
	if (min.responseTime == -1)
		min.responseTime = *t - min.arrivalTime;
	*size -= 1;
	if (*size >= 1)
    {
		table[0] = table[*size];
		orderProcesses(table, size, 0);
	}
	return min;
}

bool comparator(Process p1, Process p2)
{
	return (p1.arrivalTime < p2.arrivalTime);
}

void scheduling(Process table[], Process array[], int n, int *size, int *t)
{
	if (size == 0)
		return;

	Process min = findHighest(table, size, t);
	min.outTime = *t + 1;
	min.burstTime -= 1;

    cout << "P" << min.PID << ": " << *t << "\t";

	if (min.burstTime > 0)
    {
		insertQueue(table, min, size, t);
		return;
	}

	for (int i = 0; i < n; i++)
		if (array[i].PID == min.PID)
        {
			array[i] = min;
			break;
		}
}

void PriorityScheduling(Process array[], int n)
{
	sort(array, array + n, comparator);

	int totalWT = 0, totalBT = 0, totalTAT = 0, i, insertedProcesses = 0, size = 0, t = array[0].arrivalTime, totalRT = 0;

	Process *table = new Process[4 * n];

	for (int i = 0; i < n; i++)
    {
		totalBT += array[i].burstTime;
		array[i].remainingBurstTime = array[i].burstTime;
	}

    cout << "\n";
	while (true)
    {
		if (insertedProcesses != n)
			for (i = 0; i < n; i++)
				if (array[i].arrivalTime == t)
                {
					insertedProcesses += 1;
					array[i].inTime = -1;
					array[i].responseTime = -1;
					insertQueue(table, array[i], &size, &t);
				}
        
		scheduling(table, array, n, &size, &t);
		t += 1;
		if (size == 0 && insertedProcesses == n)
			break;
	}
    cout << "\n";

    delete []table;

	for (int i = 0; i < n; i++)
    {
		totalRT += array[i].responseTime;
		totalWT += array[i].outTime - array[i].inTime - array[i].remainingBurstTime;
		totalBT += array[i].burstTime;
	}

    cout << fixed << setprecision(2)
        << "Average waiting time: " << ((float)totalWT / (float)n)
        << "\nAverage response time: " << ((float)totalRT / (float)n)
        << "\nAverage turn around time: " << ((float)(totalWT + totalBT) / (float)n)
        << "\n";
}

int main()
{
    int n, i;
    cout << "Enter no. of processes: "; cin >> n;

	Process *array = new Process[n];
    
    cout << "Enter " << n << " process IDs: ";
    for (i = 0; i < n; i++)
        cin >> array[i].PID;
    
    cout << "Enter " << n << " arrival times: ";
    for (i = 0; i < n; i++)
        cin >> array[i].arrivalTime;
    
    cout << "Enter " << n << " burst times: ";
    for (i = 0; i < n; i++)
        cin >> array[i].burstTime;
    
    cout << "Enter " << n << " priorities: ";
    for (i = 0; i < n; i++)
        cin >> array[i].priority;

    PriorityScheduling(array, n);
    
	delete []array;
	return 0;
}