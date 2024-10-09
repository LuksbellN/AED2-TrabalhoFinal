#include <stdio.h>
#include <stdlib.h>
#include "./estruturas_dados/vetor.h"
#include "./estruturas_dados/arvore_binaria.h"
#include "./estruturas_dados/arvore_avl.h"
#include "./auxiliares/processa_dados.h"

#include <stdio.h>

#define TAM_INICIAL 1000
#define OPCAO_VETOR 1
#define OPCAO_ARVORE_BINARIA 2
#define OPCAO_ARVORE_AVL 3

int main()
{
    char *caminho = "./eleicoes2024.CSV";
    struct candidato *vetor = NULL;
    NoCandidato *arvore = NULL;
    NoCandidatoAVL *arvore_avl = NULL;
    double tempo;

    int estrutura_dados;
    printf("Escolha qual estrutura de dados carregar: ");
    printf("\n[1] Vetor\n[2] Árvore binária\n[3] Árvore AVL\n");
    scanf("%d", &estrutura_dados);
    getchar();

    int indice = processar_dados(OPCAO_VETOR, &vetor, &arvore, &arvore_avl, caminho);

    int condicional_de_funcionamento = 1;
    while (condicional_de_funcionamento != 4)
    {
        printf("[1] Buscar os dados dos candidatos de um estado\n"
        "[2] Buscar os dados dos candidatos de um estado e uma cidade\n"
        "[3] Buscar os dados dos candidatos de um estado, uma cidade e um número de candidato\n"
        "[4] Sair\n");
        scanf("%d",&condicional_de_funcionamento);
        getchar();

        switch (condicional_de_funcionamento) {
        case 1:
            tempo = busca_estado(vetor, indice, arvore, arvore_avl, estrutura_dados);
            printf("Tempo de processamento: %f\n", tempo);
            break;
        case 2:
            tempo = busca_estado_cidade(vetor, indice, arvore, arvore_avl, estrutura_dados);
            printf("Tempo de processamento: %f\n", tempo);
            break;
        case 3:
            tempo = busca_estado_cidade_numero(vetor, indice, arvore, arvore_avl, estrutura_dados);
            printf("Tempo de processamento: %f\n", tempo);
            break;
        default:
            break;
        }
    }

    // Liberar Estruturas de dados
    liberar_arvore(arvore);
    liberar_arvore_avl(arvore_avl);
    free(vetor);
    return 0;
}