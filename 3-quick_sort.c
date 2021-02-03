#include "sort.h"
/**
 * partition - swap elements of array with quick sort method
 * @array: array to be sorted
 * @low: first element of array
 * @high: last element of array
 * @size: size of array
 * Return: index of new pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int j, i = low;
	int pivot = array[high], aux;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[high] < array[i + 1])
	{
		if (high != i)
		{
			aux = array[i];
			array[i] = array[high];
			array[high] = aux;
			print_array(array, size);
		}
	}
	return (i);
}
/**
 * quicksort - recursive quicksort
 * @array: array to be sorted
 * @low: first element of array
 * @high: last element of aray
 * @size: size of array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}
/**
 *quick_sort - quick sort function
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
