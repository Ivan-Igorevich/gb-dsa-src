#include "../geek.h"

void countingSort(int* arr, int len, const int max) {
    int counts[max];
    for (int i = 0; i < max; ++i) {
        counts[i] = 0;
    }
    for (int i = 0; i < len; ++i) {
        counts[arr[i]]++;
    }
    int indx = 0;
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < counts[i]; ++j) {
            arr[indx] = i;
            indx++;
        }
    }
}

int findMin(int* arr, int len) {
    int min = arr[0];
    for (int i = 0; i < len; ++i) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int findMax(int* arr, int len) {
    int max = arr[0];
    for (int i = 0; i < len; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void sortCount(int* arr, int len) {
    int min = findMin(arr, len);
    int max = findMax(arr, len);
    const int spread = abs(min) + abs(max) + 1;
    int support[spread];
    for (int i = 0; i < spread; ++i) {
        support[i] = 0;
    }
    for (int i = 0; i < len; ++i) {
        support[arr[i] - min]++;
    }
    int count = 0;
    for (int i = 0; i < spread; ++i) {
        while (support[i] > 0) {
            arr[count++] = i + min;
            support[i]--;
        }
    }
}

void countTest() {
    const int SZ = 30;
    int arr[SZ];
    fillIntRandom(arr, SZ, 5);
    arr[0] = -17;
    arr[5] = -65;
    arr[10] = -4;
    printIntArray(arr, SZ, 2);
    sortCount(arr, SZ);
    printIntArray(arr, SZ, 2);
}