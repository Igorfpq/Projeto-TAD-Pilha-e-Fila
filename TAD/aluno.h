
#ifndef ALUNO_H
#define ALUNO_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    int id;             
    char nome[64];      
    float media;         
} Aluno;


typedef struct {
    Aluno* dados;        
    size_t tamanho;      
    size_t capacidade;  
} ListaAlunos;

void lista_init(ListaAlunos* lista, size_t capacidade_inicial);
void lista_destroy(ListaAlunos* lista);

bool lista_inserir(ListaAlunos* lista, Aluno a);

Aluno* lista_buscar(ListaAlunos* lista, int id);

bool lista_remover(ListaAlunos* lista, int id);

void lista_imprimir(const ListaAlunos* lista);

#endif // ALUNO_H
