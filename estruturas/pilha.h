
#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int* dados;   
    size_t capacidade;
    long topo;        
} Pilha;

void pilha_init(Pilha* p, size_t capacidade);
void pilha_destroy(Pilha* p);
bool pilha_vazia(const Pilha* p);
bool pilha_cheia(const Pilha* p);
bool pilha_push(Pilha* p, int valor); 
bool pilha_pop(Pilha* p, int* out);  
bool pilha_peek(const Pilha* p, int* out); 
void pilha_mostrar(const Pilha* p);

#endif 
