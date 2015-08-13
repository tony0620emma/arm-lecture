#include<time.h>
#include<stdio.h>

extern fibonacci(int x);

int main(int argc, char *argv[]){
	int i;
	for(i = 0; fibonacci(i) < 2147482647; i++)
		printf("iteration of i is: %d\n", i);
	return 0;
}
