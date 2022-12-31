#define _CRT_SECURE_NO_WARNINGS 01
#include <stdio.h>
#include <string.h>
#define A 100
#define M 205

int getNum(short* arr, int num);
int getPower(int a, short* var);
int mul(short* arr1, short* arr2);
int add(short* arr1, short* arr2);


int main() {
    short arr[M] = { 0 };
    int a = A;
    getNum(arr, a);
    getPower(a, arr);
    short max = arr[0];
    printf("%d^%d %hd\n", A, A, max);
    FILE* fp = NULL;
    fp = fopen("e29.txt", "w");

    for (int i = 2; i <= A; ++i) {
        for (int j = 2; j <= A; ++j) {
            short num[M] = { 0 };
            getNum(num, i);
            getPower(j, num);
            for (int k = max - 1; k > num[0] - 1; --k) {
                fprintf(fp, "0");
            }
            for (int k = num[0] - 1; k > 0; --k) {
                fprintf(fp, "%hd", num[k]);
            }
            fprintf(fp, "\n");
        }
    }
    fclose(fp);

    fp = fopen("e29.txt", "r");
    char str[(A - 1) * (A - 1) + 1][M];
    int t = 1;
    while (fscanf(fp, "%s", str[t]) != EOF) {
        //printf("%s\n", str[t]);
        ++t;
    }
    fclose(fp);

    for (int i = t - 1; i > 1; --i) {
        for (int j = 1; j < i; ++j) {
            if (strcmp(str[j], str[j + 1]) > 0) {
                char str0[M] = { 0 };
                strcpy(str0, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], str0);
            }
        }
    }

    int cnt = 1;
    printf("%d\n", 4);
    for (int i = 1; i < t - 1; ++i) {
        if (strcmp(str[i], str[i + 1]) != 0) {
            cnt++;
            int j;
            for (j = 0; j < max - 1; ++j) {
                if (str[i + 1][j] != '0')
                    break;
            }
            printf("%s\n", *(str + i + 1) + j);
        }
    }

    printf("%d distinct terms are in the sequence\n", cnt);

    return 0;
}
int getNum(short* arr, int num) {
    int i = 0;
    do {
        arr[++i] = num % 10;
        num /= 10;
    } while (num > 0);
    arr[0] = ++i;

    return arr[0];
}

int getPower(int a, short* var) {
    short var2[M] = { 0 };
    for (int i = 0; i < var[0]; ++i) {
        var2[i] = var[i];
    }
    for (int i = 1; i < a; ++i) {
        mul(var, var2);
    }

    return 0;
}

int mul(short* arr1, short* arr2) {
    short arr3[M] = { 0 }, arr4[M] = { 0 };
    int  re, up = 0;

    for (int i = 1; i < arr2[0]; ++i) {
        for (int j = 1; j < arr1[0]; ++j) {
            re = (arr2[i]) * (arr1[j]) + up;
            up = re / 10;
            re = re % 10;
            arr3[i + j - 1] = re;
        }
        if (up > 0) {
            arr3[arr1[0] - 1 + i] = up;
            arr3[0] = arr1[0] + i - 1 + 1;
        }
        else
            arr3[0] = arr1[0] + i - 1;
        up = 0;

        add(arr4, arr3);
    }
    for (int i = 0; i < arr4[0]; ++i) {
        arr1[i] = arr4[i];
    }

    return 0;
}

int add(short* arr1, short* arr2) {
    short arr3[M] = { 0 };
    int le = arr1[0] > arr2[0] ? arr1[0] : arr2[0], re, up = 0;
    for (int i = 1; i < le; ++i) {
        re = arr1[i] + arr2[i] + up;
        up = re / 10;
        re = re % 10;
        arr3[i] = re;
    }
    if (up > 0)
        arr3[le] = 1;

    arr3[0] = le + up;
    for (int i = 0; i < arr3[0]; ++i) {
        arr1[i] = arr3[i];
    }
    for (int i = 0; i < arr3[0]; ++i) {
        arr2[i] = 0;
    }

    return 0;
}