#include <stdio.h>
#define max 1000
#define K 8

int money[9] = { 0, 1, 2, 5, 10, 20, 50, 100,200 };
int keep[K][max + 5] = { 0 };

int f(int k, int n) {
	int ans = 0;
	if (k == 1) return 1;
	if (n == 0) return 1;
	if (n < 0) return 0;
	if (keep[k][n] && k < K && n < max) {
		return keep[k][n];
	}
	else {
		ans = f(k - 1, n) + f(k, n - money[k]);
	}
	if (k < K && n < max) {
		keep[k][n] = ans;
	}
	return ans;
}

int main() {
	printf("%d\n", f(8, 200));
	return 0;
}