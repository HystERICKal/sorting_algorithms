#include "sort.h"

/**
 * node_interchanger - interchange two nodes
 * @the_list: the list
 * @node_one: node one
 * @node_two: node two
 * Return: void
 */
void node_interchanger(listint_t **the_list,
		listint_t *node_one, listint_t *node_two)
{
	listint_t *the_prev;
	listint_t *the_next;

	if (node_one == NULL || node_two == NULL)
		return;

	the_prev = node_one->prev;
	the_next = node_two->next;

	if (the_prev)
		the_prev->next = node_two;

	if (the_next)
		the_next->prev = node_one;

	node_one->next = the_next;
	node_one->prev = node_two;
	node_two->next = node_one;
	node_two->prev = the_prev;

	if (the_prev == NULL)
		*the_list = node_two;
}

/**
 * insertion_sort_list - the insertion sort algorithm
 * @list: the list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *before_this;
	listint_t *this_one;

	if (list == NULL || (*list)->next == NULL)
		return;

	for (this_one = *list; this_one; this_one = this_one->next)
	{
		before_this = this_one->prev;
		while (before_this && before_this->n > this_one->n)
		{
			node_interchanger(list, before_this, this_one);
			print_list(*list);
			before_this = this_one->prev;
		}
	}
}
