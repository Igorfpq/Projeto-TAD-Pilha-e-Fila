
#include "aluno.h"
#include <stdio.h>
#include <string.h>

int main(void) {
    ListaAlunos lista;
    lista_init(&lista, 0);

    Aluno a1 = {.id = 101, .media = 8.5f};
    strcpy(a1.nome, "Ana");
    Aluno a2 = {.id = 102, .media = 7.2f};
    strcpy(a2.nome, "Bruno");
    Aluno a3 = {.id = 103, .media = 9.0f};
    strcpy(a3.nome, "Carla");

    printf(">>> Inserindo alunos...\n");
    printf("Inseriu Ana? %s\n", lista_inserir(&lista, a1) ? "sim" : "nao");
    printf("Inseriu Bruno? %s\n", lista_inserir(&lista, a2) ? "sim" : "nao");
    printf("Inseriu Carla? %s\n", lista_inserir(&lista, a3) ? "sim" : "nao");

    lista_imprimir(&lista);

    printf("\n>>> Buscando id=102...\n");
    Aluno* achado = lista_buscar(&lista, 102);
    if (achado) {
        printf("Encontrado: id=%d nome=%s media=%.2f\n", achado->id, achado->nome, achado->media);
    } else {
        printf("Nao encontrado.\n");
    }

    printf("\n>>> Removendo id=101...\n");
    printf("Removeu? %s\n", lista_remover(&lista, 101) ? "sim" : "nao");
    lista_imprimir(&lista);

    lista_destroy(&lista);
    return 0;
}
