#include "sort.h"

/**
 * swap_val - a function that swaps two integers in an array.
 * @i: first integer to be swaped.
 * @j: second integer to be swaped.
 */

void swap_val(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * bubble_sort - a function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm.
 * @array: array of integer.
 * @size: size of the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t a;
	size_t ln = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (a = 0; a < ln - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				swap_val(array + a, array + a + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		ln--;
	}
}
