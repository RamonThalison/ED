#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Sequencial {
  int *data;
  int size;
} slist;

slist *create_list();
void insert_element(slist *list, int element);
void print_list(slist *list);
void print_list_interval(slist *list, int start, int end);

#endif