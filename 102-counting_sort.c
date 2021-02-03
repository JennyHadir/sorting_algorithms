#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * counting_sort - sort an array in counting sort method
 * @array: array to be sorted
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *second_array, *counting_array, max, j;
	size_t i;

	if (!array || size < 2)
		return;
	max = array[0];
	second_array = malloc(sizeof(int) * size);
	if (!second_array)
	{
		free(second_array);
		return;
	}
	for (i = 0; i < size; i++)
	{
		second_array[i] = array[i];
		if (array[i] > max)
			max = array[i];
	}
	counting_array = malloc((max + 1) * sizeof(int));
	if (!counting_array)
	{
		free(second_array);
		free(counting_array);
		return; }
	for (j = 0; j <= max; j++)
		counting_array[j] = 0;
	for (i = 0; i < size; i++)
		counting_array[array[i]] += 1;
	for (j = 1; j <= max; j++)
		counting_array[j] += counting_array[j - 1];
	print_array(counting_array, max + 1);
	for  (i =  0 ; i < size; i++)
	{
		second_array[counting_array[array[i]] -  1] = array[i];
		counting_array[array[i]] -=  1; }
	for (i = 0; i < size; i++)
		array[i] = second_array[i];
	free(counting_array);
	free(second_array);
}
