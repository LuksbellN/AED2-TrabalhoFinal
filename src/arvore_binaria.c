#include "../include/arvore_binaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


NoCandidato *insere(NoCandidato *raiz, const struct candidato *novo_candidato) {
  // Verifica se o local correto foi encontrado
  if (raiz == NULL) {
    // Cria o novo nó com o candidato
    NoCandidato *novoNo = (NoCandidato *)malloc(sizeof(NoCandidato));
    if (novoNo == NULL) {
      fprintf(stderr, "Erro: Falha na alocação de memória\n");
      exit(1);
    }
    memcpy(&novoNo->candidato, novo_candidato, sizeof(struct candidato));
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
  }

  // Comparação por 1. Estado, 2. Cidade, 3. Nr Candidato
  int cmp = comparar_ordenacao_arvore(*novo_candidato, raiz->candidato);
  if (cmp < 0) {
    raiz->esquerda = insere(raiz->esquerda, novo_candidato);
  } else if (cmp > 0) {
    raiz->direita = insere(raiz->direita, novo_candidato);
  }

  return raiz;
}

void ler_arquivo_arvore_binaria(ArvoreBinaria *raiz, const char *caminho) {
  NoCandidato *arvore = NULL;
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

    arvore = insere(arvore, &novo_candidato);
  }

  fclose(arquivo);
  raiz->raiz = arvore;
  return;
}

void imprimir(NoCandidato *raiz) {
  if (raiz != NULL) {
    imprimir(raiz->esquerda);

    printf("Estado: %s, Cidade: %s, Nr: %d, Nome: %s\n", raiz->candidato.estado,
           raiz->candidato.cidade, raiz->candidato.nr_candidato,
           raiz->candidato.nm_candidato);
    imprimir(raiz->direita);
  }
}

NoCandidato *buscarMaior(NoCandidato *raiz) {
  if (raiz == NULL || raiz->direita == NULL)
    return raiz;

  return buscarMaior(raiz->direita);
}

NoCandidato *buscarMenor(NoCandidato *raiz) {
  if (raiz == NULL || raiz->esquerda == NULL)
    return raiz;

  return buscarMenor(raiz->esquerda);
}

int encontrarAltura(NoCandidato *raiz) {
  if (raiz == NULL) {
    return -1;
  }
  int alturaEsquerda = encontrarAltura(raiz->esquerda);
  int alturaDireita = encontrarAltura(raiz->direita);

  return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}

void liberar_arvore(NoCandidato *raiz) {
  if (raiz == NULL) {
    return;
  }

  // Libera a subárvore esquerda
  liberar_arvore(raiz->esquerda);

  // Libera a subárvore direita
  liberar_arvore(raiz->direita);

  // Libera o nó atual
  free(raiz);
}
