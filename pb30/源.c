#define _CRT_SECURE_NO_WARNINGS 01
#include<stdio.h>
#include<math.h>
#include<inttypes.h>
#include<stdbool.h>
#define max 354264//9µÄ5´Î·½ * 6

bool find(int32_t x)
{
	int32_t sum = 0;
	int32_t num = x;
	for (int i = 1; x != 0; i++)
	{
		double z = x % 10;
		x = x / 10;
		sum = sum + (int)pow(z, 5);
	}
	if (sum == num) return true;
	else return false;
}

//int32_t main()
//{
//	int32_t num = 0;
//	for (int32_t i = 2; i <= max; i++)
//	{
//		if (find)
//		{
//			num += i;
//		}
//	}
//	printf("%d\n", num);
//	return 0;
//}



int32_t isfine(int32_t num) {
	int32_t sum = 0, store = num;
	while (num) {
		sum += (int)pow(num % 10, 5);
		num /= 10;
	}
	return sum == store;
}

int32_t main() {
	int32_t sum = 0;
	for (int32_t i = 2; i <= max; i++) {
		if (isfine(i)) sum += i;
	}
	printf("%d\n", sum);

	return 0;
}

