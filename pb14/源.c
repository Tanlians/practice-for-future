#include <stdio.h>
#include <inttypes.h>

#define max 1000000

int clain_len(int64_t num) {
	if (num == 1) return 1;
	if (num % 2 == 0) {
		return clain_len(num / 2) + 1;
	}
	else {
		return clain_len(num * 3 + 1) + 1;
	}
}

int chat(int a)
{
	while (a != 1)
	{
		if (a % 2 == 0)
		{
			printf("->%d", a);
			chat(a / 2);
			break;
		}
		else
		{
			printf("->%d", a);
			chat(a * 3 + 1);
			break;
		}
	}
}

int main() {
	int ans = 0;
	int ans_len = 0;
	for (int i = 1; i < max; i++) {
		int store = clain_len(i);
		if (ans_len < store) {
			ans_len = store;
			ans = i;
		}
	}
	printf("%d %d\n", ans_len, ans);
	return 0;
}

//int main()
//{
//	for (int i = 1; i <= 13; i++)
//	{
//		chat(i);
//		printf("->%d\n", 1);
//	}
//	return 0;
//}