#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree. If tree is NULL, return 0.
 */
static size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h;
	size_t right_h;

	if (tree == NULL)
		return (0);

	/* Recursively find the height of the left and right subtrees */
	/* If a child is NULL, its height is 0 */
	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);

	/* The height of the current node is 1 + the max of its children's heights */
	if (left_h > right_h)
		return (1 + left_h);
	else
		return (1 + right_h);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: The balance factor. If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (0);

	/*
	 * Get the height of the left and right subtrees.
	 * The height function returns 0 for a NULL node,
	 * 1 for a leaf node, and so on.
	 */
	left_height = (int)binary_tree_height(tree->left);
	right_height = (int)binary_tree_height(tree->right);

	/* Balance factor is left height minus right height */
	return (left_height - right_height);
}
