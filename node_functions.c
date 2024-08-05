#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node_functions.h"


void adicionarNodeFinal(Node **head)
{
    // receber valor para inserir em node
    int valorPassado = pegarValorInt();


    // condição de não existirem nodes
    if (*head == NULL)
    {
        Node *novoNode = malloc(sizeof(Node));
        if (novoNode == NULL)
        {
            printf("Falha ao alocar memória para Node\n");
            exit(0);
        }

        novoNode->value = valorPassado;
        novoNode->next = NULL;

        *head = novoNode;

        return;
    }
    
    // iteração para encontrar o último node e fazer append de novo node
    for (Node *next = *head; next != NULL; next = next->next)
    {
        if (next->next == NULL)
        {
            Node *novoNode = malloc(sizeof(Node));
            if (novoNode == NULL)
            {
                printf("Falha ao alocar memória para Node\n");
                exit(0);
            }
            
            novoNode->value = valorPassado;
            novoNode->next = NULL;

            next->next = novoNode;

            return;
        }
    }
}


void removerNodeFinal(Node **head)
{
    // condição de não existirem nodes
    if (*head == NULL)
    {
        printf("Nenhum node apagado\n");
        return;
    }
    
    // iteração para encontrar o penúltimo node e excluir o útimo node
    for (Node *node = *head; node != NULL; node = node->next)
    {
        // condição de só existir o primeiro node
        if (node->next == NULL)
        {
            printf("Apagado node de valor %d\n", node->value);
            
            free(node);
            node = NULL;
            
            *head = NULL;
            return;
        }

        // condição próximos nodes na cadeia
        Node *proximoNode = node->next;
        if (proximoNode->next == NULL)
        {
            printf("Apagado node de valor %d\n", proximoNode->value);
            
            free(proximoNode);
            proximoNode = NULL;
            
            node->next = NULL;
            return;
        }
    }
}


void printarNodes(Node **head)
{
    // condição de não existirem nodes
    if (*head == NULL)
    {
        printf("\nNenhum node\n");
        return;
    }

    printf("*****************************************\n");
    printf("Nodes: \n\n");
    int quantidadeNodes = 0;


    // iteração entre nodes
    for (Node *next = *head; next != NULL; next = next->next)
    {
        printf("N%d = %d\n", quantidadeNodes, next->value);
        quantidadeNodes++;
    }
    
    printf("\n\n");
    printf("Total de nodes: %d\n\n", quantidadeNodes);
    return;
}



int pegarValorInt()
{
    while (true)
    {
        int valor = 0;

        printf("\nDigite o valor a ser acrescentado na lista:\n");
        
        if (1 == scanf("%d", &valor))
        {
            return valor;
        }
        else
        {
            printf("Valor inválido\n");
            while (getchar() != '\n');
        }
    }
}