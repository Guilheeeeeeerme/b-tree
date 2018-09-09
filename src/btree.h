
#include "btree-node.h"

typedef struct BTree
{
    BTreeNode *root;
} BTree;

BTree BTree__new();
void BTree__Add(BTree *self, int k);
void BTree__Show(BTree *self);
int BTree__Search(BTree *self, int k, BTreeNode *y);
void BTree__Delete(BTree *self, int k);