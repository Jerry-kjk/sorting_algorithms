#include "sort.h"

/**
 * subarray - a function that sorts a subarray of integers.
 * @sub: subarray of an array of integers to be sorted.
 * @buff: buffer to store the sorted subarray.
 * @front: front index of the array.
 * @mid: middle index of the array.
 * @back: back index of the array.
 */

void subarray(int *sub, int *buff, size_t front, size_t mid, size_t back)
{
	size_t i;
	size_t j;
	size_t k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub + front, mid - front);

	printf("[right]: ");
	print_array(sub + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (sub[i] < sub[j]) ? sub[i++] : sub[j++];
	for (; i < mid; i++)
		buff[k++] = sub[i];
	for (; j < back; j++)
		buff[k++] = sub[j];
	for (i = front, k = 0; i < back; i++)
		sub[i] = buff[k++];

	printf("[Done]: ");
	print_array(sub + front, back - front);
}

/**
 * sort_recursive - a function that implements the merge sort
 * algorithm through recursion.
 * @sub: subarray of an array of integers to be sorted.
 * @buff: buffer to store the sorted subarray.
 * @front: front index of the array.
 * @back: back index of the array.
 */

void sort_recursive(int *sub, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		sort_recursive(sub, buff, front, mid);
		sort_recursive(sub, buff, mid, back);
		subarray(sub, buff, front, mid, back);
	}
}

/**
 * merge_sort - a function that sorts an array of integers
 * in ascending order using the Merge sort algorithm.
 * @array: array of integers.
 * @size: size of array.
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	sort_recursive(array, buff, 0, size);

	free(buff);
}
