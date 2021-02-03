#include "sort.h"
/**
 * shell_sort - sort an array with shell sort method
 * @array: array to be sorted
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i;
	int item, j;

	while (gap <= size / 3)
	{
		gap = 3 * gap + 1;
	}
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			item = array[i];
			for (j = i - gap; j >= 0 && item < array[j]; j = j - gap)
			{
				array[j + gap] = array[j];
			}
			array[j + gap] = item;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
