#include <stdio.h>
#include <stdlib.h>

// Definindo o nó da lista
typedef struct no {
    int conteudo;
    struct no* proximo;
} no;

// Definindo a estrutura da lista
typedef struct {
    no* comeco;
    int tamanho;
} lista;

// Assinaturas das funções
lista criarLista();
void verificarLista(lista l);
int obterTamanho(lista l);
int obterValor(lista l, int posicao);
void modificarElemento(lista* l, int posicao, int novo);
void inserirElemento(lista* l, int posicao, int conteudo);
void retirarElemento(lista* l, int posicao);
void imprimirLista(lista l);
