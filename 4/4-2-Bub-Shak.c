#include "../geek.h"

void bubbleSort(int* arr, int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - 1; ++j) {
            if (arr[j] > arr[j + 1])
                swapInt(&arr[j], &arr[j + 1]);
        }
    }
}

void shakerSort(int* arr, int len) {
    int left = 1;
    int right = len - 1;
    while (left <= right) {
        int i;
        for (i = right; i >= left; --i) {
            if (arr[i - 1] > arr[i])
                swapInt(&arr[i], &arr[i - 1]);
        }
        left++;
        for (i = left; i <= right; ++i) {
            if (arr[i - 1] > arr[i])
                swapInt(&arr[i], &arr[i - 1]);
        }
        right--;
    }
}

void bubShakTest() {
    const int SIZE = 100;
    int arr[SIZE];
    fillIntRandom(arr, SIZE, 100);
    printIntArray(arr, SIZE, 3);
    //bubbleSort(arr, SIZE);
    shakerSort(arr, SIZE);
    printIntArray(arr, SIZE, 3);
}