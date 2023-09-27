#include "sort.h"

/**
 * merge_sort - This sorts an array of integers in ascending
 * order using Merge Sort.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = malloc(size * sizeof(int));
	if (!tmp)
		return;

	merge_sort_recursion(array, tmp, 0, size);
	free(tmp);
}

/**
 * merge_sort_recursion - This recursively sorts a subarray
 * of integers using Merge Sort.
 * @array: The array to be sorted.
 * @tmp: A temporary array for merging.
 * @l: The left index of the subarray.
 * @r: The right index of the subarray.
 */
void merge_sort_recursion(int *array, int *tmp, size_t l, size_t r)
{
	size_t m;

	if (r - l > 1)
	{
		m = l + (r - l) / 2;
		merge_sort_recursion(array, tmp, l, m);
		merge_sort_recursion(array, tmp, m, r);

		merge_sorted_arrays(array, tmp, l, m, r);
	}
}

/**
 * merge_sorted_arrays - Merges two sorted subarrays
 * into a single sorted array.
 *
 * @array: The original array.
 * @tmp: A temporary array for merging.
 * @l: The left index of the left subarray.
 * @m: The middle index that separates the two subarrays.
 * @r: The right index of the right subarray.
 */
void merge_sorted_arrays(int *array, int *tmp, size_t l, size_t m, size_t r)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + l, m - l);

	printf("[right]: ");
	print_array(array + m, r - m);

	for (i = l, j = m; i < m && j < r; k++)
		tmp[k] = (array[i] < array[j]) ? array[i++] : array[j++];

	for (; i < m; i++)
		tmp[k++] = array[i];

	for (; j < r; j++)
		tmp[k++] = array[j];

	for (i = l, k = 0; i < r; i++)
		array[i] = tmp[k++];

	printf("[Done]: ");
	print_array(array + l, r - l);
}
