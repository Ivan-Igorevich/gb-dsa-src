#include <stdio.h>
#include <stdlib.h>

#define T char
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1

typedef int boolean;
int cursor = -1;
T Stack[SIZE];

boolean pushStack(T data) {
    if (cursor < SIZE) {
        Stack[++cursor] = data;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T popStack() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

void arrstackTest() {
    pushStack('a');
    pushStack('b');
    pushStack('c');
    pushStack('d');
    pushStack('e');
    pushStack('f');
    while (cursor != -1) {
        printf("%c ", popStack());
    }
    popStack();
}