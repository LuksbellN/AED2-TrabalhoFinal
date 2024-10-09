#ifndef BUSCAS_VETOR_H
#define BUSCAS_VETOR_H

#include "../estruturas_dados/vetor.h"

void busca_estado_vetor(candidato *vetor, int indice, char *estado);

void busca_estado_cidade_vetor(candidato *vetor, int indice, char *estado, char *cidade);

double busca_estado_cidade_numero_vetor(candidato *vetor, int indice, char *estado, char *cidade, int nr_candidato);


#endif