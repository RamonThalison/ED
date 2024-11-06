
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 300
#define MAX_QUEUE 300
#define MAX_STACK 300

// Estrutura de Lista de Adjacência para um vértice
typedef struct No {
    int vertice;
    int peso;  // Adicionar o peso da aresta
    struct No* prox;
} No;

// Estrutura do Grafo usando Matriz de Adjacência
typedef struct {
    int num_vertices;
    int matriz[MAX_VERTICES][MAX_VERTICES];
} GrafoMatrizAdjacencia;

// Estrutura do Grafo usando Lista de Adjacência
typedef struct {
    int num_vertices;
    No** lista;
} GrafoListaAdjacencia;

// Funções de Grafo (Matriz de Adjacência)
void inicializarGrafoMatriz(GrafoMatrizAdjacencia* grafo, int num_vertices) {
    grafo->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            grafo->matriz[i][j] = 0; // Inicializa todos os valores da matriz com 0
        }
    }
}

// Exibe a matriz de adjacência
void exibirMatriz(GrafoMatrizAdjacencia* grafo) {
    for (int i = 0; i < grafo->num_vertices; i++) {
        for (int j = 0; j < grafo->num_vertices; j++) {
            printf("%d ", grafo->matriz[i][j]);
        }
        printf("\n");
    }
}

// Funções de Grafo (Lista de Adjacência)
void inicializarGrafoLista(GrafoListaAdjacencia* grafo, int num_vertices) {
    grafo->num_vertices = num_vertices;
    grafo->lista = (No**)malloc(num_vertices * sizeof(No*));
    if (!grafo->lista) {
        printf("Erro ao alocar memória para lista de adjacência.\n");
        exit(1);
    }

    for (int i = 0; i < num_vertices; i++) {
        grafo->lista[i] = NULL;
    }
}

// Cria um novo nó na lista de adjacência com o peso
No* criarNo(int vertice, int peso) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro ao alocar memória para nó.\n");
        exit(1);
    }
    novoNo->vertice = vertice;
    novoNo->peso = peso;  // Armazena o peso da aresta
    novoNo->prox = NULL;
    return novoNo;
}

// Adiciona uma aresta na lista de adjacência com o peso
void adicionarArestaLista(GrafoListaAdjacencia* grafo, int u, int v, int peso) {
    No* novoNo = criarNo(v, peso);
    novoNo->prox = grafo->lista[u];
    grafo->lista[u] = novoNo;
}

// Exibe a lista de adjacência com os pesos
void exibirLista(GrafoListaAdjacencia* grafo) {
    for (int i = 0; i < grafo->num_vertices; i++) {
        No* temp = grafo->lista[i];
        printf("Vértice %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertice);  // Exibe vértice
            temp = temp->prox;
        }
        printf("NULL\n\n");
    }
}

// Função para carregar grafo a partir de um arquivo que contém uma matriz de adjacência quadrada
void carregar_grafo_matriz(const char* nome_arquivo, GrafoMatrizAdjacencia* grafo_matriz) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int num_vertices;
    fscanf(arquivo, "%d", &num_vertices); // Lê o número de vértices
    inicializarGrafoMatriz(grafo_matriz, num_vertices); // Inicializa a estrutura do grafo

    // Preenche a matriz de adjacência com os valores do arquivo
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            fscanf(arquivo, "%d", &grafo_matriz->matriz[i][j]);
        }
    }

    fclose(arquivo); // Fecha o arquivo
}

// Função para converter uma matriz de adjacência em lista de adjacência sem duplicar arestas
void converter_matriz_para_lista(GrafoMatrizAdjacencia* grafo_matriz, GrafoListaAdjacencia* grafo_lista) {
    inicializarGrafoLista(grafo_lista, grafo_matriz->num_vertices); // Inicializa a lista de adjacência

    for (int i = 0; i < grafo_matriz->num_vertices; i++) {
        for (int j = i + 1; j < grafo_matriz->num_vertices; j++) {
            // Adiciona aresta apenas uma vez, ou seja, se existe uma aresta entre i e j
            if (grafo_matriz->matriz[i][j] != 0) {
                adicionarArestaLista(grafo_lista, i, j, grafo_matriz->matriz[i][j]); // Adiciona aresta de i para j
                adicionarArestaLista(grafo_lista, j, i, grafo_matriz->matriz[i][j]); // Adiciona aresta de j para i
            }
        }
    }
}

// Função auxiliar para impressão de caminho
void imprimirCaminho(int* antecessor, int v) {
    if (antecessor[v] == -1) {
        printf("%d", v);
        return;
    }
    imprimirCaminho(antecessor, antecessor[v]);
    printf(" -> %d", v);
}

// Implementação de Busca em Largura (BFS)
void bfs(GrafoMatrizAdjacencia* grafo, int s, int t) {
    bool visitado[MAX_VERTICES] = {false};
    int fila[MAX_QUEUE];
    int inicio = 0, fim = 0;
    int antecessor[MAX_VERTICES];
    for (int i = 0; i < grafo->num_vertices; i++) {
        antecessor[i] = -1;
    }

    visitado[s] = true;
    fila[fim++] = s;

    while (inicio != fim) {
        int u = fila[inicio++];
        for (int v = 0; v < grafo->num_vertices; v++) {
            if (grafo->matriz[u][v] != 0 && !visitado[v]) {
                visitado[v] = true;
                antecessor[v] = u;
                fila[fim++] = v;
                if (v == t) {
                    printf("Caminho BFS de %d até %d: ", s, t);
                    imprimirCaminho(antecessor, t);
                    printf("\n");
                    return;
                }
            }
        }
    }

    printf("Não há caminho entre %d e %d\n", s, t);
}

// Implementação de Busca em Profundidade (DFS) usando pilha
void dfs(GrafoMatrizAdjacencia* grafo, int s, int t) {
    bool visitado[MAX_VERTICES] = {false};
    int pilha[MAX_STACK];
    int topo = -1;
    int antecessor[MAX_VERTICES];
    for (int i = 0; i < grafo->num_vertices; i++) {
        antecessor[i] = -1;
    }

    pilha[++topo] = s;
    visitado[s] = true;

    while (topo != -1) {
        int u = pilha[topo--];
        if (u == t) {
            printf("Caminho DFS de %d até %d: ", s, t);
            imprimirCaminho(antecessor, t);
            printf("\n");
            return;
        }

        for (int v = 0; v < grafo->num_vertices; v++) {
            if (grafo->matriz[u][v] != 0 && !visitado[v]) {
                visitado[v] = true;
                antecessor[v] = u;
                pilha[++topo] = v;
            }
        }
    }

    printf("Não há caminho entre %d e %d\n", s, t);
}

int main() {
    GrafoMatrizAdjacencia grafo_matriz;
    GrafoListaAdjacencia grafo_lista;

    // Carregar o grafo a partir de um arquivo de matriz de adjacência quadrada
    carregar_grafo_matriz("pcv50.txt", &grafo_matriz);

    // Exibir o grafo em forma de matriz de adjacência
    printf("Matriz de Adjacência:\n");
    exibirMatriz(&grafo_matriz);

    // Converter a matriz de adjacência para lista de adjacência
    converter_matriz_para_lista(&grafo_matriz, &grafo_lista);

    // Exibir o grafo em forma de lista de adjacência
    printf("\nLista de Adjacência:\n");
    exibirLista(&grafo_lista);

    // Realizar busca em largura (BFS) e busca em profundidade (DFS)
    int origem, destino;
    printf("Digite a origem da busca: ");
    scanf("%d", &origem);
    printf("\nDigite o destino da busca: ");
    scanf("%d", &destino);
    printf("\n\nBusca em Largura (BFS):\n");
    bfs(&grafo_matriz, origem, destino);

    printf("\nBusca em Profundidade (DFS):\n");
    dfs(&grafo_matriz, origem, destino);

    return 0;
}
