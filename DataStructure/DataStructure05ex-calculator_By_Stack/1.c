#include <stdio.h>
#include "L"

//�������� ���� �켱���� ���� ��ȯ
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
		return 1;  // '('�����ڰ� �켱���� ���� ���� ������ ')'�����ڰ� ���ö� ���� ������� �־���ϱ� ����.
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