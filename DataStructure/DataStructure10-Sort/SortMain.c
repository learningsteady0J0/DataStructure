#include <stdio.h>
#include "SortLibary.h"

int PriComp(int n1, int n2)
{
	return n2 - n1; // 오름차순 정렬
}


	int main(void)
	{
		int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
		int i;

		// 배열 arr의 전체 영역 정렬 
		MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

		for (i = 0; i < 7; i++)
			printf("%d ", arr[i]);

		printf("\n");
		return 0;
	}
