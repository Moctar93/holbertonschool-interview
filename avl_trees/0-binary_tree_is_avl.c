#include <limits.h>
#include "binary_trees.h"

/**
 * avl_check - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node
 * @min: minimum allowed value
 * @max: maximum allowed value
 *
 * Return: height of the tree, or -1 if invalid
 */
int avl_check(const binary_tree_t *tree, long min, long max)
{
	int left_height;
	int right_height;
	int balance;

	if (!tree)
		return (0);

	/* Check if the tree is a valid BST */
	if (tree->n <= min || tree->n >= max)
		return (-1);

	/* Check the left subtree */
	left_height = avl_check(tree->left, min, tree->n);
	if (left_height == -1)
		return (-1);

	/* Check the right subtree */
	right_height = avl_check(tree->right, tree->n, max);
	if (right_height == -1)
		return (-1);

	/* Check the balance factor */
	balance = left_height - right_height;

	if (balance > 1 || balance < -1)
		return (-1);

	/* Return the height */
	if (left_height > right_height)
		return (left_height + 1);

	return (right_height + 1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (avl_check(tree, LONG_MIN, LONG_MAX) != -1);
}
