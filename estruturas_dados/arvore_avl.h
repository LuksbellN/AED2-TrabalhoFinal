#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

#include "vetor.h"

typedef struct NoCandidatoAVL
{
    struct candidato candidato;
    int fator;
    int altura;
    struct NoCandidatoAVL *esquerda, *direita, *pai;
} NoCandidatoAVL;

NoCandidatoAVL *insere_arvore_binaria_AVL(NoCandidatoAVL *raiz, const struct candidato *novo_candidato);

NoCandidatoAVL *ler_arquivo_arvore_binaria_AVL(const char *caminho);

NoCandidatoAVL *rotacionar_direita(NoCandidatoAVL *raiz);
NoCandidatoAVL *rotacionar_esquerda(NoCandidatoAVL *raiz);

void imprimir_avl(struct NoCandidatoAVL *raiz);

int altura(NoCandidatoAVL *raiz);

void liberar_arvore_avl(NoCandidatoAVL *raiz);

#endif
