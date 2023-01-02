//#include <stdio.h>
//
//int gcd(int a, int b) {
//	if (!b) return a;
//	return gcd(b, a % b);
//}
//int Isfraction(int x, int y) {
//	if (x > 100 || x < 10) return 0;
//	if (y > 100 || y < 10) return 0;
//	int x1 = x / 10;
//	int x2 = x % 10;
//	int y1 = y / 10;
//	int y2 = y % 10;
//	if (!x1 || !x2 || !y1 || !y2) return 0;
//	if (x1 == y1 && x2 * y == y2 * x && x2 != 0) return 1;
//	if (x2 == y2 && x1 * y == y1 * x && x1 != 0) return 1;
//	if (x1 == y2 && x2 * y == y1 * x && x1 != 0) return 1;
//	if (x2 == y1 && x1 * y == y2 * x && x2 != 0) return 1;
//	return 0;
//}
//int main() {
//	int x = 1, y = 1, c;
//	for (int i = 10; i <= 100; i++) {
//		for (int j = i + 1; j <= 100; j++) {
//			if (Isfraction(i, j) == 0) continue;
//			x *= i; y *= j;
//			c = gcd(x, y);
//			x /= c;
//			y /= c;
//		}
//	}
//	printf("%d\n", y);
//	return 0;
//}

#include <stdio.h>

int gcd(int a, int b);
int main() {

    int a, b, c, d, mul1 = 1, mul2 = 1;
    int gij, gbd, gac, gad, gbc;
    for (int i = 11; i <= 98; ++i) {
        if (i % 10 == 0)
            continue;
        a = i / 10;
        b = i % 10;
        for (int j = i + 1; j <= 99; ++j) {
            if (j % 10 == 0)
                continue;
            c = j / 10;
            d = j % 10;

            if (a == c && (gij = gcd(i, j), gbd = gcd(b, d), i / gij == b / gbd) && j / gij == d / gbd) {
                printf("%d / %d = %d / %d\n", i, j, b, d);
                mul1 *= i;
                mul2 *= j;
            }
            if (a == d && (gij = gcd(i, j), gbc = gcd(b, c), i / gij == b / gbc) && j / gij == c / gbc) {
                printf("%d / %d = %d / %d\n", i, j, b, c);
                mul1 *= i;
                mul2 *= j;
            }
            if (b == c && (gij = gcd(i, j), gad = gcd(a, d), i / gij == a / gad) && j / gij == d / gad) {
                printf("%d / %d = %d / %d\n", i, j, a, d);
                mul1 *= i;
                mul2 *= j;
            }
            if (b == d && (gij = gcd(i, j), gac = gcd(a, c), i / gij == a / gac) && j / gij == c / gac) {
                printf("%d / %d = %d / %d\n", i, j, a, c);
                mul1 *= i;
                mul2 *= j;
            }
        }
    }

    printf("The value of the denominator is %d\n", mul2 / gcd(mul1, mul2));

    return 0;
}

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}