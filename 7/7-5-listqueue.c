#include "../geek.h"

void listQueueTes() {
    TwoLinkList *q = (TwoLinkList*) malloc(sizeof(TwoLinkList));
    initTwoLinkList(q);
    TwoLinkEnqueue(q, 'a');
    TwoLinkEnqueue(q, 'b');
    TwoLinkEnqueue(q, 'c');
    TwoLinkEnqueue(q, 'd');
    TwoLinkEnqueue(q, 'e');
    printTwoLinkCharList(q);

    printf("%c \n", TwoLinkDequeue(q));
    printf("%c \n", TwoLinkDequeue(q));
    printTwoLinkCharList(q);

    printf("%c \n", TwoLinkDequeue(q));
    printf("%c \n", TwoLinkDequeue(q));
    printf("%c \n", TwoLinkDequeue(q));
    printf("%c \n", TwoLinkDequeue(q));
}