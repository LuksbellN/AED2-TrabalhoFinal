#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturasDados.h"


#define TAM_INCREMENTO 1000  // Quantidade de incremento quando o vetor precisar crescer


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

    char estado[3], cidade[50], cargo[15], nm_candidato[75], nm_urna_candidato[75], sg_partido[15], genero[15], grau_instrucao[45], cor_raca[20];
    int nr_candidato;

    while (fscanf(arquivo, "%2[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^\n]\n", estado, cidade, nr_candidato, cargo, nm_candidato, nm_urna_candidato, sg_partido, genero, grau_instrucao, cor_raca) != EOF){
        if (*indice >= *tamanho_atual) {
            realocar_vetor(vetor, tamanho_atual);
        }
        
        strcpy((*vetor)[*indice].estado, estado); 
        strcpy((*vetor)[*indice].cidade, cidade); 
        strcpy((*vetor)[*indice].nr_candidato, nr_candidato); 
        strcpy((*vetor)[*indice].cargo, cargo); 
        strcpy((*vetor)[*indice].nm_candidato, nm_candidato); 
        strcpy((*vetor)[*indice].nm_urna_candidato, nm_urna_candidato); 
        strcpy((*vetor)[*indice].sg_partido, sg_partido); 
        strcpy((*vetor)[*indice].genero, genero); 
        strcpy((*vetor)[*indice].grau_instrucao, grau_instrucao); 
        strcpy((*vetor)[*indice].cor_raca, cor_raca); 

        (*indice)++;
    }


    fclose(arquivo);
    return 0;
}


void exibir_dados(struct candidato *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("Estado: %s, Cidade: %s, Nr Candidato: %i, Nr Urna Candidato: %i, Sigla Partido: %s, Genero: %s, Grau Instrução: %s, Raça: %s\n",
               vetor[i].estado,
               vetor[i].cidade,
               vetor[i].nr_candidato,
               vetor[i].nm_urna_candidato,
               vetor[i].sg_partido,
               vetor[i].genero,
               vetor[i].grau_instrucao,
               vetor[i].cor_raca
               );
    }
}