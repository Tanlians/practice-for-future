#include<stdio.h>
#define U 4000000
int main()
{
	int a = 0, b = 1, sum = 0,s;
	for (int s = 0; s < U;)
	{
		s = a + b;
		a = b;
		b = s;
		if (s % 2 == 0)
			sum += s;
	}
	printf("<4000000偶斐波那契的和：%d\n", sum);
	return 0;
}

/*#include <stdio.h>//解2
int num[4000005];

int main() {
	num[0] = 1, num[1] = 2;
	int ans = 2;
	for (int i = 2; 1; i++) {
		num[i] = num[i - 1] + num[i - 2];
		if (num[i] > 4000000) {
			break;
		}
		if (num[i] % 2 == 0) {
			ans += num[i];
		}
	}
	printf("%d\n", ans);

	return 0;
}*/