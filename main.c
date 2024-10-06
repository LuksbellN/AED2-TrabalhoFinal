#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"
#include "ordenacao.h"
#include "arvore_binaria.h"

#include <stdio.h>

#define TAM_INICIAL 1000

int main(){
    char* caminho = "./eleicoes2024-small.CSV";

    #pragma region Árvore_binária
    NoCandidato *arvore = ler_arquivo_arvore_binaria(caminho);
    printf("passou leitura");
    imprimir(arvore);

    #pragma endregion Árvore_binária

    printf("\nVetor:\n\n");

    #pragma region Vetor
    struct candidato *vetor = malloc(TAM_INICIAL * sizeof(struct candidato));
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
    exibir_dados(vetor, indice);
    free(vetor);
    #pragma endregion Vetor

    return 0;
}
