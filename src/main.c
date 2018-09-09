#include <stdio.h>
#include "btree.h"

int main()
{
    BTree bTree = BTree__new();
    int k;
    int busca;
    int op = 100;

    do
    {

        printf("\n1 - Busca");
        printf("\n2 - Remocao");
        printf("\n3 - Insercao");
        printf("\n4 - Mostrar");
        printf("\nDigite 0 pra sair!\n");

        scanf("%d", &op);

        if (op == 1)
        {
            BTreeNode *nodeBusca = BTreeNode__new();

            printf("\nInsira o valor a ser pesquisado: ");
            scanf("%d", &k);
            busca = BTree__Search(&bTree, k, nodeBusca);

            if (busca == -1)
            {
                printf("\nNada foi encontrado");
            }
            else
            {
                printf("\nO node eh:\n");
                BTreeNode__Show(nodeBusca);
                printf("\nO indice eh: %d\n", busca);
            }
        }
        else if (op == 2)
        {
            printf("\nInsira o valor a ser removido: ");
            scanf("%d", &k);
            BTree__Delete(&bTree, k);
        }
        else if (op == 3)
        {
            printf("\nValor a ser inserido: ");
            scanf("%d", &k);
            BTree__Add(&bTree, k);
        }
        else if (op == 4)
        {
            BTree__Show(&bTree);
        }

    } while (op != 0);

    return 0;
}