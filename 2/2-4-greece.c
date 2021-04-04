#include <stdio.h>

int euclidus(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int euclidusFast(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int euclidusExt(int a, int b, int* x, int* y) {
    int q, r, x1, x2, y1, y2;
    if (b == 0) {
        *x = 1; *y = 0;
        return a;
    }
    x2 = 1;
    x1 = 0;
    y2 = 0;
    y1 = 1;
    while (b > 0) {
        q = a / b;
        r = a - q * b;
        *x = x2 - q * x1;
        *y = y2 - q * y1;
        a = b; b = r;
        x2 = x1; x1 = *x;
        y2 = y1; y1 = *y;
    }
    *x = x2; *y = y2;
    return a;
}

void eratosphen() {
    int arr[255] = {2, 3};
    int capacity = 2;
    for (int i = 4; i < 255; ++i) {
        int isPrime = 1;
        for (int j = 0; j < capacity; ++j) {
            if (i % arr[j] == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            arr[capacity++] = i;
        }
    }

    for (int k = 0; k < capacity; ++k) {
        printf("%d ", arr[k]);
    }
}

void greeceCheck() {
    int a;
    int b;
    int coeffA;
    int coeffB;
    printf("%s", "Введите число А:");
    scanf("%d", &a);
    printf("%s", "Введите число Б:");
    scanf("%d", &b);
    printf("НОД = %d \n", euclidus(a, b));
    printf("НОД = %d \n", euclidusFast(a, b));
    printf("НОД = %d \n", euclidusExt(a, b, &coeffA, &coeffB));
    printf("ax + by = %d \n", a * coeffA + b * coeffB);
    eratosphen();
}

