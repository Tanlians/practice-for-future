#define _CRT_SECURE_NO_WARNINGS 01
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 5000

void rand_str(char* str);

int main() {
    FILE* fp;
    fp = fopen("names.txt", "w");

    char str[10];
    for (int i = 1; i <= 5000; ++i) {
        rand_str(str);
        //printf("%s\n", str);
        fprintf(fp, "%s ", str);
        for (int i = 0; i < 10; ++i) {
            str[i] = '\0';
        }
    }
    fclose(fp);

    fp = fopen("names.txt", "r");

    char name[NUM][10], arr[10];
    int i = 0;
    while (fscanf(fp, "%8s", *(name + i)) != EOF) {
        ++i;
    }

    int n = NUM;
    for (int j = n; j > 2; --j) {
        for (int i = 0; i <= n; ++n) {
            if (strcmp(*(name + i), *(name + i + 1)) > 0) {
                strcpy(arr, *(name + i + 1));
                strcpy(*(name + i + 1), *(name + i));
                strcpy(*(name + i), arr);
            }
        }
    }

    for (int i = 0; i < NUM; ++i) {
        printf("%s\n", *(name + i));
    }

    long long int sum2 = 0;
    for (int i = 0; i < NUM; ++i) {
        int sum1 = 0;
        for (int j = 0; j < strlen(*(name + i)); ++j) {
            sum1 += *(*(name + i) + j) - 'a' + 1;
        }
        sum2 += sum1 * i;
        printf("%d\n", sum1);
    }

    printf("%lld\n", sum2);
    fclose(fp);

    return 0;
}

void rand_str(char* str) {
    int a = rand() % 8 + 1, i = 0;
    char p[9];
    for (i; i < a; ++i) {
        *(p + i) = rand() % 26 + 'a';
    }
    *(p + i) = '\0';
    strcpy(str, p);
}