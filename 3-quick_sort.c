#include "sort.h"

/**
 * swap_ints - a function that swaps two integers in an array.
 * @a: first integer to be swapd.
 * @b:second integer to be swaped.
 */

void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - a function that ordersa subset of an array of integers
 * according to the lomuto partition scheme (last element as pivot).
 * @array: array of integers.
 * @size: size of the array.
 * @l: starting index of the subset to order.
 * @r: ending index of the subset to order.
 * Return: the final partition index.
 */

int partition(int *array, size_t size, int l, int r)
{
	int *p;
	int a;
	int b;

	p = array + r;
	for (a = b = l; b < r; b++)
	{
		if (array[b] < *p)
		{
			if (a < b)
			{
				swap_ints(array + b, array + a);
				print_array(array, size);
			}
			a++;
		}
	}
	if (array[a] > *p)
	{
		swap_ints(array + a, p);
		print_array(array, size);
	}
	return (a);
}

/**
 * lomuto_sort - a function that implement the quicksort algorithm
 * through recursion.
 * @array: array of integers.
 * @size: size of the array.
 * @l: starting index of the subset to order.
 * @r: ending index of the subset to order.
 */

void lomuto_sort(int *array, size_t size, int l, int r)
{
	int x;

	if (r - l > 0)
	{
		x = partition(array, size, l, r);
		lomuto_sort(array, size, l, x - 1);
		lomuto_sort(array, size, x + 1, r);
	}
}

/**
 * quick_sort - a function that sorts an array of
 * integers in ascending order using the Quick sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
