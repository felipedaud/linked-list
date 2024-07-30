#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "node_functions.h"

int menuOpcoes();
void menuLoop();

// criação do início da linked list
Node *inicio_lista = NULL;


int main(int argc, char **argv)
{
    printf("\n\n\n__________________________________________________________________________________\n");
    printf("Criador de linked list\n");

    menuLoop();

    return 0;
}

void menuLoop()
{
    while (true)
    {
        int opcao = menuOpcoes();

        switch (opcao)
        {
            case 1:
                printarNodes(&inicio_lista);
                break;
            
            case 2:
                adicionarNodeFinal(&inicio_lista);
                break;
            
            case 3:
                removerNodeFinal(&inicio_lista);
                break;
            
            case 4:
                exit(0);
            
            default:
                exit(1);
        }
    }
}


int menuOpcoes()
{
    while (true)
    {
        int opcao = 0;

        printf("________________________________________________________________\n");
        printf("Selecione as opcoes abaixo:\n");
        printf(" 1 - Printar valores da lista\n");
        printf(" 2 - Adicionar um valor no final da lista\n");
        printf(" 3 - Remover um valor no final da lista\n");
        printf(" 4 - Sair do programa\n");

        scanf("%d", &opcao);
        printf("\n\n\n");

        if (1 <= opcao && 4 >= opcao)
        {
            return opcao;
        }

        while (getchar() != '\n');
    }
}
