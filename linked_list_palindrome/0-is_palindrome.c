#include "lists.h"

/**
 * reverse_list - Reverses a linked list.
 * @head: Pointer to the head of the list.
 * Return: Pointer to the new head of the reversed list.
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL;
    listint_t *current = head;
    listint_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Pointer to the head of the linked list.
 * Return: 1 if the list is a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *second_half = NULL;
    listint_t *prev_slow = *head;
    int result = 1;

    if (*head == NULL || (*head)->next == NULL)
        return (1); // Empty list or single node is a palindrome

    // Find the middle of the linked list
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    // Handle odd-length lists
    if (fast != NULL)
    {
        slow = slow->next;
    }

    // Reverse the second half of the linked list
    second_half = reverse_list(slow);
    prev_slow->next = NULL; // Terminate the first half

    // Compare the first half and the reversed second half
    listint_t *temp1 = *head;
    listint_t *temp2 = second_half;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->n != temp2->n)
        {
            result = 0;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // Restore the linked list (optional)
    second_half = reverse_list(second_half);
    prev_slow->next = second_half;

    return result;
}
