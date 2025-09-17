
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void garantir_capacidade(ListaAlunos* lista) {
    if (lista->tamanho < lista->capacidade) return;
    size_t nova = (lista->capacidade == 0) ? 4 : lista->capacidade * 2;
    Aluno* tmp = (Aluno*)realloc(lista->dados, nova * sizeof(Aluno));
    if (!tmp) {
        fprintf(stderr, "Erro: sem memoria para realocar lista.\n");
        exit(EXIT_FAILURE);
    }
    lista->dados = tmp;
    lista->capacidade = nova;
}

void lista_init(ListaAlunos* lista, size_t capacidade_inicial) {
    lista->tamanho = 0;
    lista->capacidade = capacidade_inicial;
    if (capacidade_inicial > 0) {
        lista->dados = (Aluno*)malloc(capacidade_inicial * sizeof(Aluno));
        if (!lista->dados) {
            fprintf(stderr, "Erro: sem memoria para lista inicial.\n");
            exit(EXIT_FAILURE);
        }
    } else {
        lista->dados = NULL;
    }
}

void lista_destroy(ListaAlunos* lista) {
    free(lista->dados);
    lista->dados = NULL;
    lista->tamanho = 0;
    lista->capacidade = 0;
}

bool lista_inserir(ListaAlunos* lista, Aluno a) {
    // impede ids duplicados
    if (lista_buscar(lista, a.id) != NULL) {
        return false;
    }
    garantir_capacidade(lista);
    lista->dados[lista->tamanho++] = a;
    return true;
}

Aluno* lista_buscar(ListaAlunos* lista, int id) {
    for (size_t i = 0; i < lista->tamanho; ++i) {
        if (lista->dados[i].id == id) return &lista->dados[i];
    }
    return NULL;
}

bool lista_remover(ListaAlunos* lista, int id) {
    for (size_t i = 0; i < lista->tamanho; ++i) {
        if (lista->dados[i].id == id) {
            lista->dados[i] = lista->dados[lista->tamanho - 1];
            lista->tamanho--;
            return true;
        }
    }
    return false;
}

void lista_imprimir(const ListaAlunos* lista) {
    printf("Lista de Alunos (tamanho=%zu):\n", lista->tamanho);
    for (size_t i = 0; i < lista->tamanho; ++i) {
        printf("  id=%d, nome=%s, media=%.2f\n",
               lista->dados[i].id, lista->dados[i].nome, lista->dados[i].media);
    }
}
