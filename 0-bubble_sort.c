#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * bubble_sort - function that sorts an array of integer
 * in ascending order using the Bubble sort algorithm
 * @array: array of integers to sort
 * @size: number of elements of array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;
	size_t li = size - 1;
	size_t z;

	if (!array || !size || size <= 0)
		return;
	k = 0;
	for (j = 0; j < li; j++)
	{
		for (i = 0; i < li - k; i++)
		{
			if (array[i] > array[i + 1])
			{
				z = array[i];
				array[i] = array[i + 1];
				array[i + 1] = z;
				print_array(array, size);
			}
		}
		k++;
	}
}
