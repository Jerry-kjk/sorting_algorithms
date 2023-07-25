#include "sort.h"

/**
 * get_max - a function that get the maximum value in an array.
 * @array: array of integers.
 * @size: size of the array.
 * Return: the maximum value in the array.
 */

int get_max(int *array, int size)
{
	int max;
	int i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * count_sort - a function that sort an array of integers using.
 * Counting Sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 * @s: significant digit to sort on.
 * @buff: buffer to store the sorted array.
 */

void count_sort(int *array, size_t size, int s, int *buff)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / s) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / s) % 10] - 1] = array[i];
		count[(array[i] / s) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - a function that sorts an array of integers
 * in ascending order using the Radix sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 */

void radix_sort(int *array, size_t size)
{
	int max;
	int s;
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (s = 1; max / s > 0; s *= 10)
	{
		count_sort(array, size, s, buff);
		print_array(array, size);
	}
	free(buff);
}
