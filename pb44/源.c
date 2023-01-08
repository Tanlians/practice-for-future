#define _CRT_SECURE_NO_WARNINGS 01
#include <stdio.h>
#include <inttypes.h>

static inline int64_t pena(int64_t x) {
	return x * (3 * x - 1) / 2;
}//��c�����У�����������ʱһ��Ҫ��static����Ȼ�����������Ŵ�������

int is_pen(int64_t x) {
	int min = 1, max = x;
	while (min <= max) {
		int64_t mid = (min + max) / 2;//ÿ��midֵ��Ҫ�任������Ӧд���ڲ�ѭ�����棻
		int64_t pen = pena(mid);
		if (pen == x) return 1;
		if (pen < x) min = mid + 1;
		else max = mid - 1;
	} 
	return 0;
}

int main() {
	int64_t k = 2;
	int64_t d = INT64_MAX;//int64_t�����ֵ��
	while (pena(k) - pena(k - 1) < d) {
		int64_t j = k - 1;
		while (pena(k) - pena(j) < d) {
			if (is_pen(pena(k) + pena(j)) && is_pen(pena(k) - pena(j))) {
				d = pena(k) - pena(j);
			}
			j--;
			if (!j) break;//��j=0ʱ������pena(k)-pena(j)Ҳ��������ѭ������Ȼ������ѭ����
		}
		k++;
	}
	printf("%"PRId64"\n", d);
	return 0;
}

//#define M 10000000
//
//int arr[M] = { 0 };
//float rSqrt(float x);
//_Bool isPentagon(long long int num);
//int main() {
//
//
//    long long int t = 100000000, x, y;
//    for (int i = 1; i < M; ++i) {
//        arr[i] = 3 * i + 1;
//        for (int j = i - 1; j > 0; --j) {
//            arr[j] = arr[i] + arr[j];
//        }
//
//        if (arr[i] > t) {
//            printf("\n\n%lld-%lld=%lld\n", x, y, t);
//            break;
//        }
//        for (int k = i; k > 0; --k) {
//            if (arr[k] >= t) {
//                break;
//            }
//            if (isPentagon(arr[k]) && isPentagon((3 * k * k - k) / 2 + (3 * (i + 1) * (i + 1) - (i + 1)) / 2)) {
//                t = arr[k];
//                y = k;
//                x = i + 1;
//                printf("%d  ", t);
//                break;
//            }
//        }
//    }
//
//    return 0;
//}
//
//_Bool isPentagon(long long int num) {
//    long long int x = (long long int)rSqrt((float)(num * 24 + 1));
//    if (x * x == num * 24 + 1 && ((1 + x) % 6 == 0)) {
//        return 1;
//    }
//    return 0;
//}
//
//
//float rSqrt(float x) {
//
//    float xhalf = 0.5f * x;
//
//    int i = *(int*)&x;
//    i = 0x5f3759df - (i >> 1);
//    x = *(float*)&i;
//    x = x * (1.5f - xhalf * x * x);
//    x = x * (1.5f - xhalf * x * x);
//    x = x * (1.5f - xhalf * x * x);
//
//    return (1 / x);
//}