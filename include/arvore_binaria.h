#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include "processa_dados.h"

NoCandidato *insere(NoCandidato *raiz, const struct candidato *novo_candidato);

void ler_arquivo_arvore_binaria(ArvoreBinaria *raiz, const char *caminho);

int comparar_ordenacao_arvore(struct candidato cand1, struct candidato cand2);

void imprimir(struct NoCandidato *raiz);

NoCandidato *buscarMaior(NoCandidato *raiz);
NoCandidato *buscarMenor(NoCandidato *raiz);
int encontrarAltura(NoCandidato *raiz);

void liberar_arvore(NoCandidato *raiz);

#endif
