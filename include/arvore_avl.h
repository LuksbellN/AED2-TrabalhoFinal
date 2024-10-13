#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

#include "processa_dados.h"

NoCandidatoAVL *
insere_arvore_binaria_AVL(NoCandidatoAVL *raiz,
                          const struct candidato *novo_candidato);

void ler_arquivo_arvore_AVL(ArvoreAVL *raiz, const char *caminho);

NoCandidatoAVL* rebalancear_arvore(NoCandidatoAVL* raiz, const struct candidato* novo_candidato, int balanco);
  
NoCandidatoAVL *rotacionar_direita(NoCandidatoAVL *raiz);
NoCandidatoAVL *rotacionar_esquerda(NoCandidatoAVL *raiz);

void imprimir_avl(struct NoCandidatoAVL *raiz);

int altura(NoCandidatoAVL *raiz);

void liberar_arvore_avl(NoCandidatoAVL *raiz);

#endif
