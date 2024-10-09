#include <stdio.h>
#include <stdlib.h>
#include "../estruturas_dados/vetor.h"
#include "../estruturas_dados/arvore_binaria.h"
#include "../auxiliares/ordenacao.h"
#include "../buscas/buscas_arvore_avl.h"
#include "../buscas/buscas_arvore_binaria.h"
#include "../buscas/buscas_vetor.h"
#include <time.h>
#include <string.h>

#include <stdio.h>
#include "../estruturas_dados/arvore_avl.h"

#define TAM_INICIAL 1000
#define OPCAO_VETOR 1
#define OPCAO_ARVORE_BINARIA 2
#define OPCAO_ARVORE_AVL 3

void print_tempo(double t){
    printf("##################################################\n\n");
    printf("Dados carregados, tempo gasto: %2f segundos\n\n", t);
    printf("##################################################\n\n");
}


int processar_dados(int estrutura_dados, struct candidato **vetor, NoCandidato **arvore, NoCandidatoAVL **arvore_avl, const char *caminho)
{
    time_t inicio, fim;
    double t;
    inicio = clock();

    switch (estrutura_dados)
    {
    case OPCAO_VETOR:
    {
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
        NoCandidato *arvore = ler_arquivo_arvore_binaria(caminho);
        if (arvore == NULL)
        {
            fprintf(stderr, "Erro: Falha na leitura do arquivo para a árvore binária.\n");
            return 1;
        }
        //imprimir(arvore);
        printf("Altura da árvore binária: %d\n", encontrarAltura(arvore));

        
        fim = clock();
        t = (double)(fim - inicio) / CLOCKS_PER_SEC;
        print_tempo(t);
        break;
    }
    case OPCAO_ARVORE_AVL:
    {
        NoCandidatoAVL *arvore_avl = ler_arquivo_arvore_binaria_AVL(caminho);
        if (arvore_avl == NULL)
        {
            fprintf(stderr, "Erro: Falha na leitura do arquivo para a árvore AVL.\n");
            return 1;
        }
        imprimir_avl(arvore_avl);
        printf("Altura da árvore AVL: %d\n", altura(arvore_avl));
        
        fim = clock();
        t = (double)(fim - inicio) / CLOCKS_PER_SEC;
        print_tempo(t);
        break;
    }
    default:
        fprintf(stderr, "Erro: Opção de estrutura de dados inválida.\n");
        
        fim = clock();
        return 1;
    }



    return 0; // Sucesso
}

double busca_estado(struct candidato *vetor, int indice, NoCandidato *arvore, NoCandidatoAVL *arvore_avl, int estrutura_dados)
{
    time_t inicio, fim;
    double t;
    char *estado = malloc(3 * sizeof(char));

    printf("\nDigite a sigla do Estado desejado:\t");
    if (fgets(estado, 2, stdin) != NULL)
    {
        // Remove o caractere de nova linha, se presente
        estado[strcspn(estado, "\n")] = 0;
    }

    inicio = clock();

    if (estrutura_dados == OPCAO_VETOR)
    {
        busca_estado_vetor(vetor, indice, estado);
    }
    else if (estrutura_dados == OPCAO_ARVORE_BINARIA)
    {
        busca_estado_arvore_binaria(arvore, estado);
    }
    else if (estrutura_dados == OPCAO_ARVORE_AVL)
    {
        busca_estado_arvore_AVL(arvore_avl, estado);
    }

    fim = clock();
    t = (double)(fim - inicio) / CLOCKS_PER_SEC;

    return t;
}

double busca_estado_cidade(struct candidato *vetor, int indice, NoCandidato *arvore, NoCandidatoAVL *arvore_avl, int estrutura_dados)
{
    time_t inicio, fim;
    double t;
    char *estado = malloc(3 * sizeof(char));
    char *cidade = malloc(50 * sizeof(char));

    printf("\nDigite a sigla do Estado desejado:\t");
    if (fgets(estado, 2, stdin) != NULL)
    {
        // Remove o caractere de nova linha, se presente
        estado[strcspn(estado, "\n")] = 0;
    }

    printf("\nDigite a cidade desejada:\t");
    if (fgets(cidade, 50, stdin) != NULL)
    {
        // Remove o caractere de nova linha, se presente
        cidade[strcspn(cidade, "\n")] = 0;
    }

    inicio = clock();

    if (estrutura_dados == OPCAO_VETOR)
    {
        busca_estado_cidade_vetor(vetor, indice, estado, cidade);
    }
    else if (estrutura_dados == OPCAO_ARVORE_BINARIA)
    {
        busca_estado_cidade_arvore_binaria(arvore, estado, cidade);
    }
    else if (estrutura_dados == OPCAO_ARVORE_AVL)
    {
        busca_estado_cidade_arvore_AVL(arvore_avl, estado, cidade);
    }

    fim = clock();
    t = (double)(fim - inicio) / CLOCKS_PER_SEC;

    return t;
}

double busca_estado_cidade_numero(struct candidato *vetor, int indice, NoCandidato *arvore, NoCandidatoAVL *arvore_avl, int estrutura_dados)
{
    double t;
    char *estado = malloc(3 * sizeof(char));
    char *cidade = malloc(50 * sizeof(char));
    if (!estado || !cidade) // Verifica se a alocação foi bem-sucedida
    {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    int nr_candidato;

    printf("\nDigite a sigla do Estado desejado:\n");
    if (fgets(estado, 3, stdin) != NULL)
    {
        // Remove o caractere de nova linha, se presente
        estado[strcspn(estado, "\n")] = 0;
    }

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ; // Limpa o buffer restante

    printf("\nDigite a cidade desejada:\n");
    if (fgets(cidade, 50, stdin) != NULL)
    {
        // Remove o caractere de nova linha, se presente
        cidade[strcspn(cidade, "\n")] = 0;
    }

    printf("\nDigite o número do candidato:\n");
    if (scanf("%d", &nr_candidato) != 1)
    {
        printf("Erro ao ler o número do candidato.\n");
    }

    // Limpa o buffer
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    

    if (estrutura_dados == OPCAO_VETOR)
    {
        t = busca_estado_cidade_numero_vetor(vetor, indice, estado, cidade, nr_candidato);
    }
    else if (estrutura_dados == OPCAO_ARVORE_BINARIA)
    {
        busca_estado_cidade_numero_arvore_binaria(arvore, estado, cidade, nr_candidato);
    }
    else if (estrutura_dados == OPCAO_ARVORE_AVL)
    {
        busca_estado_cidade_numero_arvore_AVL(arvore_avl, estado, cidade, nr_candidato);
    }


    free(estado);
    free(cidade);

    return t;
}