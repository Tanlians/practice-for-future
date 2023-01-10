

#include <stdio.h>

int arr[5] = { 0 };
void rev(int x);
void getnum(int x);
_Bool notPrime[10000] = { 1,1 };
int next(int x);
int sort(int x);

int main()
{
    int prime[10000] = { 0 };
    for (int i = 2; i < 10000; ++i) {
        if (!notPrime[i])
            prime[++prime[0]] = i;
        for (int j = 1; i * prime[j] < 10000; ++j) {
            notPrime[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }

    for (int i = 1488; i <= 9999; ++i) {
        if (!notPrime[i]) {
            int x = i, y;
            while (x != (y = next(x))) {
                if (!notPrime[y] && (sort(i) == sort(y + (y - i))) && !notPrime[y + (y - i)]) {
                    printf("%d%d%d\n", i, y, y + (y - i));
                    return 0;
                }
                x = y;
            }
        }
    }

}

void rev(int x)
{
    int arr0[5] = { 0 };
    for (int i = 4; i >= x; --i) {
        arr0[++arr0[0]] = arr[i];
    }
    arr0[0] = 0;
    for (int i = x; i <= 4; ++i) {
        arr[i] = arr0[++arr0[0]];
    }
}

void getnum(int x)
{
    for (int i = 1; i <= 4; ++i) {
        arr[5 - i] = x % 10;
        x /= 10;
    }
}

int next(int x)
{
    getnum(x);
    int t;
    for (int i = 4; i > 1; --i) {
        if (arr[i] > arr[i - 1]) {
            for (int k = 4; k > i - 1; --k) {
                if (arr[k] > arr[i - 1]) {
                    t = arr[k];
                    arr[k] = arr[i - 1];
                    arr[i - 1] = t;
                    break;
                }
            }
            rev(i);
            break;
        }
    }

    return  (arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[4]);
}


int sort(int x)
{
    int y;
    while (x != (y = next(x))) {
        x = y;
    }

    return x;
}