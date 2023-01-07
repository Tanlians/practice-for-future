#include <stdio.h>


int getnum(int num);

int main() {

    printf("%d\n", getnum(1) * getnum(10) * getnum(100) * getnum(1000) * getnum(10000) * getnum(100000) * getnum(1000000));

    return 0;
}

int getnum(int num) {
    int cnt = 0, d = 0, x;
    while (d < num) {
        ++cnt;
        int di = 1, y = cnt;
        while ((y /= 10) > 0) {
            ++di;
        }
        d += di;
        x = di;
        //printf("%d", cnt);
    }

    for (int i = 1; i <= d - num; ++i) {
        cnt /= 10;
    }

    return cnt % 10;
}