#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/* comparison direction */
#define UP 0
#define DOWN 1

/**
 * enum bool - this is thge enumeration of boolean values
 * @false: equals 0
 * @true: equals 1
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - this is a doubly linked list
 * @n: integer
 * @prev: previous pointer
 * @next: next element pointer
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* print help functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void q_sort(int *arr, int smal, int big, size_t size);
int lomuto_partition(int *arr, int smal, int big, size_t size);

/* sorting algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);
void swap_ints(int *a, int *b);

#endif
