#include "./include/arvore_avl.h"
#include "./include/arvore_binaria.h"
#include "./include/menu_buscas.h"
#include "./include/processa_dados.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_INICIAL 1000
#define OPCAO_VETOR 1
#define OPCAO_ARVORE_BINARIA 2
#define OPCAO_ARVORE_AVL 3

int main() {
  char *caminho = "./eleicoes2024-small.CSV";
  struct candidato *vetor = NULL;
  ArvoreBinaria *raizBinaria = (ArvoreBinaria *)malloc(sizeof(ArvoreBinaria));
  ArvoreAVL *raizAVL = (ArvoreAVL *)malloc(sizeof(ArvoreAVL));
  srand(time(NULL));

  int estrutura_dados;
  printf("Escolha qual estrutura de dados carregar: ");
  printf("\n[1] Vetor\n[2] Árvore binária\n[3] Árvore AVL\n");
  scanf("%d", &estrutura_dados);
  getchar();

  int indice =
      processar_dados(estrutura_dados, &vetor, raizBinaria, raizAVL, caminho);

  if (raizBinaria == NULL) {
    printf("ueee");
  }

  int condicional_de_funcionamento = 1;
  while (condicional_de_funcionamento != 4) {
    printf("\n--------------------------------------------------------------\n"
           "[1] Buscar os dados dos candidatos de um estado\n"
           "[2] Buscar os dados dos candidatos de um estado e uma cidade\n"
           "[3] Buscar os dados dos candidatos de um estado, uma cidade e um "
           "número de candidato\n"
           "[4] Sair\n"
           "--------------------------------------------------------------\n");
    scanf("%d", &condicional_de_funcionamento);
    getchar();

    switch (condicional_de_funcionamento) {
    case 1:
      busca_estado(vetor, indice, raizBinaria, raizAVL, estrutura_dados);
      break;
    case 2:
      busca_estado_cidade(vetor, indice, raizBinaria, raizAVL, estrutura_dados);
      break;
    case 3:
      busca_estado_cidade_numero(vetor, indice, raizBinaria, raizAVL,
                                 estrutura_dados);
      break;
    default:
      break;
    }
  }

  // Liberar Estruturas de dados
  liberar_arvore(raizBinaria->raiz);
  liberar_arvore_avl(raizAVL->raiz);
  free(vetor);
  return 0;
}