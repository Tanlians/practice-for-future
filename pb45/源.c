#include <stdio.h>
#include <inttypes.h>

//int is_Pentagonal(int64_t x) {
//	int64_t min = 1, max = x, mid;
//	while (min <= max) {
//		mid = (min + max) / 2;
//		int64_t pen = mid * (3 * mid - 1) / 2;
//		if (pen == x) return 1;
//		if (pen < x) min = mid + 1;
//		else max = mid - 1;
//	}
//	return 0;
//}
//
//int main() {
//	int64_t n = 145;
//	while (!is_Pentagonal(n * (2 * n - 1))) n++;
//	printf("%"PRId64"\n", n * (2 * n - 1));
//	return 0;
//}


_Bool isPen(long long int n);
float qsqrt(float n);

int main() {

    int i = 1;
    long long int   num = 1;

    while (1) {
        num += (4 * i + 1);
        if (num > 40755 && isPen(num)) {
            printf("%lld", num);
            break;
        }
        ++i;
    }

    return 0;
}

_Bool isPen(long long int n) {
    long long int x = (long long int)qsqrt((float)(n * 24 + 1));
    if (x * x == n * 24 + 1 && ((1 + x) % 6 == 0)) {
        return 1;
    }
    return 0;
}

float qsqrt(float n) {
    float nhalf = 0.5f * n;

    int i = *(int*)&n;
    i = 0x5f375a86 - (i >> 1);
    n = *(float*)&i;
    n = n * (1.5f - nhalf * n * n);
    n = n * (1.5f - nhalf * n * n);

    return 1 / n;
}