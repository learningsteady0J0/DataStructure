#include <stdio.h>
#include <stdlib.h>
#include "UsefulHeap.h"

void BubbleSort(int arr[], int len)
{
	int i, j;
	int temp;


	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void SelSort(int arr[], int len)
{
	int i, j;
	int temp, MaxIdx;

	for (i = 0; i < len - 1; i++)
	{
		MaxIdx = i;
		for (j = i+1; j < len; j++)
		{
			if (arr[j] < arr[MaxIdx])
				MaxIdx = j;
		}
		temp = arr[i];
		arr[i] = arr[MaxIdx];
		arr[MaxIdx] = temp;
	}
}

void InserSort(int arr[], int len)
{
	int i,j;
	int insert;

	for (i = 1; i < len; i++)
	{
		insert = arr[i];
		for (j = i-1; j >= 0; j--)
		{
			if (insert < arr[j])
				arr[j + 1] = arr[j];
			else
				break;
		}

		arr[j + 1] = insert;
	}
}


void HeapSort(int arr[], int n, priorityComp pc)
{
	Heap heap;
	int i;

	HeapInit(&heap,pc);

	for (i = 0; i < n; i++)
		HInsert(&heap, arr[i]);

	for (i = 0; i < n; i++)
		arr[i] = HDelete(&heap);
}

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fidx = left;
	int ridx = mid + 1;
	int i;

	int * sortArr = (int*)malloc(sizeof(int) * (right+1));
	int sidx = left;

	while (fidx <= mid && ridx <= right)
	{
		if (arr[fidx] <= arr[ridx])
			sortArr[sidx] = arr[fidx++];
		else
			sortArr[sidx] = arr[ridx++];

		sidx++;
	}

	if (fidx > mid)
	{
		for (i = ridx; i <= right; i++, sidx++)
			sortArr[sidx] = arr[i];
	}
	else
	{
		for (i = fidx; i <= mid; i++, sidx++)
			sortArr[sidx] = arr[i];
	}

	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)  // left가 작다는 것은 더 나눌 수 있다는 것.
	{
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}

}

