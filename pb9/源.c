#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int a, b, c, d;
	int u = 1;
		for (int i = 1; i < 40&&u; i++)
		{
			for (int j = i + 1; j <= 40&&u; j++)
			{
				b = j * j - i * i;
				a = 2 * i * j;
				c = i * i + j * j;
				if (1000 % (a + b + c) == 0)
				{
					printf("%d\t%d\t%d", a,b,c);
					u = 0;
				}
			}
		}
			return 0;
}