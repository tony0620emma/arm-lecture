#include <stdio.h>
#include <time.h>
#include "findGCD.h"

extern int findGCD_v1(int, int);
extern int findGCD_v2(int, int);
extern int findGCD_v3(int, int);

typedef int (*funcPtr)(int a, int b);

double get_exec_time_secs(funcPtr);

struct timespec timespec;

int main(int argc, char *argv[])
{
	funcPtr fP;
	fP = &findGCD_v1;
	printf("time for v1: %lf\n", get_exec_time_secs(fP));
	fP = &findGCD_v2;
	printf("time for v2: %lf\n", get_exec_time_secs(fP));
	fP = &findGCD_v3;
	printf("time for v3: %lf\n", get_exec_time_secs(fP));

	return 0;
}

double get_exec_time_secs(funcPtr fP)
{
	int i, j;
	clock_gettime(CLOCK_MONOTONIC, &timespec);
	double start_time = timespec.tv_sec + ((double)(timespec.tv_nsec/1000)) / 1000000;
	
	for(i = 2; i < 10000; i++)
	{
		for(j = 2; j < i; j++)
		{
			(*fP)(i, j);
		}
	}

	clock_gettime(CLOCK_MONOTONIC, &timespec);
	double end_time = timespec.tv_sec + ((double)(timespec.tv_nsec/1000)) / 1000000;

	return end_time - start_time;
}
