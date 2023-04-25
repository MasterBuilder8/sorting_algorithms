#include "sort.h"


/**
 * quick_sort - function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers to be sorted
 * @size: size of array of integers to be sorted
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	int start = 0, end = size - 1;

	if (!array || size < 2)
		return;

	quick_sort2(array, start, end, size);
}
/**
 * quick_sort2 - function that sorts an array of integers
 * @array: array of integers to be sorted
 * @start: the start of the array
 * @end: end of array to be sorted
 * @size: size  of array of integers  to be sorted
 * Return: nothing
 */
void quick_sort2(int *array, int start, int end, int size)
{
	int pivot_index;

	if (start < end)
	{
		pivot_index = lomut_partition(array, start, end, size);
		quick_sort2(array, start, pivot_index - 1, size);
		quick_sort2(array, pivot_index + 1, end, size);
	}
}
/**
 * lomut_partition - function that partitions the array of integers
 * @array: array of the integers  to be sorted
 * @strt: first index
 * @nd: last index
 * @size: size of the array of integers to be sorted
 * Return: the index of the pivot element
 */
int lomut_partition(int *array, int strt, int nd, int size)
{
	int pivot = array[nd], pivot_index = strt, j, temp;

	for (j = strt; j < nd; j++)
	{
		if (array[j] <= pivot)
		{
			if (pivot_index != j)
			{
				temp = array[pivot_index];
				array[pivot_index] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			pivot_index++;
		}
	}
	if (pivot_index != nd)
	{
		temp = array[pivot_index];
		array[pivot_index] = array[nd];
		array[nd] = temp;
		print_array(array, size);
	}

	return (pivot_index);
}

