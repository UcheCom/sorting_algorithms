#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 *                     using the Cocktail Shaker Sort algorithm.
 * @list: A pointer to a pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp, *curr, *left, *right;
	int swap;

	if (!list || !*list || !(*list)->next)
		return;

	tmp = *list;
	do {
		swap = 0;
		while (tmp->next)
		{
			curr = tmp;
			if (curr->n > curr->next->n)
			{
				right = curr->next;
				_swapnodes(list, curr, right);
				swap = 1;
				continue;
			}
			tmp = tmp->next;
		}
		if (swap == 0)
			break;
		swap = 0;
		while (tmp->prev)
		{
			curr = tmp;
			if (curr->n < curr->prev->n)
			{
				left = curr->prev;
				_swapnodes(list, left, curr);
				swap = 1;
				continue;
			}
			tmp = tmp->prev;
		}
	} while (swap == 1);
}

/**
 * swap_nodes - This swaps the node to the right
 * @list: Pointer to the head of the list
 * @x: First node
 * @y: Second node
 */
void _swapnodes(listint_t **list, listint_t *x, listint_t *y)
{
	y->prev = x->prev;
	x->next = y->next;
	if (y->next)
		(y->next)->prev = x;
	if (x->prev)
		(x->prev)->next = y;
	x->prev = y;
	y->next = x;
	if (!y->prev)
		*list = y;
	print_list(*list);
}
