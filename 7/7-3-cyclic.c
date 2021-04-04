#include "../geek.h"


//typedef struct OneLinkNode {
//    int dat;
//    struct OneLinkNode *next;
//} OneLinkNode;
//
//typedef struct {
//    OneLinkNode *head;
//    int size;
//} OneLinkList;

void insetCyclic(OneLinkList *lst, int data) {
    OneLinkNode *new = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    new->dat = data;
    new->next = lst->head;

    OneLinkNode *current = lst->head;
    if (current == NULL) {
        lst->head = new;
        new->next = lst->head;
        lst->size++;
        return;
    } else {
        while (current->next != lst->head) {
            current= current->next;
        }
        current->next = new;
        lst->size++;
    }
}

OneLinkNode* removeCyclic(OneLinkList *lst, int data) {
    OneLinkNode *current = lst->head;
    OneLinkNode *parent = NULL;

    if (current == NULL) {
        return NULL;
    }
    while (current->next != lst->head && current->dat != data) {
        parent = current;
        current = current->next;
    }
    if (current->dat != data) {
        return NULL;
    }
    if (current == lst->head) {
        if (current->next == lst->head) {
            lst->head = NULL;
            lst->size--;
            return current;
        } else {
            OneLinkNode *tmp = current;
            while (current->next != lst->head) {
                current = current->next;
            }
            lst->head = tmp->next;
            current->next = lst->head;
            lst->size--;
            return tmp;
        }
    }
    parent->next = current->next;
    lst->size--;
    return current;
}

void cyclicTest() {
    OneLinkList *l = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(l);
    printCyclicIntList(l);
    insetCyclic(l, 1);
    insetCyclic(l, 10);
    printCyclicIntList(l);

    printOneLinkIntNode(removeCyclic(l, 1)); printf("<- node \n");
    printCyclicIntList(l);
    printOneLinkIntNode(removeCyclic(l, 1)); printf("<- node \n");
    printCyclicIntList(l);

    insetCyclic(l, 20);
    printCyclicIntList(l);
    printOneLinkIntNode(removeCyclic(l, 10)); printf("<- node \n");
    printOneLinkIntNode(removeCyclic(l, 20)); printf("<- node \n");
    printCyclicIntList(l);

}