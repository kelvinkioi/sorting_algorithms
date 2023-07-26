#include "sort.h"
/**
 * swap_node_ahead - swaps a node with the next node
 * @list: pointer to the head of the list
 * @tail: pointer to te tail of the list
 * @crrnt: pointer to the node to be swapped
 *
 * Return: void
 */
void swap_node_mbele(listint_t **list, listint_t **tail, listint_t **crrnt)
{
	listint_t *nnxt = (*crrnt)->next;

	if ((*crrnt)->prev != NULL)
		(*crrnt)->prev->next = nnxt;
	else
		*list = nnxt;
	nnxt->prev = (*crrnt)->prev;
	(*crrnt)->next = nnxt->next;
	if (nnxt->next != NULL)
		nnxt->next->prev = *crrnt;
	else
		*tail = *crrnt;
	(*crrnt)->prev = nnxt;
	nnxt->next = *crrnt;
	*crrnt = nnxt;
}

/**
 * swap_node_behind - swaps the node behind the current node
 * 						with the current node
 * @list: pointer to the head of the list
 * @tail: pointer to the tail of the list
 * @crrnt: pointer to the current node
 *
 * Return: void
 */
void swap_node_nyuma(listint_t **list, listint_t **tail, listint_t **crrnt)
{
	listint_t *nnxt = (*crrnt)->prev;

	if ((*crrnt)->next != NULL)
		(*crrnt)->next->prev = nnxt;
	else
		*tail = nnxt;
	nnxt->next = (*crrnt)->next;
	(*crrnt)->prev = nnxt->prev;
	if (nnxt->prev != NULL)
		nnxt->prev->next = *crrnt;
	else
		*list = *crrnt;
	(*crrnt)->next = nnxt;
	nnxt->prev = *crrnt;
	*crrnt = nnxt;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending order
 * @list: pointer to pointer to head of list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *last_unsrt, *shaker;
	bool swappped = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (last_unsrt = *list; last_unsrt->next != NULL;)
		last_unsrt = last_unsrt->next;

	while (swappped == false)
	{
		swappped = true;
		for (shaker = *list; shaker != last_unsrt; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_mbele(list, &last_unsrt, &shaker);
				print_list((const listint_t *)*list);
				swappped = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_nyuma(list, &last_unsrt, &shaker);
				print_list((const listint_t *)*list);
				swappped = false;
			}
		}
	}
}
