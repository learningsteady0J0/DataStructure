/*
#include <stdio.h>
#include <stdlib.h>

typedef struct __node
{
	int data;
	struct __node * next;
} Node;

int main(void)
{
	Node * head = (Node*)malloc(sizeof(Node));
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int data;

	tail = head;


	while (1)
	{
		scanf("%d", &data);
		if (data < 0)
			break;
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = NULL;
		
		tail->next = newNode;
		tail = newNode;
	}

		cur = head;
		while (cur->next!=NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	
	printf("\n\n");

\
		Node * delNode;
		Node * delNextNode;

		delNextNode = head->next;
		
		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNode->next;

			printf("%d »èÁ¦\n", delNode->data);
			free(delNode);
		}


	return 0;


}
*/