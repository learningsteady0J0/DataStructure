#include <stdlib.h>
#include <stdio.h>
#include "Deque.h"

void DequeInit(Deque * pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque * pdeq)
{
	if (pdeq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque * pdeq, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pdeq->head;
	newNode->prev = NULL;

	if (DQIsEmpty(pdeq))
	{
		pdeq->tail = newNode;
	}
	else
	{
		pdeq->head->prev = newNode;
	}
	
	pdeq->head = newNode;
	
}
void DQAddLast(Deque * pdeq, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = pdeq->tail;

	if (DQIsEmpty(pdeq))
	{
		pdeq->head = newNode;
	}
	else
	{
		pdeq->tail->next = newNode;
	}

	pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque * pdeq)
{
	Data rdata;
	Node * delNode;

	if (DQIsEmpty(pdeq))
	{
		printf("데이터가 없습니다.");
		exit(-1);
	}
	else
	{
		rdata = pdeq->head->data;
		delNode = pdeq->head;

		pdeq->head = pdeq->head->next;
		free(delNode);

		if (pdeq->head == NULL)
			pdeq->tail = NULL;
		else
			pdeq->head->prev = NULL;

		return rdata;
	}
}
Data DQRemoveLast(Deque * pdeq)
{
	Data rdata;
	Node * delNode;

	if (DQIsEmpty(pdeq))
	{
		printf("데이터가 없습니다.");
		exit(-1);
	}
	else
	{
		rdata = pdeq->tail->data;
		delNode = pdeq->tail;

		pdeq->tail = pdeq->tail->prev;
		free(delNode);

		if (pdeq->tail == NULL)
			pdeq->head = NULL;
		else
			pdeq->tail->next = NULL;

		return rdata;
	}
}

Data DQGetFirst(Deque * pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("데이터가 없습니다.");
		exit(-1);
	}
	
	return pdeq->head->data;
}

Data DQGetLast(Deque * pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("데이터가 없습니다.");
		exit(-1);
	}

	return pdeq->tail->data;
}
