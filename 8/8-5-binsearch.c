#include "../geek.h"

boolean binSearch(BinTreeIntNode *root, int value) {
    if (root == NULL)
        return false;
    if (root->key == value)
        return true;

    BinTreeIntNode *current = root;
    while (current->key != value) {
        if (value < current->key)
            current = current->left;
        else
            current = current->right;

        if (current == NULL)
            return false;
    }
}

void binSearchTest() {
    BinTreeIntNode *tree = treeInsert(tree, 10);
    treeInsert(tree, 8);
    treeInsert(tree, 19);
    treeInsert(tree, 5);
    treeInsert(tree, 9);
    treeInsert(tree, 16);
    treeInsert(tree, 21);
    printBinTree(tree);
    printf(" \n");

    printf("8 in tree = %s \n", binSearch(tree, 8) ? "true" : "false");
    printf("100 in tree = %s \n", binSearch(tree, 100) ? "true" : "false");
}