#ifndef BUSCAS_VETOR_H
#define BUSCAS_VETOR_H

#include "menu_filtros.h"
#include "processa_dados.h"

ResultadoDinamico busca_estado_vetor(struct candidato *vetor, int indice,
                                     char *estado);

ResultadoDinamico busca_estado_cidade_vetor(struct candidato *vetor, int indice,
                                            char *estado, char *cidade);

void busca_estado_cidade_numero_vetor(struct candidato *vetor, int indice,
                                      char *estado, char *cidade,
                                      int nr_candidato);

#endif