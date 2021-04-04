#include "../geek.h"

void listStackTest() {
    OneLinkList *st = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(st);
    pushOneLinkStack(st, 'a');
    pushOneLinkStack(st, 'b');
    pushOneLinkStack(st, 'c');
    pushOneLinkStack(st, 'd');
    pushOneLinkStack(st, 'e');
    printOneLinkCharList(st);
    printf("%c \n", popOneLinkStack(st));
    printOneLinkCharList(st);
    printf("%c \n", popOneLinkStack(st));
    printOneLinkCharList(st);
    printf("%c \n", popOneLinkStack(st));
    printOneLinkCharList(st);
    printf("%c \n", popOneLinkStack(st));
    printf("%c \n", popOneLinkStack(st));
    printf("%c \n", popOneLinkStack(st));
}
