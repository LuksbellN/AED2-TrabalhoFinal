#include <string.h>
#include <stdbool.h>
#include "ordenacao.h"


void shellsort(struct candidato *vetor, int n) {
  double t;

  int N = 1, i, j;

  do {
    N = N * 3 + 1;
  } while (N < n);

  do {
    N /= 3;
    struct candidato aux;
    for (i = N; i < n - N; i++) {
      aux = vetor[i];
      for (j = i - N; j >= 0 && compararOrdenacao(vetor[j], aux); j -= N) {
        vetor[j + N] = vetor[j];
      }
      if (j != i - N) {
        vetor[j + N] = aux;
      }
    }
  } while (N != 1);
}


bool compararOrdenacao(struct candidato cand1, struct candidato cand2){
    // 1° opção de ordenação
    if(strcmp(cand1.estado, cand2.estado) != 0){
        return strcmp(cand1.estado, cand2.estado) > 0;
    }

    // 2° opção de ordenação
    if(strcmp(cand1.cidade, cand2.cidade) != 0){
        return strcmp(cand1.cidade, cand2.cidade) > 0;
    }

    // 3° e última opção de ordenação
    return cand1.nr_candidato > cand2.nr_candidato;
}