
#include "fila.h"
#include <stdio.h>

int main(void) {
    Fila f;
    fila_init(&f, 5);

    printf(">>> Enfileirando 1,2,3...\n");
    fila_enfileirar(&f, 1);
    fila_enfileirar(&f, 2);
    fila_enfileirar(&f, 3);
    fila_mostrar(&f);

    int primeiro;
    if (fila_primeiro(&f, &primeiro)) {
        printf("Primeiro: %d\n", primeiro);
    }

    printf(">>> Desenfileirando...\n");
    while (fila_desenfileirar(&f, &primeiro)) {
        printf("Saiu: %d\n", primeiro);
    }

    fila_destroy(&f);
    return 0;
}
