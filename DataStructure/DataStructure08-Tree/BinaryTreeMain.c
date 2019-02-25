/*
#include <stdio.h>
#include "BinaryTree.h"

void ShowInfo(BTData data);

int main(void)
{
	BTreeNode * bt1 = MakeBTreeNode();
	BTreeNode * bt2 = MakeBTreeNode();
	BTreeNode * bt3 = MakeBTreeNode();
	BTreeNode * bt4 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	PreorderTraverse(bt1, ShowInfo);
	printf("\n");
	InorderTraverse(bt1, ShowInfo);
	printf("\n");
	PostorderTraverse(bt1, ShowInfo);
	printf("\n");

	DeleteTree(bt1);


	return 0;
}

void ShowInfo(BTData data)
{
	printf("%d ", data);
}
*/