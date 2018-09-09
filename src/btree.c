#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "array.h"

void BTree__Delete(BTree *self, int k)
{
}

void BTreeSplitChild(BTreeNode *target, int insertAt)
{

    BTreeNode *right = BTreeNode__new(); // z
    BTreeNode *left = target->children[insertAt];

    right->leaf = left->leaf;

    right->n = T - 1;
    for (int j = 0; j < right->n; j++)
    {
        right->keys[j] = left->keys[j + T];
    }

    if (!left->leaf)
    {
        for (int j = 0; j < T; j++)
        {
            right->children[j] = left->children[j + T];
        }
    }

    left->n = T - 1;

    for (int j = target->n; j > insertAt; j--)
    {
        target->children[j + 1] = target->children[j];
    }

    target->children[insertAt + 1] = right;

    for (int j = target->n; j > insertAt; j--)
    {
        target->keys[j] = target->keys[j - 1];
    }

    target->keys[insertAt] = left->keys[T - 1];
    target->n++;
}

void BTreeInsertNonfull(BTreeNode *x, int k)
{

    if (x->leaf)
    {

        x->keys[x->n] = k;
        x->n++;
        insertionSort(x->keys, x->n);
    }
    else
    {

        int i = x->n;

        while (i > 0 && k < x->keys[i - 1])
        {
            i--;
        }

        if (x->children[i]->n == ((2 * T) - 1))
        {
            BTreeSplitChild(x, i);

            if (k > x->keys[i])
            {
                i = i + 1;
            }
        }
        BTreeInsertNonfull(x->children[i], k);
    }
}

int BTree__Search(BTree *x, int k, BTreeNode *y)
{
    BTreeNode *r = x->root;
    return BTreeNode__Search(r, k, y);
}

void BTree__Show(BTree *self)
{
    BTreeNode__Show(self->root);
}

void BTree__Add(BTree *self, int k)
{

    BTreeNode *r = self->root;

    if (r->n == ((2 * T) - 1))
    {
        BTreeNode *s = BTreeNode__new();

        self->root = s;
        s->leaf = FALSE;
        s->n = 0;
        s->children[0] = r;

        BTreeSplitChild(s, 0);
        BTreeInsertNonfull(s, k);
    }
    else
    {
        BTreeInsertNonfull(r, k);
    }
}

BTree BTree__new()
{
    BTree bTree;
    bTree.root = BTreeNode__new();
    return bTree;
};