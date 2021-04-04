#include "../geek.h"

void pushFront(TwoLinkList *lst, int data) {
    TwoLinkNode *new = (TwoLinkNode*) malloc(sizeof(TwoLinkNode));
    new->dat = data;
    new->prev = NULL;
    new->next = lst->head;
    if (lst->head != NULL) {
        lst->head->prev = new;
    }
    if (lst->tail == NULL) {
        lst->tail = new;
    }
    lst->head = new;
    lst->size++;
}

void pushBack(TwoLinkList *lst, int data) {
    TwoLinkNode *new = (TwoLinkNode *) malloc(sizeof(TwoLinkNode));
    new->dat = data;
    new->next = NULL;
    new->prev = lst->tail;
    if (lst->tail != NULL) {
        lst->tail->next = new;
    }
    if (lst->head == NULL) {
        lst->head = new;
    }
    lst->tail = new;
    lst->size++;
}

TwoLinkNode* remFront(TwoLinkList *lst) {
    if (lst->head == NULL) {
        return NULL;
    }
    TwoLinkNode *tmp = lst->head;
    lst->head = lst->head->next;
    if (lst->head != NULL) {
        lst->head->prev = NULL;
    }
    if (tmp == lst->tail) {
        lst->tail = NULL;
    }
    lst->size--;
    return tmp;
}

TwoLinkNode* remBack(TwoLinkList *lst) {
    if (lst->tail == NULL) {
        return NULL;
    }
    TwoLinkNode *tmp = lst->tail;
    lst->tail = lst->tail->prev;
    if (lst->tail != NULL) {
        lst->tail->next = NULL;
    }
    if (tmp == lst->head) {
        lst->head = NULL;
    }
    lst->size--;
    return tmp;
}
void twoLinkListTest() {
    TwoLinkList *lst = (TwoLinkList*) malloc(sizeof(TwoLinkList));
    initTwoLinkList(lst);
    printTwoLinkIntList(lst);
    pushFront(lst, 20);
    pushFront(lst, 10);
    pushBack(lst, 30);
    pushBack(lst, 40);
    printTwoLinkIntList(lst);
    printTwoLinkIntNode(remFront(lst)); printf("<- node \n");
    printTwoLinkIntList(lst);
    printTwoLinkIntNode(remBack(lst)); printf("<- node \n");
    printTwoLinkIntList(lst);
    printTwoLinkIntNode(remFront(lst)); printf("<- node \n");
    printTwoLinkIntNode(remFront(lst)); printf("<- node \n");
    printTwoLinkIntList(lst);
}
