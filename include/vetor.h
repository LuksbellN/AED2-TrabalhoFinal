#ifndef VETOR_H
#define VETOR_H

#include "processa_dados.h"

int ler_arquivo_vetor(const char *caminho, struct candidato **vetor,
                      int *tamanho_atual, int *indice);

void realocar_vetor(struct candidato **vetor, int *tamanho_atual);

void exibir_dados(struct candidato *vetor, int n);

#endif
