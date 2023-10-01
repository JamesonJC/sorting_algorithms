#include "sort.h"

/**
  * shell_sort - Sorts an array of integers in ascending order using
  *              the Shell Sort algorithm.
  * @array: An array of integers.
  * @size: The size of the array.
  *
  * Description: Uses the Knuth interval sequence for gap calculation.
  */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;
	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				/* Swap elements using a temporary variable */
				temp = array[j];
				array[j] = array[j - gap];
				array[j - gap] = temp;
				j -= gap;
			}
		}
		/* Print the array after each pass */
		print_array(array, size);
	}
}
