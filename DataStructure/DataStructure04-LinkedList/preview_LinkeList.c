/*
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next;
}Node;

int main(void)
{
	Node * head = (Node*)malloc(sizeof(Node));
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int num;
	head->next = NULL;

	while (1)
	{
		printf("숫자를 입력해주세요.");
		scanf("%d", &num);

		if (num < 0)
			break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = num;
		newNode->next = NULL;
		
		if (head->next == NULL)
			head->next = newNode;
		else
			tail->next = newNode;

		tail = newNode;
	}

	if (head == NULL)
		printf("데이터가 없습니다.");
	else
	{
		cur = head;

		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}



	if (head == NULL)
		return 0;
	else
	{
		Node * delNode = head;
		Node * delNodeNext = head->next;

		free(delNode); // 더미노드 지우기

		while (delNodeNext != NULL)
		{
			delNode = delNodeNext;
			delNodeNext = delNodeNext->next;

			printf("%d데이터를 지웁니다.\n", delNode->data);
			free(delNode);

		}
	}
}

*/