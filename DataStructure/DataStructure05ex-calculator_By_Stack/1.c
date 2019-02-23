#include <stdio.h>
#include "L"

//연산자의 연산 우선순위 정보 반환
int GetOpPrec(char op)
{
	switch (op)
	{
	case '*':
	case'/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;  // '('연산자가 우선위가 가장 낮은 이유는 ')'연산자가 나올때 까지 쟁반위에 있어야하기 때문.
	}

	return -1;
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void ConvToRPNExp(char exp[])
{
	Stack stack;
}