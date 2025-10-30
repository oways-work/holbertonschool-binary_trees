#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 *
 * Return: The number of nodes with at least one child.
 * If tree is NULL, the function must return 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_nodes;
	size_t right_nodes;

	if (tree == NULL)
		return (0);

	/* Recursively get the count from the left and right subtrees */
	left_nodes = binary_tree_nodes(tree->left);
	right_nodes = binary_tree_nodes(tree->right);

	/*
	 * If the current node has at least one child, it counts as 1,
	 * plus the counts from its children.
	 */
	if (tree->left != NULL || tree->right != NULL)
		return (1 + left_nodes + right_nodes);

	/*
	 * If the current node is a leaf (no children), it does not count.
	 * Just return the sum of its children's counts (which will be 0).
	 */
	return (left_nodes + right_nodes);
}
