#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer to the head of the list
 * @number: the number to insert into the list
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node, *current;

    // Step 1: Allocate memory for the new node
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = number;

    // Step 2: Insert the node at the beginning if the list is empty or the number is smaller than the head
    if (*head == NULL || (*head)->n >= number)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    // Step 3: Traverse the list to find the insertion point
    current = *head;
    while (current->next != NULL && current->next->n < number)
    {
        current = current->next;
    }

    // Step 4: Insert the new node after the current node
    new_node->next = current->next;
    current->next = new_node;

    return (new_node);
}

