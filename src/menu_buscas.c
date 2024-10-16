#include "../include/menu_buscas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void busca_estado(struct candidato *vetor, int indice, ArvoreBinaria *arvore,
                  ArvoreAVL *arvore_avl, int estrutura_dados) {
  ResultadoDinamico resultado;
  char *estado = malloc(3 * sizeof(char));
  if (!estado) // Verifica se a alocação foi bem-sucedida
  {
    printf("Erro ao alocar memória.\n");
    exit(EXIT_FAILURE);
  }

  printf("\nDigite a sigla do Estado desejado:\n");
  if (fgets(estado, 3, stdin) != NULL) {
    // Remove o caractere de nova linha, se presente
    estado[strcspn(estado, "\n")] = 0;
  }

  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF)
    ; // Limpa o buffer restante

  if (estrutura_dados == OPCAO_VETOR) {
    resultado = busca_estado_vetor(vetor, indice, estado);
  } else if (estrutura_dados == OPCAO_ARVORE_BINARIA) {
    resultado = busca_estado_arvore_binaria(arvore->raiz, estado);
  } else if (estrutura_dados == OPCAO_ARVORE_AVL) {
    resultado = busca_estado_arvore_AVL(arvore_avl->raiz, estado);
  }

  if (resultado.tamanho > 0) {
    carregar_menu(&resultado);
  }

  free(estado);
}

void busca_estado_cidade(struct candidato *vetor, int indice,
                         ArvoreBinaria *arvore, ArvoreAVL *arvore_avl,
                         int estrutura_dados) {
  ResultadoDinamico resultado;
  char *estado = malloc(3 * sizeof(char));
  char *cidade = malloc(50 * sizeof(char));
  if (!estado || !cidade) // Verifica se a alocação foi bem-sucedida
  {
    printf("Erro ao alocar memória.\n");
    exit(EXIT_FAILURE);
  }

  printf("\nDigite a sigla do Estado desejado:\n");
  if (fgets(estado, 3, stdin) != NULL) {
    // Remove o caractere de nova linha, se presente
    estado[strcspn(estado, "\n")] = 0;
  }

  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF)
    ; // Limpa o buffer restante

  printf("\nDigite a cidade desejada:\n");
  if (fgets(cidade, 50, stdin) != NULL) {
    // Remove o caractere de nova linha, se presente
    cidade[strcspn(cidade, "\n")] = 0;
  }

  if (estrutura_dados == OPCAO_VETOR) {
    resultado = busca_estado_cidade_vetor(vetor, indice, estado, cidade);
  } else if (estrutura_dados == OPCAO_ARVORE_BINARIA) {
    resultado =
        busca_estado_cidade_arvore_binaria(arvore->raiz, estado, cidade);
  } else if (estrutura_dados == OPCAO_ARVORE_AVL) {
    resultado =
        busca_estado_cidade_arvore_AVL(arvore_avl->raiz, estado, cidade);
  }

  if (resultado.tamanho > 0) {
    carregar_menu(&resultado);
  }
  free(estado);
  free(cidade);
}

void busca_estado_cidade_numero(struct candidato *vetor, int indice,
                                ArvoreBinaria *arvore, ArvoreAVL *arvore_avl,
                                int estrutura_dados) {
  char *estado = malloc(3 * sizeof(char));
  char *cidade = malloc(50 * sizeof(char));
  if (!estado || !cidade) // Verifica se a alocação foi bem-sucedida
  {
    printf("Erro ao alocar memória.\n");
    exit(EXIT_FAILURE);
  }

  int nr_candidato;

  printf("\nDigite a sigla do Estado desejado:\n");
  if (fgets(estado, 3, stdin) != NULL) {
    // Remove o caractere de nova linha, se presente
    estado[strcspn(estado, "\n")] = 0;
  }

  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF)
    ; // Limpa o buffer restante

  printf("\nDigite a cidade desejada:\n");
  if (fgets(cidade, 50, stdin) != NULL) {
    // Remove o caractere de nova linha, se presente
    cidade[strcspn(cidade, "\n")] = 0;
  }

  printf("\nDigite o número do candidato:\n");
  if (scanf("%d", &nr_candidato) != 1) {
    printf("Erro ao ler o número do candidato.\n");
  }

  if (estrutura_dados == OPCAO_VETOR) {
    busca_estado_cidade_numero_vetor(vetor, indice, estado, cidade,
                                     nr_candidato);
  } else if (estrutura_dados == OPCAO_ARVORE_BINARIA) {
    busca_estado_cidade_numero_arvore_binaria(arvore->raiz, estado, cidade,
                                              nr_candidato);
  } else if (estrutura_dados == OPCAO_ARVORE_AVL) {
    busca_estado_cidade_numero_arvore_AVL(arvore_avl->raiz, estado, cidade,
                                          nr_candidato);
  }

  free(estado);
  free(cidade);
}
