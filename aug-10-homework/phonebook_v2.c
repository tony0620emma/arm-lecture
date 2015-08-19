#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "phonebook_v2.h"

struct timespec timespec;

int main(int argc, char *argv[])
{
	printf("size of phonebook v2: %zu\n", sizeof(PhoneBook_v2));
	
	FILE *fp;

	fp = fopen("dictionary/all-names.txt", "r");
	if(fp ==NULL){
		puts("failed to open the file");
		return 1;
	}
	
	char line[MAX_LAST_NAME_SIZE];
	int i = 0;
	PhoneBook_v2 *pHead2, *entry2, *pTarget2;
	pHead2 = (PhoneBook_v2 *) malloc(sizeof(PhoneBook_v2));
        entry2 = pHead2;
	entry2->pNext = NULL;
	int j;
	for(j = 1000; j > 0; j--){ // I want to create a larger struct
		while(fgets(line, sizeof(line), fp)){
			while((line[i] >= 'a' && line[i] <= 'z') || 
					(line[i] >= 'A' && line[i] <= 'Z'))
			{i++;}
			
			line[i] = '\0';
			i = 0;
			entry2 = append_v2(line, entry2);
		}
		fseek(fp, 0, SEEK_SET);
	}
	entry2 = append_v2("correct_name", entry2);

	double start_time, end_time;

	/* flushing the cache */
	system("echo 1 >/proc/sys/vm/drop_caches");
	system("echo 2 >/proc/sys/vm/drop_caches");
	system("echo 3 >/proc/sys/vm/drop_caches");
	
	/* Test the time for version 2*/
	clock_gettime(CLOCK_MONOTONIC, &timespec);
	start_time = timespec.tv_sec + 
		((double)(timespec.tv_nsec / 10000)) / 100000;
	pTarget2 = FindName_v2("correct_name", pHead2);
	if(pTarget2 != NULL){
		puts("found name");
		printf(" : %s\n", pTarget2->LastName);
	}
	clock_gettime(CLOCK_MONOTONIC, &timespec);	
	end_time = timespec.tv_sec + 
		((double)(timespec.tv_nsec / 10000)) / 100000;
	
	printf("optimized result: %lf\n", end_time - start_time);
	
	return 0;
}
