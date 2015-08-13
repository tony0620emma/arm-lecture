#include <stdio.h>
#include <time.h>
#include "findGCD.h"

extern int findGCD_v1(int, int);
extern int findGCD_v2(int, int);
extern int findGCD_v3(int, int);

typedef int (*funcPtr)(int a, int b);

long get_exec_time_nsecs(funcPtr);

struct timespec timespec;

int main(int argc, char *argv[])
{
	funcPtr fP;
	fP = &findGCD_v1;
	printf("time for v1: %ld\n", get_exec_time_nsecs(fP));
	fP = &findGCD_v2;
	printf("time for v2: %ld\n", get_exec_time_nsecs(fP));
	fP = &findGCD_v3;
	printf("time for v3: %ld\n", get_exec_time_nsecs(fP));

	return 0;
}

long get_exec_time_nsecs(funcPtr func_pointer)
{
	int i, j;
	clock_gettime(CLOCK_MONOTONIC, &timespec);
	long start_time = timespec.tv_sec * 1000000000LL + timespec.tv_nsec;
	
	for(i = 2; i < 10000; i++)
	{
		for(j = 2; j <= i; j++)
		{
			(*func_pointer)(i, j);
		}
	}

	clock_gettime(CLOCK_MONOTONIC, &timespec);
	long end_time = timespec.tv_sec * 1000000000LL + timespec.tv_nsec;

	return end_time - start_time;
}
