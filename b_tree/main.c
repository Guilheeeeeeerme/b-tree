#include <stdio.h>
#include "btree.h"

int main() {
    BTree bTree = BTree__new();
    int k;
    int busca;


    for(int i =0; i< 100; i++)
        bTree.add(&bTree, i);

    printf("var bTree = ");
    bTree.show(&bTree);

    //BTreeNode_show(bTree.root);



    BTreeNode* nodeBusca = BTreeNode__new();
    BTreeNode* auxi = BTreeNode__new();
    auxi = bTree.root;
    //printf("\n%d",auxi);
    //printf("\n%d",bTree.root->keys[1]);
    //printf("\n\n\n\n\n");
    //BTreeNode_show(auxi);
    nodeBusca->leaf = FALSE;
    //printf("\n%d",nodeBusca->leaf);
    //BTreeNode_show(nodeBusca);
    printf("\nInsira o valor a ser pesquisado: ");
    scanf("%d", &k);

    busca = BTreeSearch(bTree.root,k,nodeBusca);

    if(busca == -1){
        printf("\nnada foi encontrado");
    }
    else{
    printf("\nO node eh:\n");
    BTreeNode_show(nodeBusca);
    printf("\nO indice eh: %d",busca);
    //free(nodeBusca);
    }


    return 0;
}
