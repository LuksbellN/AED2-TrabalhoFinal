#ifndef ESTRUTURAS_DADOS_H
#define ESTRUTURAS_DADOS_H

struct candidato {
    char estado[3];
    char cidade[50];
    int nr_candidato;
    char cargo[15];
    char nm_candidato[75];
    char nm_urna_candidato[75]; 
    char sg_partido[15];
    char genero[15];
    char grau_instrucao[45];
    char cor_raca[20];
};

int ler_arquivo_vetor(const char *caminho, struct candidato **vetor, int *tamanho_atual, int *indice);

void realocar_vetor(struct candidato **vetor, int *tamanho_atual);

void exibir_dados(struct candidato *vetor, int n);

#endif
