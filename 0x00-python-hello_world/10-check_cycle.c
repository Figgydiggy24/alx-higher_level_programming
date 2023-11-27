#include "lists.h"

/**
 * chech_cycle = will check if a singly-linked list contains a cycle.
 * @list: this is a singly linked list
 *
 * Return: 0 if there is no cycle and 1 if a cycle does exist
 */

int check_cycle(listint_t *list)
{
	listint_t *temp = list;

	if (list == NULL)
		return (0);

	do
	{
		if (temp->next == NULL)
			return (0);
		temp = temp->next;
	}while (temp != list);

	return (1);
}
