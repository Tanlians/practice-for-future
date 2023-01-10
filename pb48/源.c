
#include <stdio.h>

long long int selfpow(int x);

int main()
{
    long long int sum = 0;
    for (int i = 1; i <= 1000; ++i) {
        sum += selfpow(i);
        sum %= 10000000000;
    }
    printf("%lld\n", sum);

    return 0;
}

long long int selfpow(int x) {
    int i;
    long long int y = (long long)x;
    for (i = 1; i < x; ++i) {
        y *= (long long)x;
        y %= 10000000000;
    }

    return y;
}