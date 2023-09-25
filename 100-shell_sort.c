#include "sort.h"

/**
 * shell_sort - This sorts an array of integers
 * in ascending order using Shell Sort
 *
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int swap;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			swap = array[i];
			j = i;
			while (j >= gap && array[j - gap] > swap)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = swap;
		}
		print_array(array, size);
		gap /= 3;
	}
}
