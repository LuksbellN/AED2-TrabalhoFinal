#include "../include/arvore_avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


NoCandidatoAVL *
insere_arvore_binaria_AVL(NoCandidatoAVL *raiz,
                          const struct candidato *novo_candidato) {
  if (raiz == NULL) {
    NoCandidatoAVL *novoNo = (NoCandidatoAVL *)malloc(sizeof(NoCandidatoAVL));
    if (novoNo == NULL) {
      fprintf(stderr, "Erro: Falha na alocação de memória\n");
      exit(1);
    }
    memcpy(&novoNo->candidato, novo_candidato, sizeof(struct candidato));
    novoNo->esquerda = novoNo->direita = NULL;
    novoNo->fator = 0;
    novoNo->altura = 1;
    return novoNo;
  }

  int cmp = comparar_ordenacao_arvore(*novo_candidato, raiz->candidato);
  if (cmp < 0) {
    raiz->esquerda = insere_arvore_binaria_AVL(raiz->esquerda, novo_candidato);
  } else if (cmp > 0) {
    raiz->direita = insere_arvore_binaria_AVL(raiz->direita, novo_candidato);
  } else {
    return raiz; // Valor duplicado, não inserir
  }

  // Recalcular fator
  raiz->altura = 1 + (altura(raiz->esquerda) > altura(raiz->direita)
                          ? altura(raiz->esquerda)
                          : altura(raiz->direita));

  raiz->fator = altura(raiz->esquerda) - altura(raiz->direita);
  int balanco = raiz->fator;

  // Caso Esquerda-Esquerda
  if (balanco > 1 &&
      comparar_ordenacao_arvore(*novo_candidato, raiz->esquerda->candidato) < 0)
    return rotacionar_direita(raiz);

  // Caso Direita-Direita
  if (balanco < -1 &&
      comparar_ordenacao_arvore(*novo_candidato, raiz->direita->candidato) > 0)
    return rotacionar_esquerda(raiz);

  // Caso Esquerda-Direita
  if (balanco > 1 && comparar_ordenacao_arvore(*novo_candidato,
                                               raiz->esquerda->candidato) > 0) {
    raiz->esquerda = rotacionar_esquerda(raiz->esquerda);
    return rotacionar_direita(raiz);
  }

  // Caso Direita-Esquerda
  if (balanco < -1 && comparar_ordenacao_arvore(*novo_candidato,
                                                raiz->direita->candidato) < 0) {
    raiz->direita = rotacionar_direita(raiz->direita);
    return rotacionar_esquerda(raiz);
  }

  return raiz;
}

NoCandidatoAVL *rotacionar_direita(NoCandidatoAVL *raiz) {
  NoCandidatoAVL *p1 = raiz->esquerda;
  NoCandidatoAVL *p2 = p1->direita;

  p1->direita = raiz;
  raiz->esquerda = p2;

  raiz->altura = 1 + (altura(raiz->esquerda) > altura(raiz->direita)
                          ? altura(raiz->esquerda)
                          : altura(raiz->direita));
  p1->altura =
      1 + (altura(p1->esquerda) > altura(p1->direita) ? altura(p1->esquerda)
                                                      : altura(p1->direita));

  // Retorna "nova" raiz
  return p1;
}

NoCandidatoAVL *rotacionar_esquerda(NoCandidatoAVL *raiz) {
  NoCandidatoAVL *p1 = raiz->direita;
  NoCandidatoAVL *p2 = p1->esquerda;

  p1->esquerda = raiz;
  raiz->direita = p2;

  raiz->altura = 1 + (altura(raiz->esquerda) > altura(raiz->direita)
                          ? altura(raiz->esquerda)
                          : altura(raiz->direita));
  p1->altura =
      1 + (altura(p1->esquerda) > altura(p1->direita) ? altura(p1->esquerda)
                                                      : altura(p1->direita));

  // Retorna "nova" raiz
  return p1;
}

void ler_arquivo_arvore_binaria_AVL(ArvoreAVL *raiz, const char *caminho) {
  NoCandidatoAVL *arvore_avl = NULL;
  FILE *arquivo = fopen(caminho, "r");
  if (arquivo == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo.\n");
    return;
  }

  char linha[500];
  struct candidato novo_candidato;

  // Lê e descarta a primeira linha (cabeçalho)
  fgets(linha, sizeof(linha), arquivo);

  while (fgets(linha, sizeof(linha), arquivo)) {
    linha[strcspn(linha, "\n")] = 0;
    char *token;
    int i = 0;
    // Separa linha por ';' e preenche os dados do registro de candidato
    token = strtok(linha, ";");
    while (token != NULL && i < 10) {
      switch (i) {
      case 0:
        strcpy(novo_candidato.estado, token);
        break;
      case 1:
        strcpy(novo_candidato.cidade, token);
        break;
      case 2:
        novo_candidato.nr_candidato = atoi(token);
        break;
      case 3:
        strcpy(novo_candidato.cargo, token);
        break;
      case 4:
        strcpy(novo_candidato.nm_candidato, token);
        break;
      case 5:
        strcpy(novo_candidato.nm_urna_candidato, token);
        break;
      case 6:
        strcpy(novo_candidato.sg_partido, token);
        break;
      case 7:
        strcpy(novo_candidato.genero, token);
        break;
      case 8:
        strcpy(novo_candidato.grau_instrucao, token);
        break;
      case 9:
        strcpy(novo_candidato.cor_raca, token);
        break;
      }
      token = strtok(NULL, ";");
      i++;
    }

    arvore_avl = insere_arvore_binaria_AVL(arvore_avl, &novo_candidato);
  }

  fclose(arquivo);
  raiz->raiz = arvore_avl;
  return;
}

void imprimir_avl(NoCandidatoAVL *raiz) {
  if (raiz != NULL) {
    imprimir_avl(raiz->esquerda);

    printf("Estado: %s, Cidade: %s, Nr: %d, Nome: %s\n", raiz->candidato.estado,
           raiz->candidato.cidade, raiz->candidato.nr_candidato,
           raiz->candidato.nm_candidato);
    imprimir_avl(raiz->direita);
  }
}

int altura(NoCandidatoAVL *N) {
  if (N == NULL)
    return 0;
  return N->altura;
}

void liberar_arvore_avl(NoCandidatoAVL *raiz) {
  if (raiz == NULL) {
    return;
  }

  // Libera a subárvore esquerda
  liberar_arvore_avl(raiz->esquerda);

  // Libera a subárvore direita
  liberar_arvore_avl(raiz->direita);

  // Libera o nó atual
  free(raiz);
}