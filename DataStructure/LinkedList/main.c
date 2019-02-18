#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "point.h"
#include "NameCard.h"

// ��� �ڷᱸ���̰� ���� '�ڷᱸ���� ����'�� '������ �ڷᱸ���� Ȱ��'�� ������ ���еǵ��� ADT�� �����ؾ��Ѵ�.
// �迭 ��� ����Ʈ�� ����
// �迭�� ���̰� �ʱ⿡ �����Ǿ�� �Ѵ�. ������ �Ұ����ϴ�.
// ������ �������� �������� �̵�(����)�� �ſ� ����� �Ͼ��.
// �螉 ��� ����Ʈ�� ����
// �������� ������ ����. �ε��� ���� �������� ���� �� ���� ������ �����ϴ�.

int main()
{
	List list;
	NameCard * pNC;
	char * name[NAME_LEN];
	char * phone[PHONE_LEN];
	int i;

	ListInit(&list);

	for (i = 0; i < 3; i++)
	{
		printf("%d ��° ��ȭ��ȣ ���� �Է� :", i + 1);
		scanf("%s %s", name, phone);
		pNC = MakeNamCard(name, phone);
		LInsert(&list, pNC);
	}
	printf("\n");

	fputs("ã�� �̸� �Է� : ", stdout);
	scanf("%s", name);

	if(LFirst(&list, &pNC))
	{
		if (NameCompare(pNC,name) == 0)
			ShowNameCardInfo(pNC);
		
		while (LNext(&list, &pNC))
		{
			if (NameCompare(pNC, name) == 0)
				ShowNameCardInfo(pNC);
		}
	}

	fputs("ã�� �̸� �Է� : ", stdout);
	scanf("%s", name);
	fputs("�ٲ� ��ȭ��ȣ �Է� : ", stdout);
	scanf("%s", phone);

	if (LFirst(&list, &pNC))
	{
		if (NameCompare(pNC, name) == 0)
			ChangePhoneNum(pNC, phone);

		while (LNext(&list, &pNC))
		{
			if (NameCompare(pNC, name) == 0)
				ChangePhoneNum(pNC, phone);
		}
	}

	fputs("ã�� �̸� �Է� : ", stdout);
	scanf("%s", name);

	if (LFirst(&list, &pNC))
	{
		if (NameCompare(pNC, name) == 0)
		{
			pNC = LRemove(&list);
			free(pNC);
		}

		while (LNext(&list, &pNC))
		{
			if (NameCompare(pNC, name) == 0)
			{
				pNC = LRemove(&list);
				free(pNC);
			}
		}
	}

	if (LFirst(&list, &pNC))
	{
		ShowNameCardInfo(pNC);

		while (LNext(&list, &pNC))
			ShowNameCardInfo(pNC);
	}
	return 0;
}



/*  typedef Point * LDatd �϶�
int main()
{
	List list;
	Point compPos;
	Point * ppos;
	int i;

	ListInit(&list);

	for (i = 1; i < 3; i++)
	{
		ppos = (Point*)malloc(sizeof(Point));
		SetPointPos(ppos, 2, i);
		LInsert(&list, ppos);

		ppos = (Point*)malloc(sizeof(Point));
		SetPointPos(ppos, 3, i);
		LInsert(&list, ppos);
	}

	printf("���� ����� ������ �� %d\n\n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}

	printf("\n");

	compPos.xPos = 2;
	compPos.yPos = 0;

	if (LFirst(&list, &ppos))
	{
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);
		}

		while (LNext(&list, &ppos))
		{
			if (PointComp(ppos, &compPos) == 1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}


	printf("���� ����� ������ �� %d\n\n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}

	return 0;
}
//  typedef int LData ���� ��
int main()
{
	List list;
	int data;
	int i;
	int sum = 0;
	ListInit(&list);

	for (i = 1; i < 10; i++)
	{
		LInsert(&list, i);
	}

	if (LFirst(&list, &data))
		sum += data;
	while (LNext(&list, &data))
		sum += data;

	printf("���� : %d\n", sum);

	if (LFirst(&list, &data))
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);
	while (LNext(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);
	}

	if (LFirst(&list, &data))
		printf("%d ", data);
	while (LNext(&list, &data))
		printf("%d ", data);

}*/
