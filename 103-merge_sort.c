#include "sort.h"
/**
 * merge_sort - sorts an array of integers in
 *					ascending order using merge sort
 * @array: pointer to the first element of the array to be sorted
 * @size: number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp_buffer;

	if (array == NULL || size < 2)
		return;

	tmp_buffer = malloc(sizeof(int) * size);
	if (tmp_buffer == NULL)
		return;

	merge_sort_rr(array, tmp_buffer, 0, size);
	free(tmp_buffer);
}

/**
 * merge_sort_rr - sorts a subarray of integers in ascending order
 *							using merge sort recursively
 * @array: pointer to the first element of the array to be sorted
 * @tmp_buffer: temporary buffer used during merging
 * @mbele: starting index of the current subarray
 * @nyuma: ending index of the current subarray
 */
void merge_sort_rr(int *array, int *tmp_buffer, size_t mbele, size_t nyuma)
{
	size_t mid, index, jndex, kndex = 0;

	if (nyuma - mbele > 1)
	{
		mid = mbele + (nyuma - mbele) / 2;
		merge_sort_rr(array, tmp_buffer, mbele, mid);
		merge_sort_rr(array, tmp_buffer, mid, nyuma);

		printf("Merging...\n[left]: ");
		print_array(array + mbele, mid - mbele);

		printf("[right]: ");
		print_array(array + mid, nyuma - mid);

		for (index = mbele, jndex = mid; index < mid && jndex < nyuma; kndex++)
			tmp_buffer[kndex] = (array[index] < array[jndex]) ?
				array[index++] : array[jndex++];
		for (; index < mid; index++)
			tmp_buffer[kndex++] = array[index];
		for (; jndex < nyuma; jndex++)
			tmp_buffer[kndex++] = array[jndex];
		for (index = mbele, kndex = 0; index < nyuma; index++)
			array[index] = tmp_buffer[kndex++];

		printf("[Done]: ");
		print_array(array + mbele, nyuma - mbele);
	}
}
