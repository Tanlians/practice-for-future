#include <stdio.h>
#include <stdint.h>
#define P 1000

uint8_t cnt[P + 1] = { 0 };
int main() {

    for (int c = 5; c < P / 2; ++c) {
        for (int b = 4; b < c; ++b) {
            for (int a = 3; a <= b; ++a) {
                if (a * a + b * b == c * c) {
                    ++cnt[a + b + c];
                }
            }
        }
    }

    int max = 0, n;
    for (int i = 1; i <= P; ++i) {
        if (cnt[i] > max) {
            max = cnt[i];
            n = i;
        }
    }
    printf("p=%d ,%d solutions\n", n, max);

    for (int c = 5; c < P / 2; ++c) {
        for (int b = 4; b < c; ++b) {
            for (int a = 3; a <= b; ++a) {
                if (a * a + b * b == c * c && a + b + c == n) {
                    printf("{%d, %d, %d} ", a, b, c);
                }
            }
        }
    }

    return 0;
}