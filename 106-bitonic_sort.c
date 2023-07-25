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
 * bitonic - a function that sort a bitonic sequence inside an
 * array of integers.
 * @array: array of integers.
 * @size: size of the array.
 * @st: starting index of the sequence in array to sort.
 * @se: size of the sequence to sort.
 * @flow: direction to sort in.
 */

void bitonic(int *array, size_t size, size_t st, size_t se, char flow)
{
	size_t i;
	size_t jump = se / 2;

	if (se > 1)
	{
		for (i = st; i < st + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				ints(array + i, array + i + jump);
		}
		bitonic(array, size, st, jump, flow);
		bitonic(array, size, st + jump, jump, flow);
	}
}

/**
 * bitonic_se - a function that convert an array of integers into a bitonic
 * sequence.
 * @array: array of integers.
 * @size: size of the array.
 * @st: starting index of the sequence in array to sort.
 * @se: size of the sequence to sort.
 * @flow: direction to sort in.
 */

void bitonic_se(int *array, size_t size, size_t st, size_t se, char flow)
{
	size_t cut = se / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (se > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", se, size, str);
		print_array(array + st, se);

		bitonic_se(array, size, st, cut, UP);
		bitonic_se(array, size, st + cut, cut, DOWN);
		bitonic(array, size, st, se, flow);

		printf("Result [%lu/%lu] (%s):\n", se, size, str);
		print_array(array + st, se);
	}
}

/**
 * bitonic_sort - a function that sorts an array of integers in
 * ascending order using the Bitonic sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_se(array, size, 0, size, UP);
}
