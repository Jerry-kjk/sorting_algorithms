#include "sort.h"

/**
 * ints - a function that swap two integers in an array.
 * @a: first integer to be swaped.
 * @b: second integer to be swaped.
 */

void ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - order a subset of an array of integers
 * according to the hoare partition scheme.
 * @array: array of integers.
 * @size: size of the array.
 * @l: starting index of the subset to order.
 * @r: ending index of the subset to order.
 * Return: the final partition index.
 */

int partition(int *array, size_t size, int l, int r)
{
	int p;
	int a;
	int b;

	p = array[r];
	for (a = l - 1, b = r + 1; a < b;)
	{
		do {
			a++;
		} while (array[b] > p);

		if (a < b)
		{
			ints(array + a, array + b);
			print_array(array, size);
		}
	}
	return (a);
}

/**
 * sort - implement the quicksort algorithm through recursion.
 * @array: array of integers.
 * @size: size of the array.
 * @l: starting index of the subset to order.
 * @r: ending index of the subset to order.
 */

void sort(int *array, size_t size, int l, int r)
{
	int pa;

	if (r - l > 0)
	{
		pa = partition(array, size, l, r);
		sort(array, size, l, pa - 1);
		sort(array, size, pa, r);
	}
}

/**
 * quick_sort_hoare - a function that sorts an array of integers in
 * ascending order using the Quick sort algorithm.
 * @array: array of integers representing a binary tree.
 * @size: size of the array.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, size, 0, size - 1);
}
