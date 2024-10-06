#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetor.h"


#define TAM_INCREMENTO 1000  // Quantidade de incremento quando o vetor precisar crescer
#define MAX_LINE_LENGTH 500  // Quantidade máxima de caracteres por linha do arquivo


void realocar_vetor(struct candidato **vetor, int *tamanho_atual) {
    *tamanho_atual += TAM_INCREMENTO;
    *vetor = realloc(*vetor, (*tamanho_atual) * sizeof(struct candidato));
    if (*vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
}

int ler_arquivo_vetor(const char *caminho, struct candidato **vetor, int *tamanho_atual, int *indice) {
    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char linha[MAX_LINE_LENGTH];
    
    // Lê e descarta a primeira linha (cabeçalho)
    if (fgets(linha, sizeof(linha), arquivo) == NULL) {
        fclose(arquivo);
        return 1; // Arquivo vazio ou erro na leitura
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (*indice >= *tamanho_atual) {
            realocar_vetor(vetor, tamanho_atual);
        }
        
        char *token;
        int i = 0;
        
        // Separa linha por ';' e preenche os dados do registro de candidato
        token = strtok(linha, ";");
        while (token != NULL && i < 10) {
            switch(i) {
                case 0: strcpy((*vetor)[*indice].estado, token); break;
                case 1: strcpy((*vetor)[*indice].cidade, token); break;
                case 2: (*vetor)[*indice].nr_candidato = atoi(token); break;
                case 3: strcpy((*vetor)[*indice].cargo, token); break;
                case 4: strcpy((*vetor)[*indice].nm_candidato, token); break;
                case 5: strcpy((*vetor)[*indice].nm_urna_candidato, token); break;
                case 6: strcpy((*vetor)[*indice].sg_partido, token); break;
                case 7: strcpy((*vetor)[*indice].genero, token); break;
                case 8: strcpy((*vetor)[*indice].grau_instrucao, token); break;
                case 9: strcpy((*vetor)[*indice].cor_raca, token); break;
            }
            token = strtok(NULL, ";");
            i++;
        }

        (*indice)++;
    }

    fclose(arquivo);
    return 0;
}

void exibir_dados(struct candidato *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("Estado: %s, Cidade: %s, Nr: %d, Nome: %s\n", 
           vetor[i].estado, vetor[i].cidade, vetor[i].nr_candidato, vetor[i].nm_candidato);
    }
}