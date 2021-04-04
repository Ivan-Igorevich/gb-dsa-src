#include "../geek.h"

int linearSearch(int* arr, int len, int value) {
    int i = 0;
    while (i < len && arr[i] != value) {
        i++;
    }

    if (i < len)
        return i;
    else
        return -1;
}

int bareerSearch(int* arr, int len, int value) {
    int i = 0;
    while (arr[i] != value) {
        i++;
    }

    if (i < len - 1) {
        return i;
    } else {
        return -1;
    }
}

void linBarrTest() {
    const int SIZE = 40;
    int arr[SIZE];
    fillIntRandom(arr, SIZE, 100);
    arr[SIZE - 1] = 98;
    printIntArray(arr, SIZE, 3);
    printf("Значение 98 было найдено в массиве: %d \n", bareerSearch(arr, SIZE, 98));
    //printf("Значение 98 в массиве найдено по индексу: %d \n", linearSearch(arr, SIZE, 98));
}