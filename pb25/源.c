#define _CRT_SECURE_NO_WARNINGS 01
#include <stdio.h>

int main() {
	int fbi[3][1005] = { 0 };
	fbi[1][0] = fbi[1][1] = 1;
	fbi[2][0] = fbi[2][1] = 1;
	int n = 2;
	while (fbi[n % 3][0] < 1000) {
		n++;
		for (int i = 1; i <= fbi[(n + 2) % 3][0]; i++) {
			fbi[n % 3][i] = fbi[(n + 1) % 3][i] + fbi[(n + 2) % 3][i];
		}
		fbi[n % 3][0] = fbi[(n + 2) % 3][0];
		for (int i = 1; i <= fbi[n % 3][0]; i++) {
			if (fbi[n % 3][i] < 10) continue;
			fbi[n % 3][i + 1] += fbi[n % 3][i] / 10;
			fbi[n % 3][i] %= 10;
			fbi[n % 3][0] += (fbi[n % 3][0] == i);
		}
	}
	printf("%d\n", n);
	return 0;
}