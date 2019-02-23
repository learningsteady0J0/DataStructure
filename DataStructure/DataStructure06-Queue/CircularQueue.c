
#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue * pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue * pq)
{
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FASLE;
}

// �迭 �ε����� ���� �����ߴ��� �Ǵ��ϰ� ���̸� 0�� ���� �ƴϸ� �ε��� +1�� ��ȯ�ϴ� �Լ�
int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void EnQueue(Queue * pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front)  //ť�� �� á�� ��
	{
		printf("�����Ͱ� �� �� �ֽ��ϴ�.");
		exit(-1);
	}
	
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data DeQueue(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		printf("�����Ͱ� ��� �ֽ��ϴ�.");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		printf("�����Ͱ� ��� �ֽ��ϴ�.");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}
