#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node1: first node to swap
 * @node2: second node to swap
 *
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2) {
    if (node1->prev)
        node1->prev->next = node2;
    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;

    if (!node2->prev)
        *list = node2;
}

/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order
 * @list: pointer to the head of the list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list) {
    listint_t *crnt, *nxt_node;

    if (!list || !*list || !(*list)->next)
        return;

    crnt = (*list)->next;

    while (crnt) {
        nxt_node = crnt->next;

        while (crnt->prev && crnt->n < crnt->prev->n) {
            swap_nodes(list, crnt->prev, crnt);
            print_list(*list);
        }

        crnt = nxt_node;
    }
}
