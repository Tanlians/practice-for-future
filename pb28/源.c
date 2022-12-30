//#include<stdio.h>
//int main()
//{
//	int sum = 1;
//	for (int m = 3; m <= 1001; m += 2)
//	{
//		sum += 4 * m * m - 6 * m + 6;
//	}
//	printf("%d", sum);
//	return 0;
//}

#include <stdio.h>

int main() {
	int m = 3;
	int sum = 1;
	while (m <= 1001) {
		sum += 4 * m * m - 6 * m + 6;
		m += 2;
	}
	printf("%d\n", sum);
	return 0;
}