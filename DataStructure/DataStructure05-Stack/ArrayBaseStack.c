/*
#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	if (pstack->topIndex < STACK_LEN - 1)
	{
		(pstack->topIndex)++;
		pstack->stackArr[pstack->topIndex] = data;
	}
}

Data SPop(Stack * pstack)
{
	int rIdx;

	if (SIsEmpty(pstack))
	{
		printf("데이터 저장이 되어있지 않습니다.");
		exit(-1);
	}
	else
	{
		rIdx = pstack->topIndex;
		(pstack->topIndex)--;

		return pstack->stackArr[rIdx];
	}
}

Data SPeek(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("데이터 저장이 되어있지 않습니다.");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}
*/