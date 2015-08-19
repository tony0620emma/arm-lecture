#ifndef PHONEBOOK_V1
#define PHONEBOOK_V1
#include <string.h>
#include <stdlib.h>
#include "util.h"

typedef struct __PHONE_BOOK_V1 {
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
	struct __PHONE_BOOK_V1 *pNext;
} PhoneBook_v1;

PhoneBook_v1 *FindName_v1(char Last[], PhoneBook_v1 *pHead) {
	while (pHead != NULL) {
		if (strcasecmp(Last, pHead->LastName) == 0)
			return pHead;
		pHead = pHead->pNext;
	}
	return NULL;
}

PhoneBook_v1 *append_v1(char *Name, PhoneBook_v1 *entry){
	entry->pNext = (PhoneBook_v1 *)malloc(sizeof(PhoneBook_v1));
	entry = entry->pNext;
	strcpy(entry->LastName, Name);
	entry->pNext = NULL;
	return entry;
}

#endif
