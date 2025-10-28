#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree. If @tree is NULL, return 0.
 *
 * Description: Height is the number of edges on the longest path
 * from the node to a leaf. A leaf node has a height of 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	/*
	 * Recursively find the height of the left and right subtrees.
	 * If a child exists, its height is 1 (for the edge) + its own height.
	 */
	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	/* Return the larger of the two heights */
	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}
