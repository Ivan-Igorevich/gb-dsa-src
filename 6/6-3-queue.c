#include <stdio.h>
#include <stdlib.h>

#define T char
#define SIZE 10
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

T Queue[SIZE];
int first = 0;
int end = -1;
int items = 0;

boolean enqueueA(T data) {
    if (items == SIZE) {
        printf("%s \n", "Queue is full");
        return false;
    }
    if (end == SIZE - 1)
        end = -1;
    Queue[++end] = data;
    items++;
    return true;
}

T dequeueA() {
    if (items == 0) {
        printf("%s \n", "Queue is empty");
        return -1;
    } else {
        char tmp = Queue[first++];
        first %= SIZE; // if (first == SIZE) first = 0;
        items--;
        return tmp;
    }
}

void queueTest() {
    int i = 0;
    while (i < 5) {
        enqueueA('a');
        enqueueA('b');
        enqueueA('c');
        enqueueA('d');
        enqueueA('e');
        enqueueA('f');
        while (items > 0) {
            printf("%c ", dequeueA());
        }
        printf("\n");
        i++;
    }
};
