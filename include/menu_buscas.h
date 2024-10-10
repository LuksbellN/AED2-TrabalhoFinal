#ifndef MENU_BUSCAS_H
#define MENU_BUSCAS_H

#include "buscas_arvore_avl.h"
#include "buscas_arvore_binaria.h"
#include "buscas_vetor.h"
#include "menu_filtros.h"
#include "processa_dados.h"


void busca_estado(struct candidato *vetor, int indice, ArvoreBinaria *arvore,
                  ArvoreAVL *arvore_avl, int estrutura_dados);

void busca_estado_cidade(struct candidato *vetor, int indice,
                         ArvoreBinaria *arvore, ArvoreAVL *arvore_avl,
                         int estrutura_dados);

void busca_estado_cidade_numero(struct candidato *vetor, int indice,
                                ArvoreBinaria *arvore, ArvoreAVL *arvore_avl,
                                int estrutura_dados);

#endif
