// 파보나치 수열
/*
	f(n)  0  n==1
		  1	 n==2
		  f(n-1) + f(n-2) other number
#include <stdio.h>

int favo(int num)
{
	if (num == 1)
		return 0;
	else if (num == 2)
		return 1;
	else
		return favo(num - 1) + favo(num - 2);
}

int main(void)
{
	int i;

	for (i = 1; i < 15; i++)
	{
		printf("%d ", favo(i));
	}
}*/