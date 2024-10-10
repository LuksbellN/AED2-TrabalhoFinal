#ifndef BUSCAS_ARVORE_BINARIA_H
#define BUSCAS_ARVORE_BINARIA_H

#include "arvore_binaria.h"
#include "menu_filtros.h"
#include "processa_dados.h"

ResultadoDinamico busca_estado_arvore_binaria(NoCandidato *raiz, char *estado);

ResultadoDinamico busca_estado_cidade_arvore_binaria(NoCandidato *raiz,
                                                     char *estado,
                                                     char *cidade);

void busca_estado_cidade_numero_arvore_binaria(NoCandidato *raiz, char *estado,
                                               char *cidade, int nr_candidato);

#endif