#include "../geek.h"

int binarySearch(const int* arr, int len, int value) {
    int l = 0;
    int r = len - 1;
    int mid = (l + r) / 2;

    while (l <= r && arr[mid] != value) {
        if (arr[mid] < value)
            l = mid + 1;
        else
            r = mid - 1;
        mid = (l + r) / 2;
    }

    if (arr[mid] == value)
        return mid;
    else
        return -1;
}

int searchInter(int* arr, int len, int value) {
    int mid;
    int l = 0;
    int r = len - 1;

    while (arr[l] < value && arr[r] > value) {
        mid = l + ((value - arr[l]) * (r - l)) / (arr[r] - arr[l]);
        if (arr[mid] < value)
            l = mid + 1;
        else if (arr[mid] > value)
            r = mid - 1;
        else
            return mid;
    }

    if (arr[l] == value)
        return l;
    else if (arr[r] == value)
        return r;
    else
        return -1;
}

void binInterTest() {
    const int SZ = 30;
    int arr[SZ];
    fillIntRandom(arr, SZ, 100);
    printIntArray(arr, SZ, 3);
    sortIntInserts(arr, SZ);
    printf("Значение 65 найдено по индексу: %d \n", searchInter(arr, SZ, 65));

}