#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

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

// op1�� �켱������ op2�� �켱�������� ������ 1 ������ -1 ������ 0
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

//���� ǥ����� ����ǥ������� ��ȯ
void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char * convExp = (char*)malloc(expLen + 1);

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char)*expLen + 1); // �Ҵ�� �迭�� 0���� �ʱ�ȭ .... �ֱ��� 0���� �ʱ�ȭ�� �ұ�?
	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok)) //tok�� ����� ���ڰ� �������� Ȯ��  ... ���߿� ���ڸ����� �ƴ� n�ڸ����� �����ϰ� �����غ���
		{
			convExp[idx++] = tok; //�����̸� �迭 convExp�� �׳� ����
		}
		else
		{
			switch (tok)
			{
			case '(' :
				SPush(&stack, tok);
				break;
			case ')' :
				while (1)
				{
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;
			case '+': case '-':
			case '*': case '/':
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);
				SPush(&stack, tok);
				break;
			}

		}
	}
	while (!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp);
	free(convExp);
}

//���� ǥ������� ��ȯ�� ���� ���
int EvalRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;

	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok))
			SPush(&stack, tok - '0'); // ������ ���ڷ� ��ȯ �� ���ÿ� push ('1' - '0' = 1)
		else
		{
			op2 = SPop(&stack);
			op1 = SPop(&stack);
			switch (tok)
			{
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			
			}

		}
	}
	return SPop(&stack);
}

// ���� ǥ����� ������ ����� ��ȯ���ִ� �Լ�
int EvalInfixExp(char exp[])
{
	int len = strlen(exp);
	int ret;
	char * expcpy = (char*)malloc(len + 1);  // ���� ǥ����� ���� ǥ������� ��ȯ��Ű�� ���� �����Ҵ�
	strcpy(expcpy, exp);

	ConvToRPNExp(expcpy);
	ret = EvalInfixExp(expcpy);

	free(expcpy);
	return ret;

}