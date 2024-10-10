#ifndef BUSCAS_ARVORE_AVL_H
#define BUSCAS_ARVORE_AVL_H

#include "arvore_avl.h"
#include "menu_filtros.h"
#include "processa_dados.h"

ResultadoDinamico busca_estado_arvore_AVL(NoCandidatoAVL *raiz, char *estado);

ResultadoDinamico busca_estado_cidade_arvore_AVL(NoCandidatoAVL *raiz,
                                                 char *estado, char *cidade);

void busca_estado_cidade_numero_arvore_AVL(NoCandidatoAVL *raiz, char *estado,
                                           char *cidade, int nr_candidato);

#endif