/*
#include "SimpleHeap.h"

void HeapInit(Heap * ph)	// 힙의 초기화
{
	ph->numOfData = 0;
}

int HIsEmpty(Heap * ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx)
{
	return idx / 2;
}

int GETLChildIDX(int idx)
{
	return idx * 2;
}

int GETRChildIDX(int idx)
{
	return GETLChildIDX(idx) + 1;
}

// 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
int GetHiPriChildIDX(Heap * ph, int idx)
{
	if (GETLChildIDX(idx) > ph->numOfData)
		return 0;
	else if (GETLChildIDX(idx) == ph->numOfData)
		return GETLChildIDX(idx);
	else
	{
		if (ph->heapArr[GETLChildIDX(idx)].pr
				> ph->heapArr[GETRChildIDX(idx)].pr)
			return GETRChildIDX(idx);
		else
			return GETLChildIDX(idx);
	}
}

void HInsert(Heap * ph, HData data, priority pr)
{
	int idx = ph->numOfData + 1;
	HeapElem nelem = { pr, data };

	while(idx != 1)
	{
		if (pr < (ph->heapArr[GetParentIDX(idx)].pr))
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}

	ph->heapArr[idx] = nelem;
	ph->numOfData += 1;
}

HData HDelete(Heap * ph)
{
	HData retData = (ph->heapArr[1]).data;
	HeapElem lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		if (lastElem.pr <= ph->heapArr[childIdx].pr)
			break;
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;

}
*/