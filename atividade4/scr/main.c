#include "include/quicksort.h"
#include "include/mergesort.h"
#include "include/sequencial_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

slist *numbers;
int *array_numbers;

void quicksort_np() {
    quicksort(numbers, 0, numbers->size - 1);
}


void mergesort_np() {
    mergeSort(array_numbers, 0, numbers->size - 1);
}

// Função para medir o tempo de execução
void medirTempoExecucao(void (*func)()) {
    clock_t inicio = clock();
    func();
    clock_t fim = clock();
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.6f segundos\n", tempo_execucao);
}

slist *select_and_read_file() {
    char input[256];
    printf("Digite o nome do arquivo quer usar como teste: ");
    scanf("%s", input);

    printf("Lendo arquivo...\n");
    char file_path[300];
    snprintf(file_path, sizeof(file_path), "./inputs/%s", input);

    FILE *file = fopen(file_path, "r");

    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    slist *list = create_list();
    int i;
    for (i = 0; fscanf(file, "%s", input) != EOF; i++) {
        insert_element(list, atoi(input));
    }
    list->size = i;
    fclose(file);
    return list;
}

int main() {
    numbers = select_and_read_file();

    // Copia os números para um array
    array_numbers = (int *)malloc(numbers->size * sizeof(int));
    for (int i = 0; i < numbers->size; i++) {
        array_numbers[i] = numbers->data[i];
    }

    // Medir tempo de quicksort
    medirTempoExecucao(quicksort_np);

    // Medir tempo de mergesort
    medirTempoExecucao(mergesort_np);

    // Exibir lista ordenada
    print_list(numbers);

    // Limpeza de memória
    free(array_numbers);
    return 0;
}
