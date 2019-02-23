#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE		1
#define FASLE		0

#define QUE_LEN		100
typedef int Data;

typedef struct _cQueue
{
	int front;
	int rear;
	Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void EnQueue(Queue * pq, Data data);
Data DeQueue(Queue * pq);
Data QPeek(Queue * pq);

#endif
