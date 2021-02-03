#include "sort.h"

/**
 *bubble_sort - sort an array with bubble sort methode
 * @array: array to be sorted
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
int aux;
unsigned int i, j;

if (size > 2 && array != NULL)
{
for (i = 0; i < size - 1; i++)
{
for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
aux = array[j];
array[j] = array[j + 1];
array[j + 1] = aux;
print_array(array, size);
}
}
}
}
return;
}
