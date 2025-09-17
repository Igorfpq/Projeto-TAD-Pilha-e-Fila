
#include "pilha.h"
#include <stdio.h>

int main(void) {
    Pilha p;
    pilha_init(&p, 5);

    printf(">>> Empilhando 10,20,30...\n");
    pilha_push(&p, 10);
    pilha_push(&p, 20);
    pilha_push(&p, 30);
    pilha_mostrar(&p);

    int topo;
    if (pilha_peek(&p, &topo)) {
        printf("Topo atual: %d\n", topo);
    }

    printf(">>> Desempilhando...\n");
    while (pilha_pop(&p, &topo)) {
        printf("Saiu: %d\n", topo);
    }

    pilha_destroy(&p);
    return 0;
}
