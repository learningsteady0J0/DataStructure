#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "ListBaseStack.h"
#include "ExpressionTree.h"

BTreeNode * MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode * pnode;

	int i , len;
	
	StackInit(&stack);
	len = strlen(exp);
	
	for (i = 0; i < len; i++)
	{
		pnode = MakeBTreeNode();

		if(isdigit(exp[i]))                // 숫자라면
		{
			SetData(pnode, exp[i] - '0');
		}
		else							  // 연산자라면
		{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}
		SPush(&stack, pnode);
	}
	return SPop(&stack); // 루트 노드 반환
}

int EvaluateExpTree(BTreeNode * bt)
{
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);

	int op1 = EvaluateExpTree(GetLeftSubTree(bt));
	int op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt)
{
	if (bt == NULL)
		return;

	ShowInfixTypeExp(bt->left);

	if (!(0 <= bt->data && bt->data <= 9))
	{
		printf("( %d %c ", bt->left->data, bt->data);
	}

	ShowInfixTypeExp(bt->right);
	if (!(0 <= bt->data && bt->data <= 9))
	{
		if (0 <= bt->right->data && bt->right->data <= 9)
			printf("%d ", bt->right->data);
		
		printf(")");
	}
}

void ShowPostfixTypeExp(BTreeNode * bt)
{
	PostorderTraverse(bt, ShowNodeData);
}