#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main()
{
    BTree bTree = BTree__new();
    int k;
    int busca;
    int op = 100;

    for (int i = 1; i <= 11; i++)
        bTree.add(&bTree, i);

    printf("var bTree = ");
    bTree.show(&bTree);

    while (op)
    {
        printf("\n1 - Busca\n2 - Remocao\n3 - Insercao\n");
        scanf("%d", &op);
        if (op == 1)
        {
            BTreeNode *nodeBusca = BTreeNode__new();

            printf("\nInsira o valor a ser pesquisado: ");
            scanf("%d", &k);
            busca = BTreeSearch(bTree.root, k, nodeBusca);

            if (busca == -1)
            {
                printf("\nNada foi encontrado");
            }
            else
            {
                printf("\nO node eh:\n");
                BTreeNode_show(nodeBusca);
                printf("\nO indice eh: %d\n", busca);

                BTreeNode_show(bTree.root);
            }

            printf("Digite 0 pra sair!\n");
            scanf("%d", &op);
        }
        else if (op == 2)
        {
            printf("\nInsira o valor a ser removido: ");
            scanf("%d", &k);
            BTreeNode_Delete(bTree.root, k);
            printf("\n");
            bTree.show(&bTree);
            printf("Digite 0 pra sair!\n");
            scanf("%d", &op);
        }
        else if (op == 3)
        {
            printf("\nValor a ser inserido: ");
            scanf("%d", &k);
            bTree.add(&bTree, k);
            bTree.show(&bTree);

            printf("\nDigite 0 pra sair!\n");
            scanf("%d", &op);
        }
    }

    return 0;
}
