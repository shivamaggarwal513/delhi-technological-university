#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define N 5
#define LEFT (num + N - 1) % N
#define RIGHT (num + N) % N
int EATING = 0, HUNGRY = 1, THINKING = 2;
int state[N];
int phil[N] = {0, 1, 2, 3, 4};

sem_t mutex;
sem_t S[N];

void test(int num)
{
	if (state[num] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
	{
		state[num] = EATING;
		sleep(2);
		printf("Philosopher %d picks chopsticks %d and %d \n", num + 1, LEFT + 1, num + 1);
		printf("Philosopher %d is eating \n", num + 1);
		sem_post(&S[num]);
	}
}

void pick_chopsticks(int num)
{
	sem_wait(&mutex);
	state[num] = HUNGRY;
	printf("Philosopher %d is hungry \n", num + 1);
	
	test(num);
	
	sem_post(&mutex);
	sem_wait(&S[num]);
	
	sleep(1);
}

void put_chopsticks(int num)
{
	sem_wait(&mutex);
	
	state[num] = THINKING;
	printf("Philosopher %d is putting down chopsticks %d and %d \n", num + 1, LEFT + 1, num + 1);
	printf("Philosopher %d is thinking \n", num + 1);
	
	test(LEFT);
	test(RIGHT);
	
	sem_post(&mutex);
}

void *philosopher(void *num)
{
	while (1)
	{
		int *i = num;
		sleep(1);
		pick_chopsticks(*i);
		sleep(0);
		put_chopsticks(*i);
	}
}

int main()
{
	int i;
	pthread_t threadID[N];
	
	sem_init(&mutex, 0, 1);
	
	for (i = 0; i < N; i++)
		sem_init(&S[i], 0, 0);
	
	for (i = 0; i < N; i++)
	{
		pthread_create(&threadID[i], NULL, philosopher, &phil[i]);
		printf("Philosopher %d is thinking \n", i + 1);
	}
	
	for (i = 0; i < N; i++)
		pthread_join(threadID[i], NULL);
	
	return 0;
}