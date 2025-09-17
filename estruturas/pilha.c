
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

void pilha_init(Pilha* p, size_t capacidade) {
    p->dados = (int*)malloc(capacidade * sizeof(int));
    if (!p->dados) { perror("malloc"); exit(EXIT_FAILURE); }
    p->capacidade = capacidade;
    p->topo = -1;
}

void pilha_destroy(Pilha* p) {
    free(p->dados);
    p->dados = NULL;
    p->capacidade = 0;
    p->topo = -1;
}

bool pilha_vazia(const Pilha* p) { return p->topo < 0; }
bool pilha_cheia(const Pilha* p) { return (size_t)(p->topo + 1) >= p->capacidade; }

bool pilha_push(Pilha* p, int valor) {
    if (pilha_cheia(p)) return false;
    p->dados[++(p->topo)] = valor;
    return true;
}

bool pilha_pop(Pilha* p, int* out) {
    if (pilha_vazia(p)) return false;
    if (out) *out = p->dados[p->topo];
    p->topo--;
    return true;
}

bool pilha_peek(const Pilha* p, int* out) {
    if (pilha_vazia(p)) return false;
    if (out) *out = p->dados[p->topo];
    return true;
}

void pilha_mostrar(const Pilha* p) {
    printf("Pilha (topo=%ld): ", p->topo);
    for (long i = 0; i <= p->topo; ++i) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}
