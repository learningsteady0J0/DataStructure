#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "point.h"
#include "NameCard.h"

// 어떠한 자료구조이건 간에 '자료구조의 구현'과 '구현된 자료구조의 활용'은 완전히 구분되도록 ADT를 정의해야한다.
// 배열 기반 리스트의 단점
// 배열의 길이가 초기에 결정되어야 한다. 변경이 불가능하다.
// 삭제의 과정에서 데이터의 이동(복사)가 매우 빈번히 일어난다.
// 배엵 기반 리스트의 장점
// 데이터의 참조가 쉽다. 인덱스 값을 기준으로 어디든 한 번에 참조가 가능하다.

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
		printf("%d 번째 전화번호 정보 입력 :", i + 1);
		scanf("%s %s", name, phone);
		pNC = MakeNamCard(name, phone);
		LInsert(&list, pNC);
	}
	printf("\n");

	fputs("찾을 이름 입력 : ", stdout);
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

	fputs("찾을 이름 입력 : ", stdout);
	scanf("%s", name);
	fputs("바꿀 전화번호 입력 : ", stdout);
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

	fputs("찾을 이름 입력 : ", stdout);
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



/*  typedef Point * LDatd 일때
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

	printf("현재 저장된 데이터 수 %d\n\n", LCount(&list));

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


	printf("현재 저장된 데이터 수 %d\n\n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}

	return 0;
}
//  typedef int LData 였을 때
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

	printf("총합 : %d\n", sum);

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
