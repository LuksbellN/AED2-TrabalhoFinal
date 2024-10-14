#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/buscas_arvore_avl.h"

void busca_recursiva_estado_AVL(NoCandidatoAVL *raiz, char *estado,
                            candidato **vetorResultado, int *tamanhoResultado,
                            int *capacidadeResultado) {
  if (raiz == NULL) {
    return;
  }

  // Verifica se o estado do nó atual é menor, igual ou maior
  int cmp = strcmp(estado, raiz->candidato.estado);

  if (cmp < 0) {
    // Procura na subárvore esquerda
    busca_recursiva_estado_AVL(raiz->esquerda, estado, vetorResultado,
                           tamanhoResultado, capacidadeResultado);
  } else if (cmp > 0) {
    // Procura na subárvore direita
    busca_recursiva_estado_AVL(raiz->direita, estado, vetorResultado,
                           tamanhoResultado, capacidadeResultado);
  } else {
    // Adiciona o candidato ao vetor se o estado for igual
    adicionar_ao_vetor_resultado(vetorResultado, tamanhoResultado,
                                 capacidadeResultado, &(raiz->candidato));

    // Continua procurando na esquerda e direita para encontrar todos os
    // candidatos com o mesmo estado
    busca_recursiva_estado_AVL(raiz->esquerda, estado, vetorResultado,
                           tamanhoResultado, capacidadeResultado);
    busca_recursiva_estado_AVL(raiz->direita, estado, vetorResultado,
                           tamanhoResultado, capacidadeResultado);
  }
}

void busca_recursiva_estado_cidade(NoCandidatoAVL *raiz, char *estado,
                                   char *cidade, candidato **vetorResultado,
                                   int *tamanhoResultado,
                                   int *capacidadeResultado) {
  if (raiz == NULL) {
    return;
  }

  // Verifica se o estado / cidade do nó atual é menor, igual ou maior
  int cmp = strcmp(estado, raiz->candidato.estado);
  if (cmp == 0) {
    cmp = strcmp(cidade, raiz->candidato.cidade);
  }

  if (cmp < 0) {
    // Procura na subárvore esquerda
    busca_recursiva_estado_cidade(raiz->esquerda, estado, cidade,
                                  vetorResultado, tamanhoResultado,
                                  capacidadeResultado);
  } else if (cmp > 0) {
    // Procura na subárvore direita
    busca_recursiva_estado_cidade(raiz->direita, estado, cidade, vetorResultado,
                                  tamanhoResultado, capacidadeResultado);
  } else {
    // Adiciona o candidato ao vetor se o estado for igual
    adicionar_ao_vetor_resultado(vetorResultado, tamanhoResultado,
                                 capacidadeResultado, &(raiz->candidato));

    // Continua procurando na esquerda e direita para encontrar todos os
    // candidatos com o mesmo estado
    busca_recursiva_estado_cidade(raiz->esquerda, estado, cidade,
                                  vetorResultado, tamanhoResultado,
                                  capacidadeResultado);
    busca_recursiva_estado_cidade(raiz->direita, estado, cidade, vetorResultado,
                                  tamanhoResultado, capacidadeResultado);
  }
}

ResultadoDinamico busca_estado_arvore_AVL(NoCandidatoAVL *raiz, char *estado) {
  int tamanhoResultado = 0;
  int capacidadeResultado = 10;
  struct candidato *vetorResultado =
      malloc(capacidadeResultado * sizeof(struct candidato));
  time_t inicio, fim;
  double t;
  inicio = clock();

  busca_recursiva_estado_AVL(raiz, estado, &vetorResultado, &tamanhoResultado,
                         &capacidadeResultado);
  if (tamanhoResultado == 0) {
    printf("Não foram encontrado resultados\n");
  } else {
    printf("\nResultados:\n\n");
    for (int i = 0; i < tamanhoResultado; i++) {

      printf("Estado: %s, Cidade: %s, Nr: %d, Nome: %s\n",
             vetorResultado[i].estado, vetorResultado[i].cidade,
             vetorResultado[i].nr_candidato, vetorResultado[i].nm_candidato);
    }
  }
  printf("--------------------------------------------------------------\n\n");

  fim = clock();
  t = (double)(fim - inicio) / CLOCKS_PER_SEC;

  print_tempo(t);

  ResultadoDinamico resultado = {.capacidade = capacidadeResultado,
                                 .tamanho = tamanhoResultado,
                                 .vetor = vetorResultado};
  return resultado;
}
ResultadoDinamico busca_estado_cidade_arvore_AVL(NoCandidatoAVL *raiz,
                                                 char *estado, char *cidade) {
  int tamanhoResultado = 0;
  int capacidadeResultado = 10;
  struct candidato *vetorResultado =
      malloc(capacidadeResultado * sizeof(struct candidato));

  time_t inicio, fim;
  double t;
  inicio = clock();

  busca_recursiva_estado_cidade(raiz, estado, cidade, &vetorResultado,
                                &tamanhoResultado, &capacidadeResultado);

  if (tamanhoResultado == 0) {
    printf("Não foram encontrado resultados\n");
  } else {
    printf("\nResultados:\n\n");
    for (int i = 0; i < tamanhoResultado; i++) {

      printf("Estado: %s, Cidade: %s, Nr: %d, Nome: %s\n",
             vetorResultado[i].estado, vetorResultado[i].cidade,
             vetorResultado[i].nr_candidato, vetorResultado[i].nm_candidato);
    }
  }

  printf("--------------------------------------------------------------\n\n");

  fim = clock();
  t = (double)(fim - inicio) / CLOCKS_PER_SEC;

  print_tempo(t);

  ResultadoDinamico resultado = {.capacidade = capacidadeResultado,
                                 .tamanho = tamanhoResultado,
                                 .vetor = vetorResultado};
  return resultado;
}

void busca_estado_cidade_numero_arvore_AVL(NoCandidatoAVL *raiz, char *estado,
                                           char *cidade, int nr_candidato) {
  time_t inicio, fim;
  double t;
  inicio = clock();

  struct candidato chave;
  strcpy(chave.estado, estado);
  strcpy(chave.cidade, cidade);
  chave.nr_candidato = nr_candidato;

  // TODO
  // Completar busca por estado, cidade e número

  fim = clock();
  t = (double)(fim - inicio) / CLOCKS_PER_SEC;

  print_tempo(t);
}