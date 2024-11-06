#include "include/sequencial_list.h"

slist *create_list() {
  slist *list = malloc(sizeof(slist));
  list->data = 0;
  list->size = 0;

  return list;
}

void insert_element(slist *list, int element) {
  list->data = realloc(list->data, sizeof(int) * (list->size + 1));
  list->data[list->size] = element;
  list->size++;
}

void print_list(slist *list) {
  for (int i = 0; i < list->size; i++) {
    printf("%d ", list->data[i]);
  }
  printf("\n");
}

void print_list_interval(slist *list, int start, int end) {
  for (int i = start; i <= end; i++) {
    printf("%d ", list->data[i]);
  }
  printf("\n");
}