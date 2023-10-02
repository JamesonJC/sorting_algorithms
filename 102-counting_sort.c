#include "sort.h"
#include <stdlib.h>

/**
  * get_max - Return maximum value in an integer array.
  * @array: An array of integers.
  * @size: The size of the array.
  * Return: The maximum integer in the array.
  */

int get_max(int *array, int size)
{
	int max = array[0];
	int i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

/**
  * counting_sort - Sorts an array using the counting sort algorithm.
  * @array: An array of integers.
  * @size: The size of the array.
  */

void counting_sort(int *array, size_t size)
{
	int i, max, *count, *sorted;
	size_t j;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	sorted = malloc(sizeof(int) * size);
	if (count == NULL || sorted == NULL)
	{
		free(count);
		free(sorted);
		return;
	}

	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (j = 0; j < size; j++)
		count[array[j]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (j = size - 1; j > 0; j--)
	{
		sorted[count[array[j]] - 1] = array[j];
		count[array[j]]--;
	}
	for (j = 0; j < size; j++)
		array[j] = sorted[j];
	free(count);
	free(sorted);
}
