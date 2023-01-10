#define _CRT_SECURE_NO_WARNINGS 01
#include <stdio.h>

#define MAX 1000000

int prime[MAX] = { 0 };
_Bool notPrime[MAX + 10] = { 1,1 };

void getPrime(void);

int main()
{
    getPrime();
    int max[6] = { 0 };
    for (int i = 1; prime[i] < MAX; ++i) {
        int j = i, sum = 0, cnt = 0;
        max[0] = 0;
        while ((sum += prime[j]) < MAX) {
            ++cnt;
            if (!notPrime[sum]) {
                if (cnt > max[0]) {
                    max[0] = cnt;
                    max[1] = sum;
                    max[2] = prime[i];
                    //printf("%d %d %d\n", max[0], max[1], max[2]);
                }
            }
            ++j;
        }
        if (max[0] > max[3]) {
            max[3] = max[0];
            max[4] = max[1];
            max[5] = max[2];
            //printf("$$%d %d %d\n", max[3], max[4], max[5]);
        }
    }
    printf("%d contains %d(from:%d) terms\n", max[4], max[3], max[5]);

    return 0;
}

void getPrime(void)
{
    for (int i = 2; i < MAX + 10; ++i) {
        if (!notPrime[i])
            prime[++prime[0]] = i;
        for (int j = 1; i * prime[j] < MAX + 10; ++j) {
            notPrime[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}