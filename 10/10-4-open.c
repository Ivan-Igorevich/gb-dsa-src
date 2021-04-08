
#include "../geek.h"

typedef struct {
    int data;
    int key;
} KeyNode;

KeyNode** hashTable;
int hashTableSize;

KeyNode *nullItem;
boolean insertNode(int data);

int hashFunc(int key) {
    return key % hashTableSize;
}

KeyNode* createNode(int data) {
    KeyNode *p = (KeyNode*) malloc(sizeof(KeyNode));
    if (!p) {
        printf("Out of memory \n");
        return NULL;
    }
    p->data = data;
    p->key = data;
    return p;
}

void initTable(int size, int idx) {
    for (int i = idx; i < size; ++i) {
        hashTable[i] = NULL;
    }
}

boolean isFull() {
    for (int i = 0; i < hashTableSize; ++i) {
        if (hashTable[i] == NULL || hashTable[i] == nullItem)
            return false;
    }
    return true;
}

void increaseCapacity() {
    hashTableSize *= 2;
    KeyNode** oldHashTable = hashTable;
    hashTable = (KeyNode**) calloc(hashTableSize, sizeof(KeyNode*));
    int i;
    for (i = 0; i < hashTableSize / 2; ++i)
        insertNode(oldHashTable[i]->data);
    initTable(hashTableSize, i);
    free(oldHashTable);
}

int linearProbe(int val) {
    ++val;
    val %= hashTableSize;
    return val;
}

int quadProbe(int val, int step) {
    val += step * step;
    val %= hashTableSize;
    return val;
}

int hashFuncDbl(int key) {
    return 19 - key % 19;
}

boolean insertNode(int data) {
    KeyNode *node = createNode(data);
    if (!node) return false;

    int hashVal = hashFunc(node->key);
    if (isFull()) increaseCapacity();
    //int step = 0;
    int step = hashFuncDbl(node->key);
    while (hashTable[hashVal] && hashTable[hashVal] != nullItem) {
        //hashVal = linearProbe(hashVal);
        //hashVal = quadProbe(hashVal, ++step);
        hashVal += step;
        hashVal %= hashTableSize;
    }
    hashTable[hashVal] = node;
    return true;
}

KeyNode* findNode(int data) {
    int key = data;
    int hashVal = hashFunc(key);
//    int step = 0;
    int step = hashFuncDbl(key);
    while (hashTable[hashVal]) {
        if (hashTable[hashVal]->key == key) {
            return hashTable[hashVal];
        }
        //hashVal = linearProbe(hashVal);
        //hashVal = quadProbe(hashVal, ++step);
        hashVal += step;
        hashVal %= hashTableSize;
    }
    return NULL;
}

KeyNode* deleteNode(int data) {
    int key = data;
    int hashVal = hashFunc(key);
//    int step = 0;
    int step = hashFuncDbl(key);
    while (hashTable[hashVal]) {
        if (hashTable[hashVal]->key == key) {
            KeyNode *temp = hashTable[hashVal];
            hashTable[hashVal] = nullItem;
            return temp;
        }
        //hashVal = linearProbe(hashVal);
        //hashVal = quadProbe(hashVal, ++step);
        hashVal += step;
        hashVal %= hashTableSize;
    }
    return NULL;
}

void prntNode(KeyNode *n) {
    if (!n) {
        printf("[*,*]");
        return;
    }
    printf("[k=%d,d=%d]", n->key, n->data);
}

void prntTbl() {
    for (int i = 0; i < hashTableSize; ++i) {
        prntNode(hashTable[i]);
    }
    printf("\n");
}

void openTest() {
    hashTableSize = 25;
    hashTable = (KeyNode**) calloc(hashTableSize, sizeof(KeyNode*));
    nullItem = createNode(-1);

    insertNode(10);
    insertNode(10);
    insertNode(20);
    insertNode(30);
    insertNode(75);
    insertNode(57);
    insertNode(50);
    insertNode(60);
    insertNode(70);
    insertNode(100);
    insertNode(125);
    insertNode(1);
    prntTbl();

    deleteNode(10);
    deleteNode(20);
    prntTbl();

    prntNode(findNode(25));
    prntNode(findNode(125));
}
