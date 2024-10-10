#ifndef MENU_FILTROS_H
#define MENU_FILTROS_H

#include "processa_dados.h"

typedef struct {
    struct candidato *vetor;
    int tamanho;
    int capacidade;
} ResultadoDinamico;

void adicionar_ao_vetor_resultado(struct candidato **vetor, int *tamanho, int *capacidade, struct candidato* novo);

void carregar_menu(ResultadoDinamico *resultado);

void filtrar_genero(ResultadoDinamico *resultado);

void filtrar_partido(ResultadoDinamico *resultado);

void filtrar_cor_raca(ResultadoDinamico *resultado);

#endif
