#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "btree-node.h"

int BTreeNode__Search(BTreeNode *r, int k, BTreeNode *y)
{
    int i = 0;
    while ((i < r->n) && (k > r->keys[i]))
    {
        i++;
    }
    if (i < r->n && k == r->keys[i])
    {
        *y = *r;
        return i;
    }
    else if (r->leaf)
    {
        return (-1);
    }
    else
    {
        return BTreeNode__Search(r->children[i], k, y);
    }
}

void BTreeNode__Show(BTreeNode *x)
{
    printf("\n{");

    if (x)
    {
        printf("\"leaf\": %d, ", x->leaf);
        printf("\"n\": %d ,", x->n);
        printf("\"keys\": ");
        printArray(x->keys, x->n);
        printf(" ,\"children\": [");

        if (!x->leaf)
        {
            int i;

            for (i = 0; i < x->n; i++)
            {
                BTreeNode__Show(x->children[i]);
                printf(",");
            }

            BTreeNode__Show(x->children[i]);
        }

        printf("]");
    }

    printf("}");
}

BTreeNode *BTreeNode__new()
{

    BTreeNode *bTreeNode = (BTreeNode *)malloc(sizeof(BTreeNode));

    bTreeNode->n = 0;
    bTreeNode->leaf = TRUE;

    for (int i = 0; i < (CHILDREN); i++)
    {
        bTreeNode->children[i] = NULL;
    }

    return bTreeNode;
}