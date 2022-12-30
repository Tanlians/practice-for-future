#define _CRT_SECURE_NO_WARNINGS 01
#include<stdio.h>

int len(int d)
{
	int first_ind[1000] = { 0 };
	int ind = 0, y = 1;
	do {
		first_ind[y] = (ind++);//先给后加加
		y = (y * 10) % d;
	} while (y && first_ind[y] == 0);
	if (y == 0) return 0;
	return ind - first_ind[y];
}
int main()
{
	int max = 0, ans = 0;
	for (int i = 2; i < 1000; i++)
	{
		if (len(i) > max)
		{
		max = len(i);
		ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}