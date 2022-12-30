#define _CRT_SECURE_NO_WARNINGS 01

#include <stdio.h>
#include<stdbool.h>
#include <limits.h>

#include <inttypes.h>

#include <time.h>

#include <stdlib.h>
#define MAX_N 1000
#define MAX_M 2500
#define R_M_TEST_ROUND 30

int prime[MAX_M + 5] = { 0 };
int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}
bool R_M_TEST(int x) {
    if (x <= 1) return false;
    int64_t a, m, ans;
    for (int i = 0; i < R_M_TEST_ROUND; i++) {
        a = (rand() % (x - 1)) + 1;
        ans = 1;
        m = x - 1;
        while (m) {
            if (m % 2) ans = (ans * a) % x;
            a = (a * a) % x;
            m /= 2;
        }
        if (ans != 1) return false;
    }
    return true;
}
int HowManyPrime(int a, int b) {
    int i = 0;
    while (R_M_TEST(i * i + a * i + b)) ++i;
    return i;
}

int main() {
    srand(time(0));
    prime[1] = INT_MAX;
    for (int i = 2; i <= MAX_M; i++)
        if (!prime[i])
            for (int j = i; j <= MAX_M; j += i)
                if (!prime[j]) prime[j] = i;
    int maxNum = 40, tempNum, result = 0;
    for (int a = 1 - MAX_N; a < MAX_N; a++)
        for (int b = (a < 0 ? -a + 1 : 2); b < MAX_N; b++) {
            if (prime[b] != b) continue;
            if (prime[b + a + 1] != b + a + 1) continue;
            if (a > 0 && b > 0 && prime[gcd(a, b)] <= maxNum) continue;
            tempNum = HowManyPrime(a, b);
            if (tempNum > maxNum) {
                result = a * b;
                maxNum = tempNum;
            }
        }
    printf("%d\n", result);
    return 0;

}

//#include <stdio.h>
//#define M 30000  //尝试建立足够大的质数检测列表
//
//int main() {
//    _Bool arr[M] = { 1,1,0 };
//    int pri[M] = { 0 };
//    for (int i = 2; i <= M; ++i) {
//        if (!arr[i]) {
//            pri[++pri[0]] = i;
//        }
//        for (int j = 1; i * pri[j] <= M; ++j) {
//            arr[i * pri[j]] = 1;
//            if (i % pri[j] == 0)
//                break;
//        }
//    }
//    int x = 0, cnt = 0, max = 0, var[3] = { 0 }, f;
//    for (int i = -999; i <= 0; ++i) {
//        for (int j = 0; j <= 1000; ++j) {
//            f = x * x + i * x + j;
//            while (f > 1 && !arr[f]) {
//                cnt++;
//                x++;
//                f = x * x + i * x + j;
//            }
//            if (cnt > max) {
//                max = cnt;
//                var[0] = max;
//                var[1] = i;
//                var[2] = j;
//            }
//            cnt = 0;
//            x = 0;
//        }
//    }
//    for (int i = 1; i <= 999; ++i) {
//        for (int j = -1000; j <= 1000; ++j) {
//            f = x * x + i * x + j;
//            while (f > 1 && !arr[f]) {
//                cnt++;
//                x++;
//                f = x * x + i * x + j;
//            }
//            if (cnt > max) {
//                max = cnt;
//                var[0] = max;
//                var[1] = i;
//                var[2] = j;
//            }
//            cnt = 0;
//            x = 0;
//        }
//    }
//    printf("n^2");
//    if (var[1] > 0)
//        printf("+%dn", var[1]);
//    else if (var[1] < 0)
//        printf("%dn", var[1]);
//    if (var[2] > 0)
//        printf("+%d", var[2]);
//    else if (var[2] < 0)
//        printf("%d", var[2]);
//
//    return 0;
//}