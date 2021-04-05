#include "../geek.h"

void binTreeTest() {
    BinTreeIntNode *tree = treeInsert(tree, 10);
    treeInsert(tree, 8);
    treeInsert(tree, 19);
    treeInsert(tree, 5);
    treeInsert(tree, 9);
    treeInsert(tree, 16);
    treeInsert(tree, 21);
    printBinTree(tree);
    printf(" \n");

    treeNodeDelete(tree, 5);
    printBinTree(tree);
    printf(" \n");
    treeNodeDelete(tree, 19);
    printBinTree(tree);
    printf(" \n");
    treeNodeDelete(tree, 8);
    printBinTree(tree);
    printf(" \n");
}
