#include "../geek.h"

const int n = 6;
int matrix[n][n] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
};
int visitedDepth[n] = {0};

void depthTravers(int st) {
    int r;
    printf("%d ", st);

    visitedDepth[st] = 1;
    for (r = 0; r < n; ++r) {
        if (matrix[st][r] == 1 && !visitedDepth[r]) {
            depthTravers(r);
        }
    }
}

void resetArr() {
    for (int i = 0; i < n; ++i) {
        visitedDepth[i] = 0;
    }
}

void depthTest() {
    depthTravers(0);
    resetArr();
    printf("\n");
    depthTravers(2);
    resetArr();
    printf("\n");
    depthTravers(1);
    resetArr();
    printf("\n");
}
