#include "sort.h"

/**
* bi_merge - This merges two subarrays
* @array: Array to be sorted
* @size: Size of the array
* @flo: Direction, ascending- (1) descending- (0)
* @bi_size: Size of the bitonic subarray to merge
*/
void bi_merge(int *array, size_t size, int flo, size_t bi_size)
{
	size_t i, n;
	int tmp;

	if (bi_size > 1)
	{
		n = bi_size / 2;
		for (i = 0; i < size - n; i++)
		{
			if ((array[i] > array[i + n]) == flo)
			{
				tmp = array[i];
				array[i] = array[i + n];
				array[i + n] = tmp;
			}
		}
		bi_merge(array, size, flo, n);
		bi_merge(array + n, size - n, flo, n);
	}
}

/**
* bi_sort - Bitonic recursive sorting
* @array: Array to sort
* @size: Size of array
* @flo: Direction, ascending- (1), descending- (0)
* @bi_size: size of the subarray
*/
void bi_sort(int *array, size_t size, int flo, size_t bi_size)
{
	size_t n;

	if (bi_size > 1)
	{
		n = bi_size / 2;
		printf("Merging [%d/%d] ", (int)bi_size, (int)size);
		if (flo == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array, bi_size);
		bi_sort(array, n, 1, size);
		bi_sort(array + n, n, 0, size);
		bi_merge(array, bi_size, flo, size);
		printf("Result [%d/%d] ", (int) bi_size, (int)size);
		if (flo == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array, bi_size);
	}
}

/**
* bitonic_sort - This sorts array using bitonic algorithm
* @array: Array to sort
* @size: Size of array
*/
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	bi_sort(array, size, 1, size);
}
