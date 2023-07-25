#include "sort.h"

/**
 * swap_integers - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_integers(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Lomuto partition scheme for Quick sort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int *pivot, top, down;
	pivot = array + high;
	
	for (top = down = low; down < high; down++)
	{
		if (array[down] < *pivot)
		{
			if (top < down)
			{
				swap_integers(array + down, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *pivot)
	{
		swap_integers(array + top, pivot);
		print_array(array, size);
	}
	return (top);
}

/**
 * quick_sort_aid - Helper function for Quick sort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quick_sort_aid(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		quick_sort_aid(array, low, pi - 1, size);
		quick_sort_aid(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_aid(array, 0, size - 1, size);
}
