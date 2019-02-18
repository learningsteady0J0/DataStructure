#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"


NameCard * MakeNamCard(char * name, char * phone)
{
	NameCard * nameCard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(nameCard->name, name);
	strcpy(nameCard->phone, phone);

	return nameCard;
}

void ShowNameCardInfo(NameCard * pcard)
{
	printf("Name : %s \n Phone : %s \n\n",pcard->name,pcard->phone);
}

int NameCompare(NameCard*pcard, char* name)
{
	return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard* pcard, char* phone)
{
	
	strcpy(pcard->phone, phone, strlen(phone));
}
