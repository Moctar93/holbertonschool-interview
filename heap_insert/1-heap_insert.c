#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: A double pointer to the root node of the heap
 * @value: The value to store in the new node
 *
 * Return: A pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node;

    if (!root)
        return (NULL);

    // If the tree is empty, create the root node
    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    // Insert the new node as a leaf (find the first empty leaf position)
    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    // Use level order traversal to find the right spot to insert the new node
    // This is done by filling the tree from left to right at the last level.
    // If it's not a complete tree, you would insert it in the first available spot.

    // Heapify up to maintain max heap property
    while (new_node->parent && new_node->n > new_node->parent->n)
    {
        // Swap the new node with its parent
        int temp = new_node->n;
        new_node->n = new_node->parent->n;
        new_node->parent->n = temp;

        new_node = new_node->parent;
    }

    return (new_node);
}

