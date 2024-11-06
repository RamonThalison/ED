#include "include/quicksort.h"

void quicksort(slist *list, int start, int end) {
  if (start < end) {
    int p = partition(list, start, end);
    quicksort(list, start, p - 1);
    quicksort(list, p + 1, end);
  }
}

int partition(slist *list, int start, int end) {
  // Escolhe aleatóriamente o pivô
  srand(time(0));
  int pivot = start + rand() % (end - start + 1);

  // Troca o pivô com a posição inicial
  swap(list, pivot, start);


  // Ordena a partição
  int element = list->data[start];
  int i = start + 1;
  int j = end;

  while (1) {
    // Enqaunto o elemento da esquerda for menor que o pivô
    while (list->data[i] <= element) {
      i++;
    }

    // Enquanto o elemento da direita for maior que o pivô
    while (list->data[j] >= element && j > start) {
      j--;
    }

    if (i > j) {
      swap(list, start, j);
      return j;
    }

    swap(list, i, j);
  }
}

void swap(slist *list, int pos1, int pos2) {
  int aux = list->data[pos1];
  list->data[pos1] = list->data[pos2];
  list->data[pos2] = aux;
}