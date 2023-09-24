#include "sort.h"


/**
 * swap_ints - this function swaps two integers
 * @d: first integer
 * @e: second integer
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - this function sorts an array of integers
 * @array: integers array
 * @size: array size
 * Description: prints array
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t m, n;

	if (array == NULL || size < 2)
		return;

	for (m = 0; m < size - 1; m++)
	{
		min = array + m;
		for (n = m + 1; n < size; n++)
			min = (array[n] < *min) ? (array + n) : min;

		if ((array + m) != min)
		{
			swap_ints(array + m, min);
			print_array(aray, size);
		}
	}
}

