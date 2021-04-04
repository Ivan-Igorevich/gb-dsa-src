#include "../geek.h"

void insert(OneLinkList *lst, int data) {
    OneLinkNode *new = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    new->dat = data;
    new->next = NULL;

    OneLinkNode *current = lst->head;
    if (current == NULL) {
        lst->head = new;
        lst->size++;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        lst->size++;
    }
}

OneLinkNode* rm(OneLinkList *lst, int data) {
    OneLinkNode *current = lst->head;
    OneLinkNode *parent = NULL;
    if (current == NULL)
        return NULL;

    while (current->next != NULL && current->dat != data) {
        parent = current;
        current = current->next;
    }
    if (current->dat != data) {
        return NULL;
    }
    if (current == lst->head) {
        lst->head = current->next;
        lst->size--;
        return current;
    }
    parent->next = current->next;
    lst->size--;
    return current;
}

void oneLinkTest() {
    OneLinkList *lst = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(lst);
    printOneLinkIntList(lst);
    insert(lst, 1);
    printOneLinkIntList(lst);
    insert(lst, 10);
    printOneLinkIntList(lst);
    printOneLinkIntNode(rm(lst, 1)); printf("<- removed node\n");
    printOneLinkIntList(lst);
    printOneLinkIntNode(rm(lst, 2)); printf("<- removed node\n");
    printOneLinkIntList(lst);
}