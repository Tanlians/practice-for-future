#include <stdio.h>
#include <inttypes.h>

int main() {
	int64_t sum = 1, m = 20;
	for (int64_t i = 40; i > 20; i--) {
		sum *= i;
		while (sum % m == 0 && m != 1) {
			sum /= m;
			m--;
		}
	}
	printf("%"PRId64"\n", sum);
	return 0;
}