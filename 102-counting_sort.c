#include "sort.h"

/**
 * counting_sort - function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: array to sort
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, max = 0;
	int *cnt = NULL;

	if (!array || size < 2)
		return;
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i] + 1;
	}
	cnt = malloc(max * sizeof(int));
	if (!cnt)
		return;
	for (i = 0; i < max; i++)
		cnt[i] = 0;
	for (i = 0; i < (int)size; i++)
		cnt[array[i]]++;
	for (i = 0; i < max; i++)
	{
		if (i + 1 < max)
			cnt[i + 1] += cnt[i];
	}
	print_array(cnt, max);
	for (i = 0; i < max; i++)
	{
		if (i && cnt[i] != cnt[i - 1])
			array[cnt[i] - 1] = i;
	}
	free(cnt);
}
