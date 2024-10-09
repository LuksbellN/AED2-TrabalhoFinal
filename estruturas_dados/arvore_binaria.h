#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include "vetor.h"

typedef struct NoCandidato
{
    struct candidato candidato;
    struct NoCandidato *esquerda, *direita;
} NoCandidato;

NoCandidato *insere(NoCandidato *raiz, const struct candidato *novo_candidato);

NoCandidato *ler_arquivo_arvore_binaria(const char *caminho);

int comparar_ordenacao_arvore(struct candidato cand1, struct candidato cand2);

void imprimir(struct NoCandidato *raiz);

NoCandidato *buscarMaior(NoCandidato *raiz);
NoCandidato *buscarMenor(NoCandidato *raiz);
int encontrarAltura(NoCandidato *raiz);

void liberar_arvore(NoCandidato *raiz);

#endif
