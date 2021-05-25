#include <stdio.h>
#include <stdlib.h>

int searchNum(int* array, int len, int value) {
    for (int i = 0; i < len; ++i) {
        if (array[i] == value)
            return i;
    }
    return -1;
}

float mean(int* array, int len) {
    float sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += array[i];
    }
    return sum / len;
}

char** initArray(char** array, const int row, const int col) {
    array = (char**) calloc(sizeof(char*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = (char*) calloc(sizeof(char), col);
    }
    return array;
}

void fillArray(char** array, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *((*(array + i)) + j) = ((i + 1) * (j + 1));
        }
    }
}

void printArray(char** array, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%4d", *((*(array + i)) + j));
        }
        printf("\n");
    }
}

void changeCols(char** array, int row, int col, int from, int to) {
    char temp;
    for (int i = 0; i < row; ++i) {
        temp = *((*(array + i)) + from);
        *((*(array + i)) + from) = *((*(array + i)) + to);
        *((*(array + i)) + to) = temp;
    }
}

void arrTest() {
    int a[10] = {1,2,3,4,5,6,7,8,9,0};
    int b[10] = {0};
    int c[] = {0,1,2,3,4,5};
    int d[10];
    d[0] = 10;
    d[1] = 20;
    d[2] = 30;
    for (int i = 3; i < 9; ++i) {
        d[i] = (i + 1) * 10;
    }

    printf("index of  5 in a: %d \n", searchNum(a, 10, 5));
    printf("index of 21 in d: %d \n", searchNum(d, 10, 21));
    printf("mean of c: %f \n", mean(c, 6));

    const int row = 10;
    const int col = 10;
    char** arr;
    arr = initArray(arr, row, col);
    fillArray(arr, row, col);
    printArray(arr, row, col);

    changeCols(arr, row, col, 2, 8);
    printArray(arr, row, col);

}
