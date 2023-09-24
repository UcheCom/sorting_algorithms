#include "sort.h"

/**
 * quick_sort - This sorts an array of integer using Quick sort
 * @array: The array to be sorted
 * @size: The number of elements in the array.
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	q_sort(array, 0, size - 1, size);
}

/**
 * q_sort - Recursive function for Quick Sort Algorithm
 * @arr: The array to be sorted
 * @smal: The small index of the partition
 * @big: The big index of the partition
 * @size: The number of elements in the array
 */
void q_sort(int *arr, int smal, int big, size_t size)
{
	int pivot;

	if (smal >= big)
		return;

	pivot = lomuto_partition(arr, smal, big, size);

	q_sort(arr, smal, pivot - 1, size);
	q_sort(arr, pivot + 1, big, size);
}

/**
 * lomuto_partition - This implements the Lomuto partition scheme
 * @arr: The array to be partitioned
 * @smal: The small index of the partition
 * @big: The big index of the partition
 * @size: The number of elements in the array
 *
 * Return: The pivot index
 */
int lomuto_partition(int *arr, int smal, int big, size_t size)
{
	int pivot = arr[big], swap;
	int i, j;

	i = smal;
	for (j = smal; j < big; j++)
	{
		if (arr[j] <= pivot)
		{
			if (j != i)
			{
				swap = arr[i];
				arr[i] = arr[j];
				arr[j] = swap;
				print_array(arr, size);
			}
			i++;
		}
	}

	if (i != big && arr[i] != pivot)
	{
		swap = arr[i];
		arr[i] = arr[big];
		arr[big] = swap;
		print_array(arr, size);
	}
	return (i);
}
