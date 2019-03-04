#include <stdio.h>

int ISearch(int ar[], int first, int last, int target)
{
	int standard;

	if (ar[last] < target || target < ar[first]);
		return -1;

	standard = ((double)(target - ar[first]) / (ar[last] - ar[first]) * (last - first)) + first;

	if (ar[standard] == target)
		return standard;
	else if (target < ar[standard])
		return ISearch(ar, first, standard - 1, target);
	else
		return ISearch(ar, standard+1, last, target);
}

int main(void)
{
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ\n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º : %d \n", idx);

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 2);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ\n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º : %d \n", idx);

	return 0;
}