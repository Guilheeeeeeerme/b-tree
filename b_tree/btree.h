
#include "btree-node.h"

typedef struct BTree {
    BTreeNode *root;
    void (*add)(struct BTree* self, int key);
    void (*show)(struct BTree* self);
} BTree;

BTree BTree__new();
void BTreeNode__show(BTreeNode* x);
int BTreeSearch (BTreeNode* x, int k, BTreeNode* y);
int BTreeSearchAndDelete (BTreeNode* x, int k);
void BTreeNode_show(BTreeNode* x);
