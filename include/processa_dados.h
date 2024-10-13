#ifndef PROCESSA_DADOS_H
#define PROCESSA_DADOS_H

#define TAM_INICIAL 1000
#define OPCAO_VETOR 1
#define OPCAO_ARVORE_BINARIA 2
#define OPCAO_ARVORE_AVL 3

typedef struct candidato {
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
} candidato;

typedef struct NoCandidato {
  struct candidato candidato;
  struct NoCandidato *esquerda, *direita;
} NoCandidato;

typedef struct {
  NoCandidato *raiz;
} ArvoreBinaria;

typedef struct NoCandidatoAVL {
  struct candidato candidato;
  int fator;
  int altura;
  struct NoCandidatoAVL *esquerda, *direita;
} NoCandidatoAVL;

typedef struct {
  NoCandidatoAVL *raiz;
} ArvoreAVL;

int processar_dados(int estrutura_dados, struct candidato **vetor,
                    ArvoreBinaria *arvore, ArvoreAVL *arvore_avl,
                    const char *caminho);

int comparar_ordenacao_arvore(struct candidato cand1, struct candidato cand2);

void print_tempo(double t);

#endif
