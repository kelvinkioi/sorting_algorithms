#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: array of integers
 * @size: number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
	int i = 0, tmp1 = 0, z = 0, tmp2 = 0;

	if (!array || !size || size <= 0)
		return;
	for (i = 0; i < (int) size; i++)
	{
		tmp2 = i;
		for (z = i + 1; z < (int)size; z++)
		{
			if (array[tmp2] > array[z])
				tmp2 = z;
		}
		if (array[tmp2] < array[i])
		{
			tmp1 = array[i];

			array[i] = array[tmp2];
			array[tmp2] = tmp1;
			print_array(array, size);
			tmp2 = 0;
			tmp1 = 0;
		}
	}
}
