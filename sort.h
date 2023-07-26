#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * enum bool - enumaration of boolean values
 *
 * @false: Equals 0
 * @true: Equal 1
 */
typedef enum bool
{
	false = 0, true = 1
} bool;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
/*advanced */
void swap(int *a, int *b);
void insert_back(int *array, int gap, int pos);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);
void merge_sort_rr(int *array, int *tmp_buffer, size_t mbele, size_t nyuma);
void radix_sort(int *array, size_t size);

#endif /*SORT_H*/

