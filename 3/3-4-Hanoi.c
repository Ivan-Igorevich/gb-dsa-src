#include <stdio.h>

int operations = 0;

void put(int from, int to) {
    printf("%d -> %d | ", from, to);
    if ((++operations % 5) == 0)
        printf("\n");
}

void hanoi(int from, int to, int n) {
    int temp = from ^ to;
    if (n == 1) {
        put(from, to);
    } else {
        hanoi(from, temp, n - 1);
        put(from, to);
        hanoi(temp, to, n - 1);
    }
}

void hanoiTest() {
    int disks = 8;
    printf("pyramid size = %d \n", disks);
    hanoi(1, 3, disks);
    printf("\n operations = %d \n", operations);
}
