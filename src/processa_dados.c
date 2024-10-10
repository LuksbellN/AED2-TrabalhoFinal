#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../include/processa_dados.h"

#include "../include/arvore_binaria.h"
#include "../include/arvore_avl.h"
#include "../include/vetor.h"
#include "../include/ordenacao.h"



void print_tempo(double t){
    printf("\nTempo de Execucao: %lf segundos\n\n", t);
    printf("--------------------------------------------------------------\n\n");
}


int processar_dados(int estrutura_dados, struct candidato **vetor, ArvoreBinaria *arvore, ArvoreAVL *arvore_avl, const char *caminho)
{
    time_t inicio, fim;
    double t;

    switch (estrutura_dados)
    {
    case OPCAO_VETOR:
    {
        inicio = clock();
        *vetor = malloc(TAM_INICIAL * sizeof(struct candidato));
        if (vetor == NULL)
        {
            fprintf(stderr, "Erro: Falha na alocação de memória para o vetor.\n");
            return 1;
        }

        int tamanho_atual = TAM_INICIAL;
        int indice = 0;

        if (ler_arquivo_vetor(caminho, vetor, &tamanho_atual, &indice))
        {
            free(vetor);
            fprintf(stderr, "Erro: Falha na leitura do arquivo para o vetor.\n");
            return 1;
        }

        shellsort(*vetor, indice);
        fim = clock();
        t = (double)(fim - inicio) / CLOCKS_PER_SEC;
        print_tempo(t);

        return indice;

        break;
    }
    case OPCAO_ARVORE_BINARIA:
    {
        inicio = clock();
        ler_arquivo_arvore_binaria(arvore, caminho);
        if (arvore->raiz == NULL)
        {
            fprintf(stderr, "Erro: Falha na leitura do arquivo para a árvore binária.\n");
            return 1;
        }

        
        fim = clock();
        t = (double)(fim - inicio) / CLOCKS_PER_SEC;
        print_tempo(t);
        break;
    }
    case OPCAO_ARVORE_AVL:
    {
        inicio = clock();
        ler_arquivo_arvore_binaria_AVL(arvore_avl, caminho);
        if (arvore_avl->raiz == NULL)
        {
            fprintf(stderr, "Erro: Falha na leitura do arquivo para a árvore AVL.\n");
            return 1;
        }
        fim = clock();
        t = (double)(fim - inicio) / CLOCKS_PER_SEC;
        print_tempo(t);
        break;
    }
    default:
        fprintf(stderr, "Erro: Opção de estrutura de dados inválida.\n");
    }



    return 0; // Sucesso
}


int comparar_ordenacao_arvore(struct candidato cand1, struct candidato cand2)
{
  // 1° opção de ordenação
  if (strcmp(cand1.estado, cand2.estado) != 0)
  {
    return strcmp(cand1.estado, cand2.estado);
  }

  // 2° opção de ordenação
  if (strcmp(cand1.cidade, cand2.cidade) != 0)
  {
    return strcmp(cand1.cidade, cand2.cidade);
  }

  // 3° e última opção de ordenação
  return cand1.nr_candidato - cand2.nr_candidato;
}