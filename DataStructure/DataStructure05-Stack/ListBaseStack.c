#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data SPop(Stack * pstack)
{
	Data rdata = pstack->head->data;
	Node * delNode = pstack->head;

	if (SIsEmpty(pstack))
	{
		printf("데이터가 엄습니다");
		exit(-1);
	}

	pstack->head = pstack->head->next;

	free(delNode);

	return rdata;
}

Data SPeek(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("데이터가 엄습니다");
		exit(-1);
	}

	return pstack->head->data;
}