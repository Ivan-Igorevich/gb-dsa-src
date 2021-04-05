#include "../geek.h"

void preOrderTravers(BinTreeIntNode *root) {
    if (root) {
        printf("%2d ", root->key);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void inOrderTravers(BinTreeIntNode *root) {
    if (root) {
        inOrderTravers(root->left);
        printf("%2d ", root->key);
        inOrderTravers(root->right);
    }
}

void postOrderTravers(BinTreeIntNode *root) {
    if (root) {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%2d ", root->key);
    }
}

void traversTest() {
    BinTreeIntNode *tree = treeInsert(tree, 10);
    treeInsert(tree, 8);
    treeInsert(tree, 19);
    treeInsert(tree, 5);
    treeInsert(tree, 9);
    treeInsert(tree, 16);
    treeInsert(tree, 21);
    printBinTree(tree);
    printf(" \n");
    preOrderTravers(tree);
    printf(" \n");
    inOrderTravers(tree);
    printf(" \n");
    postOrderTravers(tree);
    printf(" \n");

}