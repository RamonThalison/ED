#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

int main() {
    // Criando uma lista
    lista l = criarLista();
    
    // Verificando se a lista está vazia
    verificarLista(l);
    
    // Inserindo elementos na lista
    inserirElemento(&l, 1, 10);  // Insere o elemento 10 na posição 1
    inserirElemento(&l, 2, 20);  // Insere o elemento 20 na posição 2
    inserirElemento(&l, 2, 30);  // Insere o elemento 30 na posição 2
    
    // Imprimindo a lista
    imprimirLista(l);
    
    // Obtendo o tamanho da lista
    printf("Tamanho da lista: %d\n", obterTamanho(l));
    
    // Modificando um elemento da lista
    modificarElemento(&l, 2, 25);  // Modifica o elemento da posição 2 para 25
    imprimirLista(l);
    
    // Obtendo o valor de um elemento da lista
    int valor = obterValor(l, 2);  // Obtém o valor do elemento na posição 2
    if (valor != -1) { 
        printf("Valor na posicao 2: %d\n", valor);
    }
    
    // Removendo um elemento da lista
    retirarElemento(&l, 1);  // Remove o elemento da posição 1
    imprimirLista(l);
    
    return 0;
}
