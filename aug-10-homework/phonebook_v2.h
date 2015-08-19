#ifndef PHONEBOOK_V2
#define PHONEBOOK_V2
#include <string.h>
#include <stdlib.h>
#include "util.h"

typedef struct __PHONE_BOOK_V2 {
	    char LastName[MAX_LAST_NAME_SIZE];
	    struct __PHONE_BOOK_DETAIL *pDetail;
	    struct __PHONE_BOOK_V2 *pNext;
} PhoneBook_v2;

typedef struct __PHONE_BOOK_DETAIL {
	    char FirstName[16];
	    char email[16];
	    char phone[10];
	    char cell[10];
	    char addr1[16];
	    char addr2[16];
	    char city[16];
	    char state[2];
	    char zip[5];
} PhoneBookDetail;

PhoneBook_v2 *FindName_v2 (char Last[], PhoneBook_v2 *pHead) {
	while (pHead != NULL) {
		if (strcasecmp(Last, pHead->LastName) == 0)
			return pHead;
		pHead = pHead->pNext;
	}
	return NULL;
}


PhoneBook_v2 *append_v2(char *Name, PhoneBook_v2 *entry){
	entry->pNext = (PhoneBook_v2 *)malloc(sizeof(PhoneBook_v2));
	entry = entry->pNext;
	strcpy(entry->LastName, Name);
	entry->pNext = NULL;
	return entry;
}

#endif
