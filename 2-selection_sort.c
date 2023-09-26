#include "sort.h"

/**
  * selection_sort - Sort the elements of an array with selection sort algo.
  * @array: Arrat to be sorted.
  * @size: The size of the array.
  */

void selection_sort(int *array, size_t size)
{
size_t i = 0, j, min_index;
int tmp;
if (array == NULL || size < 2)
return;

while (i < size - 1)
{
min_index = i;
/*Getting minimum on the remaining elements*/
for (j = i + 1; j < size; j++)
{
if (array[j] < array[min_index])
min_index = j;
}
/*Swap the minimum element and the current*/
if (min_index != i)
{
tmp = array[i];
array[i] = array[min_index];
array[min_index] = tmp;
print_array(array, size);
}
i++;
}
}
