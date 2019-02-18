// 하노이의 탑.
// 일련의 과정이 반복이라고? 그럼 재귀함수!

#include <stdio.h>

void Hanoi(int num, char from, char by, char to)
{
	if (num == 1)
	{
		printf("블럭 1이 %c에서 %c로 이동했습니다.\n", from, to);
	}
	else
	{
		Hanoi(num - 1, from, to, by);
		printf("블럭 %d이 %c에서 %c로 이동했습니다.\n",num, from, to);
		Hanoi(num - 1, by, from, to);
	}
}

int main()
{
	Hanoi(5, 'A', 'B', 'C');
	return 0;
}