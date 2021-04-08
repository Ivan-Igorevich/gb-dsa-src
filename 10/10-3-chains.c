#include "../geek.h"

typedef int K;
typedef int htIndex;

int htSize;

htIndex hash(T data) {
    return data % htSize;
}

boolean chainInsertNode(OneLinkNode **table, K data) {
    OneLinkNode *p, *p0;

    htIndex bucket = hash(data);
    p = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (p == NULL) {
        printf("Out of memory! \n");
        return false;
    }

    p0 = table[bucket];
    table[bucket] = p;
    p->next = p0;
    p->dat = data;
    return true;
}

OneLinkNode* chainFindNode(OneLinkNode **table, K data) {
    OneLinkNode *p = table[hash(data)];
    while (p && !(p->dat == data))
        p = p->next;
    return p;
}

void chainDeleteNode(OneLinkNode **table, K data) {
    OneLinkNode *parent, *current;
    parent = NULL;
    htIndex bucket = hash(data);
    current = table[bucket];
    while (current && !(current->dat == data)) {
        parent = current;
        current = current->next;
    }
    if (!current) {
        printf("Value not found \n");
        return;
    }
    if (parent)
        parent->next = current->next;
    else
        table[bucket] = current->next;
    free(current);
}

void printTable(OneLinkNode** table, int size) {
    OneLinkNode *p;
    for (int i = 0; i < size; ++i) {
        p = table[i];
        while (p) {
            printf("%5d", p->dat);
            p = p->next;
        }
        printf("\n");
    }
    printf("\n");
}

void chainsTest() {
    htSize = 8;
    int* arr;
    const int SZ = 20;
    arr = (int*) malloc(sizeof(int) * SZ);
    fillIntRandom(arr, SZ, 100);

    OneLinkNode** hashTable = (OneLinkNode**) calloc(htSize, sizeof(OneLinkNode*));
    for (int i = 0; i < SZ; ++i) {
        chainInsertNode(hashTable, arr[i]);
    }
    printTable(hashTable, htSize);

    printf(" \n");
    printOneLinkIntNode(chainFindNode(hashTable, 40));
    printOneLinkIntNode(chainFindNode(hashTable, 41));
    printf(" \n");

    for (int i = 0; i < SZ / 2; ++i) {
        chainDeleteNode(hashTable, arr[i]);
    }
    printTable(hashTable, htSize);

}
