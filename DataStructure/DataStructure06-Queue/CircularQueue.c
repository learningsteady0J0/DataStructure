
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

// 배열 인덱스가 끝에 도달했는지 판단하고 끝이면 0을 끝이 아니면 인덱스 +1를 반환하는 함수
int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void EnQueue(Queue * pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front)  //큐가 꽉 찼을 시
	{
		printf("데이터가 꽉 차 있습니다.");
		exit(-1);
	}
	
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data DeQueue(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		printf("데이터가 비어 있습니다.");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		printf("데이터가 비어 있습니다.");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}
