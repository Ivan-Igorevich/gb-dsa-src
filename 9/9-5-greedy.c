#include "../geek.h"

int profitCalculation(int* deadline, int* task, const int TASKS, const int DAYS) {
    int used[DAYS];
    int arr[DAYS];

    clearIntArray(used, DAYS);
    clearIntArray(arr, DAYS);

    int sum = 0;
    for (int i = 0; i < TASKS; ++i) {
        int k = deadline[i];
        while (k >= 1 && used[k] == 1) {
            k--;
        }
        if (k == 0) continue;

        used[k] = 1;
        arr[k] = task[i];
        sum += task[i];
    }
    printIntArray(arr, DAYS, 0);
    return sum;
}

void greedyTest() {
    const int DMAX = 10;
    const int N = 12;
    int task[] =     {1000, 900, 800, 700, 600, 500, 400, 300, 300, 100, 75, 50};
    int deadline[] = {2,    8,   9,   3,   5,   4,   7,   2,   1,   6,   9,  10};

    printf("%d\n", profitCalculation(deadline, task, N, DMAX + 1));
}
