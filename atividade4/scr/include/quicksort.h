#include "sequencial_list.h"
#include <time.h>

void quicksort(slist *list, int start, int end);
int partition(slist *list, int start, int end);
void swap(slist *list, int pos1, int pos2);