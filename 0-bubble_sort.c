#include "sort.h"

/**
   * bubble_sort - Sort the element of an array and call print_array to print.
   * @array: The array to be sorted.
   * @size: The size of the array.
   */

void bubble_sort(int *array, size_t size)
{
size_t i = 0, j = 0;
int temp;

/*Return if array is NULL or there's only one or less elements*/
if (array == NULL || size < 2)
return;
for (i = 0; i < size - 1; i++)
{
for (j = 0; j < size - 1 - i; j++)
{
if (array[j + 1] < array[j])
{
/*swap elements if they are in the wrong order*/
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;
print_array(array, size);
}
}
}
}
