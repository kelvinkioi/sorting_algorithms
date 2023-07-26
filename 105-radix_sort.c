#include "sort.h"
/**
 * get_max - finds the maximum element in an array of integers
 * @array: pointer to the first element of array
 * @size: number of elements in array
 *
 * Return: maximum integer in the array
 */
int get_max(int *array, int size)
{
	int maxi, i;

	for (maxi = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maxi)
			maxi = array[i];
	}

	return (maxi);
}

/**
 * radix_counting_sort - sorts an array of integers in ascending order using
 *							Radix Counting Sort algorithm
 * @array: pointer to the first element of the array to be sorted
 * @size: number of elements in the array
 * @sdigit: current significant digit for sorting
 * @buff: temporary buffer used for sorting
 */
void radix_counting_sort(int *array, size_t size, int sdigit, int *buff)
{
	int cnt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		cnt[(array[i] / sdigit) % 10] += 1;

	for (i = 0; i < 10; i++)
		cnt[i] += cnt[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[cnt[(array[i] / sdigit) % 10] - 1] = array[i];
		cnt[(array[i] / sdigit) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - sorts an array of integers in ascending order using Radix Sort
 * @array: pointer to the first element of the array to be sorted
 * @size: number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int maxi, sdigit, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	maxi = get_max(array, size);
	for (sdigit = 1; maxi / sdigit > 0; sdigit *= 10)
	{
		radix_counting_sort(array, size, sdigit, buff);
		print_array(array, size);
	}

	free(buff);
}
