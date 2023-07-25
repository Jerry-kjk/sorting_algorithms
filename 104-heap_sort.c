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
 * heapify - a function that turns a binary tree into a complete binary heap.
 * @array: array of integers representing a binary tree.
 * @size: size of the array.
 * @base: index of the base row of the tree.
 * @root: root node of the binary tree.
 */

void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t l;
	size_t r;
	size_t la;

	l = 2 * root + 1;
	r = 2 * root + 2;
	la = root;

	if (l < base && array[l] > array[la])
		la = l;
	if (r < base && array[r] > array[la])
		la = r;
	if (la != root)
	{
		ints(array + root, array + la);
		print_array(array, size);
		heapify(array, size, base, la);
	}
}

/**
 * heap_sort - a function that sorts an array of integers
 * in ascending order using the Heap sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		ints(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
