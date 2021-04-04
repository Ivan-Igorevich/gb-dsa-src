#include <stdio.h>
#include <stdlib.h>

#define SZ 10

typedef struct {
    int pr;
    int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;

void initQueue() {
    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins(int pr, int dat) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;
    int flag;

    if (items == 0) {
        arr[tail++] = node;
        items++;
    } else if (items == SZ) {
        printf("%s \n", "Queue is full");
        return;
    } else {
        int i = 0;
        int idx = 0;
        Node *tmp;
        for (i = head; i < tail; ++i) {
            idx = i % SZ;
            if (arr[idx]->pr > pr)
                break;
            else
                idx++;
        }
        flag = idx % SZ;
        i++;
        while (i <= tail) {
            idx = i % SZ;
            tmp = arr[idx];
            arr[idx] = arr[flag];
            arr[flag] = tmp;
            i++;
        }
        arr[flag] = node;
        items++;
        tail++;
    }
}

Node* rem() {
    if (items == 0) {
        return NULL;
    } else {
        int idx = head++ % SZ;
        Node *tmp = arr[idx];
        arr[idx] = NULL;
        items--;
        return tmp;
    }
}

void printQueue() {
    printf("[ ");
    for (int i = 0; i < SZ; ++i) {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}

void prQueueTest() {
    initQueue();
    ins(1, 11);
    ins(3, 22);
    ins(4, 33);
    ins(2, 44);
    ins(3, 55);
    ins(4, 66);
    ins(5, 77);
    ins(1, 88);
    ins(2, 99);
    ins(6, 100);
    printQueue();
    for (int i = 0; i < 7; ++i) {
        Node* n = rem();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
    }
    printQueue();

    ins(1, 110);
    ins(3, 120);
    ins(6, 130);
    printQueue();

    for (int i = 0; i < 5; ++i) {
        Node* n = rem();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
    }
    printQueue();

}