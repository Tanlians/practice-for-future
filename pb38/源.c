#include <stdio.h>
#define M 100000000

int isPandigital(int num);
int main() {

    int sum = 0, p, n = 1;
    for (int i = 1; i < M; ++i) {
        p = isPandigital(i);
        sum = p > sum ? n = i, p : sum;
    }

    printf("%d, %d\n", n, sum);

    return 0;
}

int isPandigital(int num) {
    int digit[10] = { 0 };
    int sum = 0, y = num;
    do {
        int x = y, mul = 1;
        do {
            int d = x % 10;
            if (d != 0 && !digit[d]) {
                digit[d] = 1;
                ++digit[0];
            }
            else
                return 0;
        } while ((x /= 10) > 0);
        for (int i = 1; i <= 9 - digit[0]; ++i) {
            mul *= 10;
        }
        sum += mul * y;
        y += num;
    } while (digit[0] < 9);

    return sum;
}