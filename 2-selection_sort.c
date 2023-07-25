#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: array of integers
 * @size: number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
	int i = 0, tmp1 = 0, z = 0, min_p = 0;

	if (!array || !size || size <= 0)
		return;
	for (i = 0; i < (int)size - 1; i++)
	{
		min_p = i;
		for (z = i + 1; z < (int)size; z++)
		{
			if (array[min_p] > array[z])
				min_p = z;
		}
		if (array[min_p] < array[i])
		{
			tmp1 = array[i];

			array[i] = array[min_p];
			array[min_p] = tmp1;
			print_array(array, size);
			min_p = 0;
			tmp1 = 0;
		}
	}
}
