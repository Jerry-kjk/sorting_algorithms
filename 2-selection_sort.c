#include "sort.h"

/**
 * swap_ints - a function that swaps two integers in an array.
 * @a: first integer to be swaped.
 * @b: second integer to be swaped.
 */

void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - a function that sorts an array of
 * integers in ascending order using the Selection sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int *x;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		x = array + i;
		for (j = i + 1; j < size; j++)
			x = (array[j] < *x) ? (array + j) : x;
		if ((array + i) != x)
		{
			swap_ints(array + i, x);
			print_array(array, size);
		}
	}
}
