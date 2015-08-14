#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_LAST_NAME_SIZE 16
#define TEST_NUMBER 200000000

struct timespec timespec;

typedef struct __PHONE_BOOK_ENTRY {
	char LastName[MAX_LAST_NAME_SIZE];
	char FirstName[16];
	char email[16];
	char phone[10];
	char cell[10];
	char addr1[16];
	char addr2[16];
	char city[16];
	char state[2];
	char zip[5];
	struct __PHONE_BOOK_ENTRY *pNext;
} PhoneBook;

PhoneBook *FindName_v1(char Last[], PhoneBook *pHead){
	while(pHead != NULL){
		if(strcasecmp(Last, pHead->LastName) == 0)
			return pHead;
		pHead = pHead->pNext;
	}
	return NULL;
}

PhoneBook *FindName_v2(char Last[], PhoneBook *pHead){
	while(pHead->LastName != NULL){
		if(strcasecmp(Last, pHead->LastName) == 0)
			return pHead;
		pHead = pHead->pNext;
	}
}

PhoneBook *append(char *Name, PhoneBook *entry){
	entry->pNext = (PhoneBook *)malloc(sizeof(PhoneBook));
	entry = entry->pNext;
	strcpy(entry->LastName, Name);
	entry->pNext = NULL;

	return entry;
}

int main(int argc, char *argv[]){
	
	FILE *fp;
	char line[MAX_LAST_NAME_SIZE];
	
	fp = fopen("dictionary/all-names.txt", "r");
	if(fp == NULL){
		puts("failed to open the file");
		return 1;		
	}

	int i = 0;
	PhoneBook *pHead, *entry, *pTarget;
	pHead = (PhoneBook *) malloc(sizeof(PhoneBook));
	entry = pHead;
	entry->pNext = NULL;
	while(fgets(line, sizeof(line), fp)){
		while((line[i] >= 'a' && line[i] <= 'z') || 
				(line[i] >= 'A' && line[i] <= 'Z')){i++;}
		line[i] = '\0';
		i = 0;
		entry = append(line, entry);
		//printf("Append name: %s\n", line);
	}
	
	long start_time, end_time;
	
	/* test the time for v1*/
	clock_gettime(CLOCK_MONOTONIC, &timespec);
	start_time = timespec.tv_sec * 1000000000LL + timespec.tv_nsec;
	pTarget = FindName_v1("zoe", pHead);
	if(pTarget != NULL){
		puts("found name");
		printf(" : %s\n", pTarget->LastName);
	}
	clock_gettime(CLOCK_MONOTONIC, &timespec);
	end_time = timespec.tv_sec * 1000000000LL + timespec.tv_nsec;
	printf("unoptimized result: %ld\n"
			, end_time - start_time);

	/* flushing the cache */
	const int size = 1024*1024;
	char *c = (char *) malloc(size);
	for(int j = 0; j < 0x1000; j++)
		for(int k = 0; k < size; k++)
			c[k] = j*k;

	/* test the time for v2*/
	clock_gettime(CLOCK_MONOTONIC, &timespec);
	start_time = timespec.tv_sec * 1000000000LL + timespec.tv_nsec;
	pTarget = FindName_v2("zoe", pHead);	
	if(pTarget != NULL){
		puts("found name");
		printf(" : %s\n", pTarget->LastName);
	}
	clock_gettime(CLOCK_MONOTONIC, &timespec);
	end_time = timespec.tv_sec * 1000000000LL + timespec.tv_nsec;
	printf("optimized result: %ld\n"
			, end_time - start_time);

	return 0;				
}


