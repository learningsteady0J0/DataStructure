#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h" // ���뷮 ������ ���� ���� ť�� ��� (QUEUE_LEN�� ���� ũ��)

#define CUS_COME_TERM	15 // ���� �ֹ� ����: �� ����

#define CHE_BUR		0 // ġ�� ���� ���
#define BUL_BUR		1 // �Ұ�� ���� ���
#define DUB_BUR		2 // ���� ���� ���

#define CHE_TURM	12 // ġ�� ���� ���� �ð� : �� ����(���ϵ���)
#define	BUL_TURM	15 // �Ұ�� ���� ���� �ð�
#define DUB_TURM	24 // ���� ���� ���� �ð�

int main(void)
{
	int makeProc = 0;  // �ܹ��� ���� �����Ȳ
	int CB_count = 0, BB_count = 0, DB_count = 0; 
	int sec; 
	Queue q;

	QueueInit(&q);
	srand(time(NULL));

	for (sec = 0; sec < 3600; sec++) //3600�� ���ɽð� 1�ð��� �� ��.
	{
		if (sec % CUS_COME_TERM == 0)
		{
			switch (rand() % 3)
			{
			case CHE_BUR:
				EnQueue(&q, CHE_TURM);
				CB_count++;
				break;
			case BUL_BUR:
				EnQueue(&q, BUL_TURM);
				BB_count++;
				break;
			case DUB_BUR:
				EnQueue(&q, DUB_TURM);
				DB_count++;
				break;
			}
		}

		if (makeProc <= 0 && !QIsEmpty(&q))
			makeProc = DeQueue(&q);

		makeProc--;
	}

	printf("�ùķ��̼� ���\n");
	printf("ġ�� ���� : %d   �Ұ�� ���� : %d   ���� ���� : %d\n", CB_count, BB_count, DB_count);
	printf("���� ũ�� : %d", QUE_LEN);
	
	//���� �����͸� �ʰ��Ѵٴ� �޽����� �߸� ���뷮 �ʰ��� ����.
	//10�� �ݺ��Ͽ� 9�� ���â�̶߰� 1�� ����â�� �߸� ���������� ���� ������ Ȯ�� 90%!

	return 0;
}

