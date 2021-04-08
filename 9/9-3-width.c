#include "../geek.h"

void clearVisited(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}

void widthTravers(int** matrix, int start, const int size) {
    TwoLinkList* queue = (TwoLinkList*) malloc(sizeof(TwoLinkList));
    initTwoLinkList(queue);
    int visited[size];
    clearVisited(visited, size);
    TwoLinkEnqueue(queue, start);
    while (queue->size > 0) {
        int indx = TwoLinkDequeue(queue);
        if (visited[indx] == 1) continue;
        visited[indx] = 1;
        printf("%d ", indx);
        for (int i = 0; i < size; ++i) {
            if (get2dInt(matrix, indx, i) == 1 && visited[i] == 0)
                TwoLinkEnqueue(queue, i);
        }
    }
}

//int matrix[n][n] = {
//        {0, 1, 1, 0, 0, 0},
//        {0, 0, 0, 1, 1, 1},
//        {0, 0, 0, 0, 0, 1},
//        {1, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 1, 0},
//};

void widthTest() {
    const int SZ = 6;
    int** adjacency = init2dIntArray(adjacency, SZ, SZ);
    set2dInt(adjacency, 0, 1, 1);
    set2dInt(adjacency, 0, 2, 1);
    set2dInt(adjacency, 1, 3, 1);
    set2dInt(adjacency, 1, 4, 1);
    set2dInt(adjacency, 1, 5, 1);
    set2dInt(adjacency, 2, 5, 1);
    set2dInt(adjacency, 3, 0, 1);
    set2dInt(adjacency, 5, 4, 1);

    widthTravers(adjacency, 0, SZ);
    printf("\n");
    widthTravers(adjacency, 3, SZ);
    printf("\n");
    widthTravers(adjacency, 1, SZ);
    printf("\n");

}

