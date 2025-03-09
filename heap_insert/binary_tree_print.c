#include <stdio.h>
#include "binary_trees.h"

/**
 * print_level - Print each level of the tree
 * @tree: The current node to print
 * @level: The current level to print
 * @indent: The current indentation (number of spaces)
 */
void print_level(const binary_tree_t *tree, int level, int indent)
{
    if (!tree)
        return;

    if (level == 0)
    {
        for (int i = 0; i < indent; i++)
            printf("  ");
        printf("(%d)", tree->n);
    }
    else
    {
        print_level(tree->left, level - 1, indent + 2);
        print_level(tree->right, level - 1, indent + 2);
    }
}

/**
 * binary_tree_print - Print the entire binary tree
 * @tree: The root node of the tree
 */
void binary_tree_print(const binary_tree_t *tree)
{
    if (!tree)
        return;

    int height = binary_tree_height(tree);
    for (int level = 0; level <= height; level++)
    {
        print_level(tree, level, 0);
        printf("\n");
    }
}

/**
 * binary_tree_height - Measure the height of the binary tree
 * @tree: The root node of the tree
 * Return: The height of the tree
 */
int binary_tree_height(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    int left_height = binary_tree_height(tree->left);
    int right_height = binary_tree_height(tree->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

