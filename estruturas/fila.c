
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void fila_init(Fila* f, size_t capacidade) {
    f->dados = (int*)malloc(capacidade * sizeof(int));
    if (!f->dados) { perror("malloc"); exit(EXIT_FAILURE); }
    f->capacidade = capacidade;
    f->frente = 0;
    f->tras = 0;
    f->tamanho = 0;
}

void fila_destroy(Fila* f) {
    free(f->dados);
    f->dados = NULL;
    f->capacidade = f->frente = f->tras = f->tamanho = 0;
}

bool fila_vazia(const Fila* f) { return f->tamanho == 0; }
bool fila_cheia(const Fila* f) { return f->tamanho == f->capacidade; }

bool fila_enfileirar(Fila* f, int valor) {
    if (fila_cheia(f)) return false;
    f->dados[f->tras] = valor;
    f->tras = (f->tras + 1) % f->capacidade;
    f->tamanho++;
    return true;
}

bool fila_desenfileirar(Fila* f, int* out) {
    if (fila_vazia(f)) return false;
    if (out) *out = f->dados[f->frente];
    f->frente = (f->frente + 1) % f->capacidade;
    f->tamanho--;
    return true;
}

bool fila_primeiro(const Fila* f, int* out) {
    if (fila_vazia(f)) return false;
    if (out) *out = f->dados[f->frente];
    return true;
}

void fila_mostrar(const Fila* f) {
    printf("Fila (tam=%zu): ", f->tamanho);
    for (size_t i = 0, idx = f->frente; i < f->tamanho; ++i) {
        printf("%d ", f->dados[idx]);
        idx = (idx + 1) % f->capacidade;
    }
    printf("\n");
}
