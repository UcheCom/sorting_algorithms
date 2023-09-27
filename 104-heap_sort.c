#include "sort.h"

/**
 * heap_set - This heapifies a subtree at 'root' recursively
 * @array: The array to be sorted
 * @hp: The total number of elements in the heap
 * @r: The root index of the subtree to be heapified
 * @size: The original size of the array
 */
void heap_set(int *array, size_t hp, size_t r, size_t size)
{
	size_t bgst = r;
	size_t lft = 2 * r + 1;
	size_t rgt = 2 * r + 2;
	int tmp;

	if (lft < hp && array[lft] > array[bgst])
		bgst = lft;

	if (rgt < hp && array[rgt] > array[bgst])
		bgst = rgt;

	if (bgst != r)
	{
		tmp = array[r];
		array[r] = array[bgst];
		array[bgst] = tmp;
		print_array(array, size);
		heap_set(array, hp, bgst, size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending
 * order using Heap Sort
 * @array: The array to be sorted
 * @size: The total number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1;
	int tmp;

	if (!array || size < 2)
		return;
	for (; i >= 0; i--)
		heap_set(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		if (i > 0)
		{
			print_array(array, size);
		}
		heap_set(array, i, 0, size);
	}
}
