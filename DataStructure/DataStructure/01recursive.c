/*
//Àç±ÍÇÔ¼ö

   n! = n x n-1 x n-2 x .... x 2 x 1
   n! = n x (n-1)!
									
	f(n) n>=1  n x f(n-1)									
		 n==0     1							
									
#include <stdio.h>

int Factorial(int num)
{
	if (num == 0)
		return 1;
	else
		return num * Factorial(num - 1);
}

int main()
{
	printf("%d", Factorial(10));
}*/