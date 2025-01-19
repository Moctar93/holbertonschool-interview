#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_print - Prints a binary tree in a human-readable format
 * @tree: Pointer to the root of the tree
 */
void binary_tree_print(const binary_tree_t *tree)
{
    if (!tree)
        return;

    printf("       .-------(%03d)-------.\n", tree->n);
    if (tree->left || tree->right)
    {
        if (tree->left)
            printf("  .--(%03d)--.\n", tree->left->n);
        else
            printf("  .--(XXX)--.\n");

        if (tree->right)
            printf("  .--(%03d)--.\n", tree->right->n);
        else
            printf("  .--(XXX)--.\n");
    }
    binary_tree_print(tree->left);
    binary_tree_print(tree->right);
}

