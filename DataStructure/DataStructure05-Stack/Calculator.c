#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

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

// op1의 우선순위가 op2의 우선순위보다 높으면 1 낮으면 -1 같으면 0
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

//중위 표기법을 후위표기법으로 변환
void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char * convExp = (char*)malloc(expLen + 1);

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char)*expLen + 1); // 할당된 배열을 0으로 초기화 .... 왜굳이 0으로 초기화를 할까?
	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok)) //tok에 저장된 문자가 숫자인지 확인  ... 나중에 한자리수가 아닌 n자리수도 가능하게 변경해보기
		{
			convExp[idx++] = tok; //숫자이면 배열 convExp에 그냥 저장
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

//후위 표기법으로 변환된 식을 계산
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
			SPush(&stack, tok - '0'); // 정수면 숫자로 변환 후 스택에 push ('1' - '0' = 1)
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

// 중위 표기법의 수식의 결과를 반환해주는 함수
int EvalInfixExp(char exp[])
{
	int len = strlen(exp);
	int ret;
	char * expcpy = (char*)malloc(len + 1);  // 중위 표기법을 후위 표기법으로 변환시키기 위해 동적할당
	strcpy(expcpy, exp);

	ConvToRPNExp(expcpy);
	ret = EvalInfixExp(expcpy);

	free(expcpy);
	return ret;

}