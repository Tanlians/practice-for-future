#define _CRT_SECURE_NO_WARNINGS 01
#include <stdio.h>

void sum(char(*p)[53]);

int main() {

    char p[100][53];
    for (int i = 0; i < 100; ++i) {
        scanf("%s", p + i);
    }

    for (int i = 0; i < 100; ++i) {
        for (int j = 52; j >= 2; --j) {
            *(*(p + i) + j) = *(*(p + i) + j - 2);
        }
        *(*(p + i) + 1) = '0';
        *(*(p + i)) = '0';
    }

    sum(p);
    int i = 0, t = 0, c = 0;
    while (1) {
        if (p[0][i] != 0)
            t = 1;
        if (t == 1) {
            printf("%c", p[0][i]);
            c = c + 1;
        }
        i = i + 1;
        if (c == 10) {
            printf("\n");
            break;
        }
    }

    return 0;
}

void sum(char(*p)[53]) {

    int ahead = 0, pl;

    for (int i = 1; i < 100; ++i) {
        for (int j = 51; j >= 0; --j) {
            pl = (*(*p + j) - (int)'0') + (*(*(p + i) + j) - (int)'0') + ahead;
            if (pl >= 10) {
                ahead = 1;
                *(*p + j) = pl - 10 + (int)'0';
            }
            else {
                *(*p + j) = pl + (int)'0';
                ahead = 0;
            }
        }
    }
}

