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
		printf("���ڸ� �Է����ּ���");
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
		printf("�����Ͱ� �������� �ʽ��ϴ�.");
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