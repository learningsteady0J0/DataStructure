/*#include <stdio.h>

int BSearch(int ar[], int first, int last, int target)
{
	int mid;
	if (first > last)
		return -1;

	mid = (first + last) / 2;
	if (ar[mid] == target)
		return mid;
	else if (ar[mid] > target)
		return BSearch(ar, first, mid - 1, target);
	else
		return BSearch(ar, mid+1, last, target);
}

int main()
{
	int ar[] = { 1,3,4,6,7,8,9,10,50,100 };
	int idx;
	idx = BSearch(ar, 0, sizeof(ar) / sizeof(int) - 1, 50);

	if (idx == -1)
		printf("Å½»ö ½ÇÆÐ!\n");
	else
		printf("idx: %d\n", idx);

	idx = BSearch(ar, 0, sizeof(ar) / sizeof(int) - 1, 11);

	if (idx == -1)
		printf("Å½»ö ½ÇÆÐ!\n");
	else
		printf("idx: %d\n", idx); 
}*/