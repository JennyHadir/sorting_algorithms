#include "sort.h"

/**
 * selection_sort - sort an array with selection method
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j;
	int min, pos, aux;

	if (array != NULL && size > 2)
	{

		for (i = 0; i < size; i++)
		{
			min = array[i];
			pos = 0;
			for (j = i; j < size; j++)
			{
				if (min > array[j])
				{
					min = array[j];
					pos = j;
				}
			}
			if (pos != 0)
			{
				aux = array[i];
				array[i] = min;
				array[pos] = aux;
				print_array(array, size);
			}
		}
	}
}
