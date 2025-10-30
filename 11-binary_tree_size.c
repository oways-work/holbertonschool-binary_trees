#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the tree. If tree is NULL, the function must return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_left = 0;
	size_t size_right = 0;

	if (tree == NULL)
		return (0);

	/*
	 * Recursively find the size of the left and right subtrees.
	 * The size of the current tree is 1 (for the current node)
	 * plus the size of its left child tree and its right child tree.
	 */
	size_left = binary_tree_size(tree->left);
	size_right = binary_tree_size(tree->right);

	return (1 + size_left + size_right);
}
