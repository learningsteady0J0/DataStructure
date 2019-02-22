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
	Node * head = NULL;
	Node * cur = NULL;

	Node * newNode;
	int num;

	while (1)
	{
		printf("숫자를 입력해주세요");
		scanf("%d", &num);

		if (num < 0)
			break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = num;
		newNode->next = NULL;

		if (head != NULL)
			newNode->next = head;
		head = newNode;
	}

	if (head == NULL)
		printf("데이터가 존재하지 않습니다.");
	else
	{
		cur = head;
		printf("%d ", cur->data);
	}

	while (cur->next != NULL)
	{
		cur = cur->next;
		printf("%d ", cur->data);
	}
}*/