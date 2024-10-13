#include "../include/ordenacao.h"
#include <stdbool.h>
#include <string.h>

bool compararOrdenacaoVetor(struct candidato cand1, struct candidato cand2) {
  // 1° opção de ordenação
  if (strcmp(cand1.estado, cand2.estado) != 0) {
    return strcmp(cand1.estado, cand2.estado) > 0;
  }
  // 2° opção de ordenação
  if (strcmp(cand1.cidade, cand2.cidade) != 0) {
    return strcmp(cand1.cidade, cand2.cidade) > 0;
  }
  // 3° e última opção de ordenação
  return cand1.nr_candidato > cand2.nr_candidato;
}

void shellsort(struct candidato *vetor, int n) {
  int N = 1, i, j;
  // Sequência de Knuth
  do {
    N = N * 3 + 1;
  } while (N < n);

  do {
    N /= 3;
    struct candidato aux;
    for (i = N; i < n; i++) {
      aux = vetor[i];
      for (j = i - N; j >= 0 && compararOrdenacaoVetor(vetor[j], aux) > 0;
           j -= N) {
        vetor[j + N] = vetor[j];
      }
      vetor[j + N] = aux;
    }
  } while (N > 1);
}
