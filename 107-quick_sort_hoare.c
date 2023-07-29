#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - performs the Hoare partition scheme for Quick Sort
 * @array: pointer to the first element of the array to be partitioned
 * @size: number of elements in the array
 * @start: starting index of the partition
 * @end: ending index of the partition
 *
 * Return: index of the partition
 */
int hoare_partition(int *array, size_t size, int start, int end)
{
	int pivot, top, down;

	pivot = array[end];
	for (top = start - 1, down = end + 1; top < down;)
	{
		do {
			top++;
		} while (array[top] < pivot);
		do {
			down--;
		} while (array[down] > pivot);

		if (top < down)
		{
			swap_ints(array + top, array + down);
			print_array(array, size);
		}
	}

	return (top);
}

/**
 * hoare_sort - sorts an array of integers using the Hoare pertition scheme
 * @array: pointer to the first element of array (sorted)
 * @size: number of elements in array
 * @start: starting index of the subarray to be sorted
 * @end: ending index of the subarray to be sorted
 */
void hoare_sort(int *array, size_t size, int start, int end)
{
	int pindex;

	if (end - start > 0)
	{
		pindex = hoare_partition(array, size, start, end);
		hoare_sort(array, size, start, pindex - 1);
		hoare_sort(array, size, pindex, end);
	}
}

/**
 * quick_sort_hoare - sorts an array of integer using the Quick Sort algorithm
 *						with the Hoare partition scheme
 * @array: pointer to the first element of the array (sorted)
 * @size: number of elements in array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
