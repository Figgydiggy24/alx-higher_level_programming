#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of the head of the list
 * Return: 0 if not a palindrome, 1 if a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head;
	listint_t *fast = *head;
	listint_t *prev_slow = NULL;
	
	int palindrome = 1;
	
	if (*head == NULL || (*head)->next == NULL)
		return 1;
	
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		listint_t *next_slow = slow->next;
		slow->next = prev_slow;
		prev_slow = slow;
		slow = next_slow;
	}
	
	if (fast != NULL)
		slow = slow->next;
	while (prev_slow != NULL && slow != NULL)
	{
		if (prev_slow->n != slow->n)
		{
			palindrome = 0;
			break;
		}
		prev_slow = prev_slow->next;
		slow = slow->next;
	}
	
	prev_slow = NULL;
	while (*head != NULL)
	{
		listint_t *next_head = (*head)->next;
		(*head)->next = prev_slow;
		prev_slow = *head;
		*head = next_head;
	}
	*head = prev_slow;
	
	return palindrome;
}
