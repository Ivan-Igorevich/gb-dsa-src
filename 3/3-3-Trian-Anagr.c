#include <stdio.h>

int triangle(int n) {
    int result = 0;
    if (n == 1)
        result += 1;
    else
        result += n + triangle(n - 1);
    return result;
}


void printPyramid(int n) {
    int i = 1;
    while (i <= n) {
        int amnt = i;
        char shift[5];
        sprintf(shift, "%%%dd", n + 1 - i); //%3d
        printf(shift, i);
        while (--amnt != 0)
            printf("%2d", i);
        printf("\n");
        i++;
    }
}

void printTriangle(int n) {
    int prev = 0;
    while (n > 0) {
        prev++;
        n -= prev;
        printf("%s%d", (prev > 1) ? " + " : "", prev);
    }
}

void rotate(char* word, int size, int n) {
    int i;
    int pos = size - n;
    char temp = word[pos];
    for (i = pos + 1; i < size; ++i) {
        word[i - 1] = word[i];
    }
    word[i - 1] = temp;
}

void display(char* word, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%c", word[i]);
    }
    printf("\n");
}

void getAnagram(char* word, int size, int n) {
    if (n == 1) {
        return;
    }
    for (int i = 0; i < n; ++i) {
        getAnagram(word, size, n - 1);
        if (n == 2)
            display(word, size);
        rotate(word, size, n);
    }
}

void trianAnagrTest() {
    const int num = 5;
    printf("%d \n", triangle(num));
    printPyramid(num);
    printTriangle(triangle(num));
    printf("\n");

    int size = 4;
    char arr[64];
    printf("Введите, пожалуйста, слово длиной %d букв: ", size);
    scanf("%s", arr);
    printf("\n");
    getAnagram(arr, size, size);
}