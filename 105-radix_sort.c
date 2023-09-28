#include "sort.h"

/**
 * _getmax - This finds the maximum element in an array
 * @array: The array to find the maximum from
 * @size: The size of the array
 * Return: The maximum element in the array
 */
int _getmax(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * radix_sort - This sorts an array of integers in ascending
 * order using Radix Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max;
	int lsd;

	if (!array || size < 2)
		return;

	max = _getmax(array, size);

	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		_countingsort(array, size, lsd);
		print_array(array, size);
	}
}

/**
 * _countingsort - This performs counting sort on an array
 * @array: The array to be sorted
 * @size: The size of the array
 * @lsd: The current exponent (significant digit)
 */
void _countingsort(int *array, size_t size, int lsd)
{
	int *op, x, y;
	int counter[10] ={0};
	size_t i, m;

	op = malloc(sizeof(int) * size);

	if (!op)
		return;

	for (i = 0; i < size; i++)
		counter[(array[i] / lsd) % 10]++;

	for (x = 1; x < 10; x++)
		counter[x] += counter[x - 1];

	for (y = size - 1; y >= 0; y--)
	{
		op[counter[(array[y] / lsd) % 10] - 1] = array[y];
		counter[(array[y] / lsd) % 10]--;
	}

	for (m = 0; m < size; m++)
		array[m] = op[m];

	free(op);
}
