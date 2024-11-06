#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

// Função para criar uma nova lista
lista criarLista() {
    lista l;
    l.tamanho = 0;
    l.comeco = NULL;
    return l;
} 

// Verifica se a lista está vazia
void verificarLista(lista l) {
    if (l.comeco == NULL) {
        printf("Lista Vazia.\n");
    } else {
        printf("Lista com elementos.\n");
    }
}

// Retorna o tamanho da lista
int obterTamanho(lista l) {
    return l.tamanho;
}

// Obtém o valor de um elemento na posição especificada
int obterValor(lista l, int posicao) {
    if (posicao > l.tamanho || posicao < 1) {
        printf("Posicao invalida.\n");
        return -1;
    }

    no* aux = l.comeco;  // Corrigi para usar ponteiro de nó
    for (int i = 1; i < posicao; i++) {
        aux = aux->proximo;  // Percorre a lista até a posição correta
    }
    return aux->conteudo;
}

// Modifica o valor de um elemento na lista
void modificarElemento(lista* l, int posicao, int novo) {
    if (posicao > l->tamanho || posicao < 1) {
        printf("Posicao invalida.\n");
        return;
    }

    no* aux = l->comeco;
    for (int i = 1; i < posicao; i++) {
        aux = aux->proximo;
    }
    aux->conteudo = novo;
}

// Insere um elemento em uma posição específica na lista
void inserirElemento(lista* l, int posicao, int conteudo) {
    if (posicao < 1 || posicao > l->tamanho + 1) {
        printf("Posicao invalida.\n");
        return;
    }

    // Aloca um novo nó
    no* novoNo = (no*)malloc(sizeof(no));
    novoNo->conteudo = conteudo;
    novoNo->proximo = NULL;

    if (posicao == 1) {
        // Insere no início
        novoNo->proximo = l->comeco;
        l->comeco = novoNo;
    } else {
        // Insere no meio ou fim
        no* aux = l->comeco;
        for (int i = 1; i < posicao - 1; i++) {
            aux = aux->proximo;
        }
        novoNo->proximo = aux->proximo;
        aux->proximo = novoNo;
    }

    l->tamanho++;
}

// Remove um elemento de uma posição específica na lista
void retirarElemento(lista* l, int posicao) {
    if (posicao > l->tamanho || posicao < 1) {
        printf("Posicao invalida.\n");
        return;
    }

    no* aux = l->comeco;

    if (posicao == 1) {
        // Remove o primeiro nó
        l->comeco = aux->proximo;
        free(aux);
    } else {
        // Remove de uma posição no meio ou fim
        no* anterior = NULL;
        for (int i = 1; i < posicao; i++) {
            anterior = aux;
            aux = aux->proximo;
        }
        anterior->proximo = aux->proximo;
        free(aux);
    }

    l->tamanho--;
}

// Imprime os elementos da lista
void imprimirLista(lista l) {
    no* aux = l.comeco;
    printf("Lista:\n");
    for (int i = 0; i < l.tamanho; i++) {
        printf("%d elemento: %d\n", i + 1, aux->conteudo);
        aux = aux->proximo;
    }
}
