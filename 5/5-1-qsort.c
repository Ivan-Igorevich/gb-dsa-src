#include "../geek.h"

// Быстрая сортировка, она же сортировка Хоара
// https://ru.wikipedia.org/wiki/%D0%91%D1%8B%D1%81%D1%82%D1%80%D0%B0%D1%8F_%D1%81%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0
void qs(int* arr, int first, int last) {
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swapInt(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last) qs(arr, i, last);
    if (first < j) qs(arr, first, j);
}

// сортировка Ломуто
void qsL(int* arr, int first, int last) {
    if (first < last) {
        int x = arr[last];
        int i = first;
        int j;
        for (j = first; j <= last - 1; j++) {
            if (arr[j] <= x) {
                swapInt(&arr[i], &arr[j]);
                i++;
            }
        }
        swapInt(&arr[i], &arr[last]);
        qsL(arr, first, i - 1);
        qsL(arr, i + 1, last);
    }
}

void qSortTest() {
    const int SZ = 30;
    int arr[SZ];
    fillIntRandom(arr, SZ, 100);
    printIntArray(arr, SZ, 3);
    qsL(arr, 0, SZ - 1);
    printIntArray(arr, SZ, 3);
}
