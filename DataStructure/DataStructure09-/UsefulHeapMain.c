/*
#include <stdio.h>
#include "UsefulHeap.h"

// 우선순위 비교함수 첫번째 인자의 우선순위가 높다면 0보다 큰 값 반환 
// 여기서는 문자를 넣기 때문에 ch2 -ch1  =>  'B' - 'A' = 1    
int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1;
}

int main(void)
{
	Heap heap;
	HeapInit(&heap, DataPriorityComp);

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));

	while (!HIsEmpty(&heap))
		printf("%c \n", HDelete(&heap));

	return 0;
}
*/