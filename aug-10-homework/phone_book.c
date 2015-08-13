#include <time.h>
#include <string.h>
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

PhoneBook *pBook[TEST_NUMBER];

void init(int number){
	int i;
	for(i = 1; i < number; i++){
		strcpy(pBook[i-1]->LastName, "wrong-name");
		pBook[i-1]->pNext = pBook[i];
	}
	strcpy(pBook[i]->LastName, "correct-name");
}

PhoneBook *FindName_v1(char Last[], PhoneBook *pHead){
	while(pHead != NULL){
		if(strcasecmp(Last, pHead->LastName) == 0)
			return pHead;
		pHead = pHead->pNext;
	}
	return NULL;
}

PhoneBook *FindName_v2(char Last[], PhoneBook *pHead){
	while(pHead != NULL){
		if(strcasecmp(Last, pHead->LastName) == 0)
			return pHead;
		pHead = pHead->pNext;
	}
	return NULL;
}

int main(int argc, char *argv[]){
	long start_time, end_time;

	clock_gettime(CLOCK_MONOTONIC, &timespec);
	start_time = timespec.tv_sec * 1000000000LL + timespec.tv_nsec;
	FindName_v1("correct-name", pBook[0]);
	end_time = timespec.tv_sec * 1000000000LL + timespec.tv_nsec;
	printf("unoptimized result: %ld\n", end_time - start_time);

	clock_gettime(CLOCK_MONOTONIC, &timespec);
	start_time = timespec.tv_sec * 1000000000LL + timespec.tv_nsec;
	FindName_v2("correct-name", pBook[0]);
	end_time = timespec.tv_sec * 1000000000LL + timespec.tv_nsec;
	printf("optimized result: %ld\n", end_time - start_time);

	return 0;				
}


