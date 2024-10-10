#include "../include/buscas_vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int compararOrdenacao(struct candidato cand1, struct candidato cand2) {
  // Comparar o estado
  int cmp = strcmp(cand1.estado, cand2.estado);
  if (cmp != 0)
    return cmp;

  // Comparar a cidade
  cmp = strcmp(cand1.cidade, cand2.cidade);
  if (cmp != 0)
    return cmp;

  // Comparar o número do candidato
  return cand1.nr_candidato - cand2.nr_candidato;
}

struct candidato *busca_binaria(candidato *vetor, int inicio, int fim,
                                candidato *chave) {
  if (inicio > fim) {
    return NULL; // não achou
  }
  int meio = (inicio + fim) / 2;
  int cmp = compararOrdenacao(vetor[meio], *chave);

  if (cmp == 0) {
    return &vetor[meio]; // achou
  } else if (cmp < 0) {
    return busca_binaria(vetor, meio + 1, fim, chave);
  } else {
    return busca_binaria(vetor, inicio, meio - 1, chave);
  }
}

ResultadoDinamico busca_estado_vetor(candidato *vetor, int indice,
                                     char *estado) {
  int tamanhoResultado = 0;
  int capacidadeResultado = 10;
  struct candidato *vetorResultado =
      malloc(capacidadeResultado * sizeof(struct candidato));

  time_t inicio, fim;
  double t;
  inicio = clock();

  // TODO
  // Completar busca por estado

  fim = clock();
  t = (double)(fim - inicio) / CLOCKS_PER_SEC;

  print_tempo(t);

  ResultadoDinamico resultado = {.capacidade = capacidadeResultado,
                                 .tamanho = tamanhoResultado,
                                 .vetor = vetorResultado};
  return resultado;
}

ResultadoDinamico busca_estado_cidade_vetor(candidato *vetor, int indice,
                                            char *estado, char *cidade) {
  int tamanhoResultado = 0;
  int capacidadeResultado = 10;
  struct candidato *vetorResultado =
      malloc(capacidadeResultado * sizeof(struct candidato));

  time_t inicio, fim;
  double t;
  inicio = clock();

  // TODO
  // Completar busca por estado e cidade

  fim = clock();
  t = (double)(fim - inicio) / CLOCKS_PER_SEC;

  print_tempo(t);

  ResultadoDinamico resultado = {.capacidade = capacidadeResultado,
                                 .tamanho = tamanhoResultado,
                                 .vetor = vetorResultado};
  return resultado;
}

void busca_estado_cidade_numero_vetor(struct candidato *vetor, int indice,
                                      char *estado, char *cidade,
                                      int nr_candidato) {
  clock_t inicio, fim;
  double t;

  struct candidato chave;
  strcpy(chave.estado, estado);
  strcpy(chave.cidade, cidade);
  chave.nr_candidato = nr_candidato;

  inicio = clock();
  struct candidato *resultado = busca_binaria(vetor, 0, indice - 1, &chave);
  fim = clock();

  if (resultado == NULL) {
    printf("Candidato não encontrado\n");
  } else {
    printf("\nResultado:\nEstado: %s, Cidade: %s, Nr: %d, Nome: %s\n\n",
           resultado->estado, resultado->cidade, resultado->nr_candidato,
           resultado->nm_candidato);
  }

  printf("--------------------------------------------------------------\n\n");

  t = (double)(fim - inicio) / CLOCKS_PER_SEC;
  print_tempo(t);
}
