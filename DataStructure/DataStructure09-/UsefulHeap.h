#ifndef __USEFULL_HEAP__
#define __USEFULL_HEAP__

#define TRUE		1
#define FALSE		0

#define HEAP_LEN	100

typedef char HData;
typedef int priorityComp(HData d1, HData d2);

typedef struct _heap
{
	priorityComp * comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap * ph, priorityComp pc);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);

#endif