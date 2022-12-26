#define _CRT_SECURE_NO_WARNINGS 01
#define MAX 105
#include<stdio.h>

int f[MAX][MAX] = { 0 };
int m[MAX][MAX] = { 0 };

int main()
{
	for(int i=0;i<15;i++){
		for (int j = 0; j <= i; j++)
		{
			scanf("%d",&m[i][j]);
		}
 }
	for (int j = 0; j < 15; j++)
	{
		f[14][j] = m[14][j];
		}
	for (int i = 13; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			f[i][j] = m[i][j];
			if(f[i+1][j]>f[i+1][j+1])
			{
				f[i][j] += f[i + 1][j];
			}
			else {
				f[i][j] += f[i + 1][j + 1];
			}
		}
	}
	printf("%d", f[0][0]);
	return 0;
}

