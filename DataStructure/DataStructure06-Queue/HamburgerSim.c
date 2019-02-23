#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h" // 수용량 측정을 위해 원형 큐를 사용 (QUEUE_LEN이 대기실 크기)

#define CUS_COME_TERM	15 // 고객의 주문 간격: 초 단위

#define CHE_BUR		0 // 치즈 버거 상수
#define BUL_BUR		1 // 불고기 버거 상수
#define DUB_BUR		2 // 더블 버거 상수

#define CHE_TURM	12 // 치즈 버거 제조 시간 : 초 단위(이하동문)
#define	BUL_TURM	15 // 불고기 버거 제조 시간
#define DUB_TURM	24 // 더블 버거 제조 시간

int main(void)
{
	int makeProc = 0;  // 햄버거 제작 진행상황
	int CB_count = 0, BB_count = 0, DB_count = 0; 
	int sec; 
	Queue q;

	QueueInit(&q);
	srand(time(NULL));

	for (sec = 0; sec < 3600; sec++) //3600은 점심시간 1시간을 뜻 함.
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

	printf("시뮬레이션 결과\n");
	printf("치즈 버거 : %d   불고기 버거 : %d   더블 버거 : %d\n", CB_count, BB_count, DB_count);
	printf("대기실 크기 : %d", QUE_LEN);
	
	//만약 데이터를 초과한다는 메시지가 뜨면 수용량 초과를 뜻함.
	//10번 반복하여 9번 결과창이뜨고 1번 실패창이 뜨면 안정적으로 고객을 수용할 확률 90%!

	return 0;
}

