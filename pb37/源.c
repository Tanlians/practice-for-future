#include <stdio.h>
#define M 1000000

_Bool trun(int num);
_Bool notPrime[M] = { 1,1 };
int main() {

    int prime[M / 10] = { 0 }, cnt = 0, sum = 0;
    for (int i = 2; i < M; ++i) {
        if (cnt == 11) break;
        if (!notPrime[i]) {
            prime[++prime[0]] = i;
            if (trun(i)) sum += i, printf("%d ", i), ++cnt;
        }
        for (int j = 1; i * prime[j] < M; ++j) {
            notPrime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }

    printf("\n\nsum is %d\n", sum);

    return 0;
}

_Bool trun(int num) {
    int x = num, y = num, m = 1;
    if (num < 10) return 0;
    while (y /= 10) {
        if (notPrime[y]) return 0;
        m *= 10;
        x = num % m;
        if (notPrime[x]) return 0;
    }

    return 1;
}