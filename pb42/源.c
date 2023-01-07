#include <stdio.h>
#define M 26*15

_Bool test(int num);
void getTri(int n);
_Bool isTri[M + 1] = { 0,1 };
int main() {

    FILE* fp = NULL;
    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("can't find that file");
        return -2;
    }

    getTri(M);

    int ch, st = 0, sum = 0, cnt = 0, len = 0, co = 0;;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') continue;
        if (ch == '\"') {
            if (st == 0) {
                st = 1;
                continue;
            }
            else {
                st = 0;

                printf(" %d\n", sum);
                if (isTri[sum])  co++;

                sum = 0;
                len = cnt > len ? cnt : len;
                cnt = 0;
            }
        }
        if (st == 1) {
            ++cnt;
            printf("%c", ch);
            sum += ch - 'A' + 1;
        }
    }

    //printf("%d\n", len);

    printf("\n\n%d triangle words\n", co);

    fclose(fp);

    return 0;
}

void getTri(int n) {
    int arr[M] = { 1,1 };
    do {
        arr[0]++;
        arr[arr[0]] = arr[arr[0] - 1] + arr[0];
        isTri[arr[arr[0]]] = 1;
    } while (arr[arr[0]] < n);
}