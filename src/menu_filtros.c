#include "../include/menu_filtros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void carregar_menu(ResultadoDinamico *resultado) {

  int condicional_de_funcionamento = 1;
  while (condicional_de_funcionamento != 4) {
    printf("\n--------------------------------------------------------------\n"
           "[1] Filtrar resultados por gênero\n"
           "[2] Filtrar resultados por partido\n"
           "[3] Filtrar resultados por cor / raça\n"
           "[4] Voltar\n"
           "--------------------------------------------------------------\n");
    scanf("%d", &condicional_de_funcionamento);
    getchar();

    switch (condicional_de_funcionamento) {
    case 1:
      filtrar_genero(resultado);
      break;
    case 2:
      filtrar_partido(resultado);
      break;
    case 3:
      filtrar_cor_raca(resultado);
      break;
    default:
      break;
    }
  }
}

void filtrar_genero(ResultadoDinamico *resultado) {
  char *genero = malloc(15 * sizeof(char));
  if (!genero) // Verifica se a alocação foi bem-sucedida
  {
    printf("Erro ao alocar memória.\n");
    exit(EXIT_FAILURE);
  }
  printf("\nDigite o gênero que deseja filtrar:\n");
  if (fgets(genero, 15, stdin) != NULL) {
    // Remove o caractere de nova linha, se presente
    genero[strcspn(genero, "\n")] = 0;
  }

  printf("\nResultados: \n");
  for (int i = 0; i < resultado->tamanho; i++) {
    if (strcmp(resultado->vetor[i].genero, genero) == 0) {
      printf("Estado: %s, Cidade: %s, Nr: %d, Nome: %s\n",
             resultado->vetor[i].estado, resultado->vetor[i].cidade,
             resultado->vetor[i].nr_candidato,
             resultado->vetor[i].nm_candidato);
    }
  }

  printf("\n\n");
}

void filtrar_partido(ResultadoDinamico *resultado) {
  char *partido = malloc(15 * sizeof(char));
  if (!partido) // Verifica se a alocação foi bem-sucedida
  {
    printf("Erro ao alocar memória.\n");
    exit(EXIT_FAILURE);
  }
  printf("\nDigite o partido que deseja filtrar:\n");
  if (fgets(partido, 15, stdin) != NULL) {
    // Remove o caractere de nova linha, se presente
    partido[strcspn(partido, "\n")] = 0;
  }

  printf("\nResultados: \n");
  for (int i = 0; i < resultado->tamanho; i++) {
    if (strcmp(resultado->vetor[i].sg_partido, partido) == 0) {
      printf("Estado: %s, Cidade: %s, Nr: %d, Nome: %s\n",
             resultado->vetor[i].estado, resultado->vetor[i].cidade,
             resultado->vetor[i].nr_candidato,
             resultado->vetor[i].nm_candidato);
    }
  }

  printf("\n\n");
}

void filtrar_cor_raca(ResultadoDinamico *resultado) {
  char *raca = malloc(15 * sizeof(char));
  if (!raca) // Verifica se a alocação foi bem-sucedida
  {
    printf("Erro ao alocar memória.\n");
    exit(EXIT_FAILURE);
  }
  printf("\nDigite o raça que deseja filtrar:\n");
  if (fgets(raca, 15, stdin) != NULL) {
    // Remove o caractere de nova linha, se presente
    raca[strcspn(raca, "\n")] = 0;
  }

  printf("\nResultados: \n");
  for (int i = 0; i < resultado->tamanho; i++) {
    if (strcmp(resultado->vetor[i].cor_raca, raca) == 0) {
      printf("Estado: %s, Cidade: %s, Nr: %d, Nome: %s\n",
             resultado->vetor[i].estado, resultado->vetor[i].cidade,
             resultado->vetor[i].nr_candidato,
             resultado->vetor[i].nm_candidato);
    }
  }
  printf("\n\n");
  printf("%s\n", raca);
}

void adicionar_ao_vetor_resultado(candidato **vetorResultado,
                                  int *tamanhoResultado,
                                  int *capacidadeResultado,
                                  candidato *novoCandidato) {
  if (*tamanhoResultado >= *capacidadeResultado) {
    *capacidadeResultado *= 2;
    *vetorResultado =
        realloc(*vetorResultado, *capacidadeResultado * sizeof(candidato));
    if (*vetorResultado == NULL) {
      fprintf(stderr, "Erro: Falha na realocação de memória\n");
      exit(1);
    }
  }

  (*vetorResultado)[*tamanhoResultado] = *novoCandidato;
  (*tamanhoResultado)++;
}