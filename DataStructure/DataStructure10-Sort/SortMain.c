#include <stdio.h>
#include "SortLibary.h"

int PriComp(int n1, int n2)
{
	return n2 - n1; // �������� ����
}


	int main(void)
	{
		int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
		int i;

		// �迭 arr�� ��ü ���� ���� 
		MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

		for (i = 0; i < 7; i++)
			printf("%d ", arr[i]);

		printf("\n");
		return 0;
	}
