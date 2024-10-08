#ifndef NODE_FUNCTIONS_H
#define NODE_FUNCTIONS_H


typedef struct {
    int value;
    void *next;
} Node;


void adicionarNodeFinal(Node **head);
void adicionarNodeInicio(Node **head);

void removerNodeFinal(Node **head);
void removerNodeInicio(Node **head);

void printarNodes(Node **head);

int pegarValorInt();

#endif