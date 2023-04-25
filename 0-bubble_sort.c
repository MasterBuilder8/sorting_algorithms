#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * @array: array of integers to be sorted
 * @size: size of array of integers
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int i = 0, aux = 0, max = 0, swapped = 1;

	if (!array || size < 2)
		return;

	max = size - 1;

	for (; i < max; ++i)
	{
		if (array[i] > array[i + 1])
		{
			aux = array[i];
			array[i] = array[i + 1];
			array[i + 1] = aux;
			swapped = 1;
			print_array(array, size);
		}

		if (swapped == 1 && max == -1)
			i = -1, swapped = 0, --max;
	}
}
