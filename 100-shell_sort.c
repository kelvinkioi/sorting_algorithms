#include "sort.h"

#include "sort.h"
/**
 * swap - swaps two integers
 * @a: integer a
 * @b: integer b
 **/

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * insert_back - swaps two elemnts from the right position
 * to the left position
 * @array: array of elements
 * @gap: interval between elements
 * @pos: position in the arrray
 */
void insert_back(int *array, int gap, int pos)
{
	int i;

	for (i = pos - gap; i >= 0; i -= gap, pos -= gap)
	{
		if (array[i] > array[pos])
			swap(&array[i], &array[pos]);
		else
			break;
	}
}

/**
 * shell_sort - function that sorts an array of integers in
 * ascending order using the Shell sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, i, j;

	if (!array)
		return;
	if (size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = 0, j = gap; j < size; i++, j++)
		{
			if (array[i] > array[j])
			{
				swap(&array[i], &array[j]);
				insert_back(array, gap, i);
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
