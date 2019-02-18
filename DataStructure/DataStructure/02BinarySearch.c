/*
// 이진 탐색 알고리즘
// 배열에 저장된 데이터가 정렬이 되어 있어야 사용이 가능
// 최악의 경우 T(n)의 함수 = logn/2
// 빅-오 표기법 >> 빅-오는 함수 T(n)에서 가장 영향력이 큰 부분이 어딘가를 따지는 것
// O(n^2) 빅오 오브 엔 제곱
// 빅-오는 데이터 수의 증가에 따른 연산횟수의 증가형태를 나타내는 표기법 
// 따라서 999n^2 나 n^2나 둘은 동일  데이터수가 2,3,4개로 늘어날때 각각 연산횟수는 두배씩 늘었났기때문(99,198,396 //4,8,16)

#include <stdio.h>

int BinarySearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len-1;
	int idx;
	int opCount = 0;

	while(first <= last)
	{


		idx = (first + last)/2; //탐색 대상의 중앙을 찾는다

		if (ar[idx] == target)
			return idx;
		else
		{
			if (ar[idx] < target)
			{
				first = idx+1; // 요것이 포인트, 그냥 idx를 대입하면 그 인덱스값은 이미 처리되어있는 인덱스일 뿐만 아니라
			}				   // 이렇게 하지 않으면 무한루프가 발생 됨.  first < target < last 
			else
				last = idx-1;
		}
		opCount++;
	}
	printf("비교연산 횟수 : %d\n",opCount);
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
		printf("탐색 실패\n");
	else
		printf("idx: %d\n", idx);

	idx = BinarySearch(ar, sizeof(ar) / sizeof(int), 9);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("idx: %d\n", idx);

	idx = BinarySearch(ar2, sizeof(ar2) / sizeof(int), 1);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("idx: %d\n", idx);

	idx = BinarySearch(ar3, sizeof(ar3) / sizeof(int), 1);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("idx: %d\n", idx);
}

*/