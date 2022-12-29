#define _CRT_SECURE_NO_WARNINGS 01
#include <stdio.h>
#include<string.h>
#define max 1000000

//int main()
//{
//	int count = 1, cnt = 0, a, b ,temp;
//	char c[11] = "0123456789";
//	int len = strlen(c);
//	printf("%d\n", len);
//	printf("%d\n", c[3] - '0');
//	for (int i = 1; i < max; i++)
//	{
//		for (int j = 8; j >= 0; j--)
//		{
//			if (c[j] < c[j + 1])
//			{
//				b = j;
//				break;
//			}
//		}
//		for (int k = b; k < 9; k++)
//		{
//			if (b + 1 == 9)
//				temp = 9;
//			else if (c[k+1] < c[k + 2])
//				temp = k + 1;
//		}
//		char p;
//		p = c[temp];
//		c[temp] = c[b];
//		c[b] = p;
//		for (int k = b+1 , o=9;k<=o; k++,o--)
//		{
//			char ui;
//			if (k == 9)
//				break;
//			else
//			{
//				ui = c[k];
//				c[k] = c[o];
//				c[o] = ui;
//			}
//		}
//	}
//	puts(c);
//	return 0;
//}

void main()
{
	int i, j, k, t1, b;
	char a[11] = "0123456789";
	char min, t2;
	int len = strlen(a);
	for (i = 1; i < 1000000; i++)
	{
		min = 'z';
		for (j = len - 2; j >= 0; j--)
		{
			if (a[j] < a[j + 1])
			{
				for (k = j + 1; k < len; k++)
				{
					if (a[k] > a[j])
					{
						if (min > a[k])
						{
							min = a[k];
							t1 = k;
						}
					}
				}
				t2 = a[j];
				a[j] = a[t1];
				a[t1] = t2;
				for (k = j + 1, b = len - 1; k <= b; k++, b--)
				{
					t2 = a[k];
					a[k] = a[b];
					a[b] = t2;
				}
				break;//跳出循环，进行下一次排列
			}
		}
	}
	puts(a);
	return 0;
}


//int get_num(int n, int* num, int delta) {
//	int rank = n / delta + 1, now = 0;
//	for (int i = 0; i < 10; i++) {
//		now += !(num[i]);
//		if (now == rank) return i;
//	}
//	return -1;
//}
//int main() {
//	int n = 999999, delta = 362880;//初始为0123456789，所以只需便利999999次即可，delta=9!;
//	int num[10] = { 0 };
//	for (int i = 0; i < 10; i++) {
//		int digit = get_num(n, num, delta);
//		printf("%d", digit);  //找到第i个数字
//		num[digit] = 1;       //将已经用过的数字标记为1；
//		n %= delta;           //还需要排列的次数；
//		if (i == 9) break;     //如果i=9，已经不用再除1！,不然会有除0的现象；
//		delta /= (9 - i);     //确定下一位的增量；
//	}
//	return 0;
//}

//#include <stdio.h>
//#define M 10
//
//_Bool isBtS(int n, int* arr);
//int tBS(int a, int* arr);
//void rev(int* arr, int n);
//void test(int* arr);
//void pri(int* arr);
//
//int main() {
//    int arr[M] = { 0,1,2,3,4,5,6,7,8,9 };
//
//    test(arr);
//    pri(arr);
//
//    return 0;
//}
//
//_Bool isBtS(int n, int* arr) {
//    for (int i = n; n < M - 1; ++n) {
//        if (arr[n] < arr[n + 1])
//            return 0;
//    }
//    return 1;
//}
//
//int tBS(int a, int* arr) {
//    int ver = 0, l = 0;
//    static int cnt = 0;
//    for (int i = a + 1; i <= M - 1; ++i) {
//        if (arr[i] > arr[a]) {
//            l = i;
//        }
//        else {
//            break;
//        }
//    }
//    ver = arr[l];
//    arr[l] = arr[a];
//    arr[a] = ver;
//
//    rev(arr, a + 1);
//    cnt++;
//
//    return cnt == 1000000 - 1 ? 1 : 0;
//}
//
//void rev(int* arr, int n) {
//    int k = M - n;
//    int num[k];
//    for (int i = 0; i < M - n; ++i) {
//        num[i] = arr[i + n];
//    }
//    for (int i = n; i < M; ++i) {
//        arr[i] = num[M - 1 - i];
//    }
//}
//
//void test(int* arr) {
//    int i = M - 1;
//    while (i != 0) {
//        if (isBtS(i, arr) && !isBtS(i - 1, arr)) {
//            //pri(arr);		
//            if (tBS(i - 1, arr)) {
//                return;
//            }
//            i = M - 1;
//        }
//        else {
//            i--;
//        }
//    }
//}
//
//void pri(int* arr) {
//    for (int i = 0; i < M; ++i) {
//        printf("%d ", arr[i]);
//    }
//    puts("");
//}