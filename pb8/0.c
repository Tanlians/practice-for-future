#define _CRT_SECURE_NO_WARNINGS 01
#include<stdio.h>

char num[1005];

int main() {
	scanf("%s", num);
	long long now = 1, ans = 0, zero_cnt = 0;
	for (int i = 0; i < 1000; i++) {
		if (i < 13) {
			now *= num[i] - '0';
		}
		else {
			if (num[i] == '0') {
				zero_cnt++;
			}
			else {
				now *= num[i] - '0';
			}
			if (num[i - 13] == '0') {
				zero_cnt--;
			}
			else {
				now /= num[i - 13] - '0';
			}
		}
		if (zero_cnt == 0 && ans < now) {
			ans = now;
		}
	}
	printf("%lld\n", ans);

	return 0;
}

//#include<stdio.h>
//int main()
//{
//	char a[1005];
//	scanf("%s", &a);
//	long long now = 1, ans = 0, k = 0;
//	for (k = 0; k < 1000; k++)
//	{
//		now *= (a[k] * a[k + 1]  * a[k + 2]  * a[k + 3]  * a[k + 4]  * a[k + 5]  * a[k + 6] * a[k + 7]  * a[k + 8]  * a[k + 9]  * a[k + 10]  * a[k + 11] * a[k + 12]  * a[k + 13] );
//		if (now > ans)
//			ans = now;
//	}
//	printf("%lld\n", ans);
//	return 0;
//}