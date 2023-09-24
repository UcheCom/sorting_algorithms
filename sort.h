#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);

#endif
