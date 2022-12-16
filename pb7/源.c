//#include<stdio.h>
//int main()
//{
//	int count = 0;
//	int a = 2;
//	while (count < 10001)
//	{
//		int i;
//		for(a=2;a<200010;a++)
//			for (i = 2; i < a; i++)
//			{
//				if (a % i == 0) {
//					if (a == i)
//						count++;
//				}
//			}
//	}
//	printf("%d", a);
//	return 0;
//}

//#include <stdio.h>
//
//#define MAX 1000000
//
//int main()
//{
//    int prime[10002] = { 0 };
//    _Bool notPrime[MAX] = { 1,1 };
//
//    for (int i = 2; i < MAX; ++i) {
//        if (!notPrime[i]) {
//            prime[++prime[0]] = i;
//            if (prime[0] == 10001) {
//                printf("%d", i);
//                break;
//            }
//        }
//        for (int j = 1; i * prime[j] < MAX; ++j) {
//            notPrime[i * prime[j]] = 1;
//            if (i % prime[j] == 0)
//                break;
//        }
//    }
//
//    return 0;
//}
#include<stdio.h>
#define MAX_N 200000

int prime[MAX_N + 5] = { 0 };
void init_prime() {
	for (int i = 2; i <= MAX_N; i++) {
		if (prime[i]) continue;
		prime[++prime[0]] = i;
		for (int j = i, I = MAX_N / i; j <= I; j++) {
			prime[i * j] = 1;
		}
	}
	return;
}

int main() {
	init_prime();
	printf("%d\n", prime[10001]);
	return 0;
}