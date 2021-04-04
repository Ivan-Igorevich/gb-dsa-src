#include "../geek.h"

//void sortInserts(int* arr, int len) {
//    int temp, pos;
//    for (int i = 1; i < len; ++i) {
//        temp = arr[i];
//        pos = i - 1;
//        while (pos >= 0 && arr[pos] > temp) {
//            arr[pos + 1] = arr[pos];
//            pos--;
//        }
//        arr[pos + 1] = temp;
//    }
//}

void sortSelection(int* arr, int len) {
    int min;
    for (int i = 0; i < len - 1; ++i) {
        min = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] < arr[min])
                min = j;
        }
        swapInt(&arr[i], &arr[min]);
    }
}

void insPickTest() {
    const int SIZE = 30;
    int array[SIZE];
    fillIntRandom(array, SIZE, 100);
    printIntArray(array, SIZE, 3);
    //sortInserts(array, SIZE);
    sortSelection(array, SIZE);
    printIntArray(array, SIZE, 3);
}
