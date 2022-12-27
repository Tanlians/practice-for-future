#define _CRT_SECURE_NO_WARNINGS 01
#include<stdio.h>

int cal(int date)
{
	int year, m, d, w, y, c;//eg:20191130
	year = date / 10000;
	m = date % 10000 / 100;
	d = date % 100;
	y = year % 100;
	c = year / 100;
	if (m == 1 || m == 2) {
		m += 12;
		y--;
	}
	w = (y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1) % 7;
	return w;
}

int cal2(int year,int m,int d)
{
	int y, c, w;
	y = year % 100;
	c = year / 100;
	if (m == 1 || m == 2)
	{
		m += 12;
		y--;
	}
	w = (y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1) % 7;
	return w;
}

int main()
{
	int count = 0;
	for (int year = 1901; year <= 2000; year++)
		for (int m = 1; m <= 12; m++)
		{
			if(cal2(year,m,1)==6)
				count++;
		}
	printf("1901-2000共有%d个星期天", count);
}