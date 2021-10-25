#include "sort.h"

/**
 * insertion_swap - swap nod
 * @n1: first node
 * @n2: second node
 * @head: the head
 * Return: null
 */
void insertion_swap(listint_t *n1, listint_t *n2, listint_t **head)
{
	listint_t *t1, *t2;

	if (n1 == NULL || n2 == NULL)
		return;

	t1 = n1->prev;
	t2 = n2->next;

	if (t1)
		t1->next = n2;
	if (t2)
		t2->prev = n1;
	n1->next = t2;
	n1->prev = n2;
	n2->next = n1;
	n2->prev = t1;

	if (t1 == NULL)
		*head = n2;
}


/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order using the Insertion algorithm
 * @list: Double pointer to list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *crnt, *prv;

	if (list == NULL || (*list)->next == NULL)
		return;

	crnt = *list;

	while (crnt)
	{
		prv = crnt->prev;
		while (prv && prv->n > crnt->n)
		{
			insertion_swap(prv, crnt, list);
			print_list(*list);
			prv = crnt->prev;
		}
		crnt = crnt->next;
	}
}
