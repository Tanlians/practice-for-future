#include<stdio.h>
#include<stdbool.h>
bool huiwen(int n)
{
	int a[6];
	int j = 0;
	int i = 0;
	while (n != 0)
	{
		if (n / 10 != 0)
		{
			a[i] = n % 10;
			n = n / 10;
			i++;
		}
		else {
			a[i] = n;
			n = n / 10;
		}
	}
	while (j <= i)
	{
		if (a[i] == a[i - j])
			j++;
		else
			return false;
	}
	return true;
}
int main() {

	int res = 0;
	for (int i = 100; i < 1000; i++) {

		for (int j = 100; j < 1000; j++) {

			if (huiwen(i * j)) {

				if (i * j >= res) {

					res = i * j;
				}
			}
		}
	}

	printf("%d", res);
	return 0;
}