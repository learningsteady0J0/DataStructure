#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE		1
#define FALSE		0

#define HEAP_LEN	100

typedef char HData;
typedef int  priority;

typedef struct _heapElem
{
	priority pr;	// 값이 작을수록 높은 우선순위
	HData data;
} HeapElem;
  
typedef struct _heap
{
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap * ph);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data, priority pr);
HData HDelete(Heap * ph);

#endif