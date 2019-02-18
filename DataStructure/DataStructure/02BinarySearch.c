/*
// ���� Ž�� �˰���
// �迭�� ����� �����Ͱ� ������ �Ǿ� �־�� ����� ����
// �־��� ��� T(n)�� �Լ� = logn/2
// ��-�� ǥ��� >> ��-���� �Լ� T(n)���� ���� ������� ū �κ��� ��򰡸� ������ ��
// O(n^2) ��� ���� �� ����
// ��-���� ������ ���� ������ ���� ����Ƚ���� �������¸� ��Ÿ���� ǥ��� 
// ���� 999n^2 �� n^2�� ���� ����  �����ͼ��� 2,3,4���� �þ�� ���� ����Ƚ���� �ι辿 �þ����⶧��(99,198,396 //4,8,16)

#include <stdio.h>

int BinarySearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len-1;
	int idx;
	int opCount = 0;

	while(first <= last)
	{


		idx = (first + last)/2; //Ž�� ����� �߾��� ã�´�

		if (ar[idx] == target)
			return idx;
		else
		{
			if (ar[idx] < target)
			{
				first = idx+1; // ����� ����Ʈ, �׳� idx�� �����ϸ� �� �ε������� �̹� ó���Ǿ��ִ� �ε����� �Ӹ� �ƴ϶�
			}				   // �̷��� ���� ������ ���ѷ����� �߻� ��.  first < target < last 
			else
				last = idx-1;
		}
		opCount++;
	}
	printf("�񱳿��� Ƚ�� : %d\n",opCount);
	return -1;
}

int main(void)
{
	int ar[] = { 1,2,6,7,9,11,12,15,17,19 };
	int ar2[500] = { 0 };
	int ar3[5000] = { 0 };
	int idx;

	idx = BinarySearch(ar, sizeof(ar) / sizeof(int), 5);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("idx: %d\n", idx);

	idx = BinarySearch(ar, sizeof(ar) / sizeof(int), 9);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("idx: %d\n", idx);

	idx = BinarySearch(ar2, sizeof(ar2) / sizeof(int), 1);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("idx: %d\n", idx);

	idx = BinarySearch(ar3, sizeof(ar3) / sizeof(int), 1);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("idx: %d\n", idx);
}

*/