#define _CRT_SECURE_NO_WARNINGS 01
#include <stdio.h>

int isPan(int num1, int num2);
int getDig(int num);
int main() {
    int a = 1, b = 2, sum = 0;

    while ((getDig(a) + getDig(b) + getDig(a * b)) <= 9) {
        while ((getDig(a) + getDig(b) + getDig(a * b)) <= 9) {
            b++;
            if (isPan(a, b) == 1) {
                printf("%d x %d = %d\n", a, b, a * b);
                sum += a * b;
            }
        }
        a++;
        while ((isPan(a, 0) != -2)) {
            a++;
        }
        b = a + 1;
    }
    printf("SUM=%d\n", sum);

    return 0;
}

int isPan(int num1, int num2) {
    int dig[10] = { 0 }, mul = num1 * num2, cnt = 0;
    do {
        if (num1 % 10 == 0 || dig[num1 % 10] == 1)
            return -1;
        else {
            dig[num1 % 10] = 1;
            cnt++;
        }
    } while ((num1 = num1 / 10) > 0);

    do {
        if (num2 % 10 == 0 || dig[num2 % 10] == 1)
            return -2;
        else {
            dig[num2 % 10] = 1;
            cnt++;
        }
    } while ((num2 = num2 / 10) > 0);

    do {
        if (mul % 10 == 0 || dig[mul % 10] == 1)
            return -3;
        else {
            dig[mul % 10] = 1;
            cnt++;
        }
    } while ((mul = mul / 10) > 0);

    if (cnt == 9)
        return 1;
    else
        return 2;
}

int getDig(int num) {
    int cnt = 1;
    while ((num = num / 10) > 0) {
        cnt++;
    }

    return cnt;
}