#include "sort.h"

/**
 * counting_sort - This sorts an array of integers
 * in ascending order using Counting Sort
 *
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *op, k;
	int i;

	if (!array || size <= 1)
		return;

	k = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	count = malloc(sizeof(int) * (k + 1));
	if (!count)
		return;
	for (i = 0; i <= k; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];
	print_array(count, k + 1);

	op = malloc(sizeof(int) * size);
	if (!op)
	{
		free(count);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		op[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = op[i];
	free(count);
	free(op);
}
