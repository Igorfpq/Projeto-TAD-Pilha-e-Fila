
#ifndef FILA_H
#define FILA_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int* dados;         
    size_t capacidade;
    size_t frente;    
    size_t tras;       
    size_t tamanho;    
} Fila;

void fila_init(Fila* f, size_t capacidade);
void fila_destroy(Fila* f);
bool fila_vazia(const Fila* f);
bool fila_cheia(const Fila* f);
bool fila_enfileirar(Fila* f, int valor); 
bool fila_desenfileirar(Fila* f, int* out); 
bool fila_primeiro(const Fila* f, int* out); 
void fila_mostrar(const Fila* f);

#endif // FILA_H
