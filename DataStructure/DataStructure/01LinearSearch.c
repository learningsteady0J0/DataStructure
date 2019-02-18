/*// 순차 탐색
// 알고리즘의 시간 복잡도를 계산하기 위해 핵심이 되는 연산이 무엇인지 파악해야함. (여기서는 == 연산)
// 운이 나빠 ==연산 횟수가 가장 많을 때를 '최악의 경우'라고 하고 이를 통해 알고르짐 성능(시간복잡도)를 판단함.
// T(n) = n 최악의 경우를 대상으로 정의한 T(n) 함수.

#include <stdio.h>

int LSearch(int ar[], int len, int target)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (ar[i] == target)
			return i;
	}
	return -1;
}

int main()
{
	int arr[] = { 3,5,2,4,9 };
	int idx;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겍 저장 인덱스 : %d\n", idx);

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겍 저장 인덱스 : %d\n", idx);

}*/