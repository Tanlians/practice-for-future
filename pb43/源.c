#include <stdio.h>
#define M 1000

int listN[11] = { 10,0,1,2,3,4,5,6,7,8,9 };

_Bool isBtS(int n);
void rev(int n);
void prt(int n);
long long int sort(void);
_Bool test(void);
long long int getNum(void);

int main() {

    printf("\n\n%lld", sort());

    return 0;
}

_Bool isBtS(int n) {
    if (n == listN[0]) return 1;
    int i;
    for (i = n; i < listN[0]; ++i) {
        if (listN[i] < listN[i + 1]) return 0;
    }

    return 1;
}

void rev(int n) {
    int arr[11] = { 0 };
    for (int i = n; i <= listN[0]; ++i) {
        arr[++arr[0]] = listN[i];
    }
    arr[0] = 0;
    for (int i = listN[0]; i >= n; --i) {
        listN[i] = arr[++arr[0]];
    }
}

void prt(int n) {
    for (int i = n; i <= listN[0]; ++i) {
        printf("%d", listN[i]);
    }
    puts("");
}

long long int sort(void) {

    long long int sum = 0;

    if (test()) {
        prt(1);
        sum += getNum();
    }

    int i = listN[0];
    while (i > 1) {
        if (isBtS(i) && !isBtS(i - 1)) {
            for (int j = listN[0]; j > 1; --j) {
                if (listN[j] > listN[i - 1]) {
                    int t = listN[j];
                    listN[j] = listN[i - 1];
                    listN[i - 1] = t;
                    rev(i);
                    i = listN[0];
                    if (test()) {
                        prt(1);
                        sum += getNum();
                    }
                    break;
                }
            }
        }
        else
            --i;
    }

    return sum;
}


_Bool test(void) {
    int pri[] = { 2,3,5,7,11,13,17 };
    for (int i = 2; i <= 8; ++i) {
        if (((listN[i] * 100 + listN[i + 1] * 10 + listN[i + 2]) % pri[i - 2]) != 0)
            return 0;
    }
    return 1;
}

long long int getNum(void) {
    long long int sum = listN[1];
    for (int i = 2; i <= listN[0]; ++i) {
        sum *= 10;
        sum += listN[i];
    }

    return sum;
}