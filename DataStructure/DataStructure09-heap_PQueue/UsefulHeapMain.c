/*
#include <stdio.h>
#include "UsefulHeap.h"

// �켱���� ���Լ� ù��° ������ �켱������ ���ٸ� 0���� ū �� ��ȯ 
// ���⼭�� ���ڸ� �ֱ� ������ ch2 -ch1  =>  'B' - 'A' = 1    
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