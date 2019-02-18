// �ϳ����� ž.
// �Ϸ��� ������ �ݺ��̶��? �׷� ����Լ�!

#include <stdio.h>

void Hanoi(int num, char from, char by, char to)
{
	if (num == 1)
	{
		printf("�� 1�� %c���� %c�� �̵��߽��ϴ�.\n", from, to);
	}
	else
	{
		Hanoi(num - 1, from, to, by);
		printf("�� %d�� %c���� %c�� �̵��߽��ϴ�.\n",num, from, to);
		Hanoi(num - 1, by, from, to);
	}
}

int main()
{
	Hanoi(5, 'A', 'B', 'C');
	return 0;
}