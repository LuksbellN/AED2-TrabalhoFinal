#ifndef PROCESSA_DADOS_H
#define PROCESSA_DADOS_H

int processar_dados(int estrutura_dados, struct candidato **vetor, NoCandidato **arvore, NoCandidatoAVL **arvore_avl, const char *caminho);

double busca_estado(struct candidato* vetor, int indice, NoCandidato* arvore, NoCandidatoAVL* arvore_avl, int estrutura_dados);

double busca_estado_cidade(struct candidato* vetor, int indice, NoCandidato* arvore, NoCandidatoAVL* arvore_avl, int estrutura_dados);

double busca_estado_cidade_numero(struct candidato* vetor, int indice, NoCandidato* arvore, NoCandidatoAVL* arvore_avl, int estrutura_dados);

#endif