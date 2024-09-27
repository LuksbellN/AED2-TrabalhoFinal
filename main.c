#include <stdio.h>
#include <stdlib.h>
#include "estruturasDados.h"
#include "ordenacao.h"

#include <stdio.h>

#define TAM_INICIAL 1000

int main(){
    char* caminho = "./eleicoes2024.CSV";

    struct cep *vetor = malloc(TAM_INICIAL * sizeof(struct candidato));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    int tamanho_atual = TAM_INICIAL;
    int indice = 0;

    if (ler_arquivo_vetor(caminho, &vetor, &tamanho_atual, &indice)) {
        free(vetor);
        return 1;
    }

    // Ordenar os dados utilizando Shellsort
    shellsort(vetor, indice);



    free(vetor);

    return 0;
}
