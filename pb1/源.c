#include<stdio.h>
#define U 1000
int Search(int b)
{
	if (b % 3 == 0 || b % 5 == 0)
		return b;
	else
		return 0;
}
int judge(int b)
{
	if (b % 15 == 0)
		return b;
	else
		return 0;
}
int main()
{
	int sum = 0, i = 0, c,d;
	for (i = 1; i < U; i++)
	{
		d = judge(i);
		c = Search(i);
		sum += c;
		sum -= d;
	}
	printf("%d", sum);
}