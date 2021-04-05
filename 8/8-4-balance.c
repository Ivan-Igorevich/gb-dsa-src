#include "../geek.h"

FILE *file;

BinTreeIntNode* balancedTree(int n) {
    BinTreeIntNode *newNode;
    int x;
    int nL;
    int nR;

    if (n == 0) {
        return NULL;
    } else {
        fscanf(file, "%d", &x);
        nL = n / 2;
        nR = n - nL - 1;
        newNode = (BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
        newNode->key = x;
        newNode->left = balancedTree(nL);
        newNode->right = balancedTree(nR);
    }
    return newNode;
}

void balanceTest() {
    BinTreeIntNode *tree = NULL;
    file = fopen("../sources/8/balance.txt", "r");
    if (file == NULL) {
        printf("%s \n", "Cannot open file");
        return;
    }
    const int count = 15;
    tree = balancedTree(count);
    fclose(file);
    printBinTree(tree);
}