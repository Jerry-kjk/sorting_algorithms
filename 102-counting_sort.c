#include "sort.h"

/**
 * max - a function that get the maximum value in an array of integers.
 * @array: the array of integers.
 * @size: the size of array.
 * Return: maximum integer in the array.
 */

int max(int *array, int size)
{
	int a, b;

	for (a = array[0], b = 1; b < size; b++)
	{
		if (array[b] > a)
			a = array[b];
	}
	return (a);
}

/**
 * counting_sort - a function that sorts an array of integers in
 * ascending order using the Counting sort algorithm.
 * @array: the array of integers.
 * @size: the size of array.
 */

void counting_sort(int *array, size_t size)
{
	int *count;
	int *sorted;
	int a;
	int b;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	a = max(array, size);
	count = malloc(sizeof(int) * (a + 1));

	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (b = 0; b < (a + 1); b++)
		count[b] = 0;
	for (b = 0; b < (int)size; b++)
		count[array[b]] += 1;
	for (b = 0; b < (a + 1); b++)
		count[b] += count[b - 1];
	print_array(count, a + 1);
	for (b = 0; b < (int)size; b++)
	{
		sorted[count[array[b]] - 1] = array[b];
		count[array[b]] -= 1;
	}

	for (b = 0; b < (int)size; b++)
		array[b] = sorted[b];

	free(sorted);
	free(count);
}
