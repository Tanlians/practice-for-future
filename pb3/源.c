#include <stdio.h>

int main()
{
    long long int num = 600851475143;
    int cnt = 1;

    while (num != 1) {
        ++cnt;
        while (num % cnt == 0) {
            num /= cnt;
        }
    }
    printf("%d", cnt);

    return 0;
}