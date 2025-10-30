#include "binary_trees.h"

/**
 * get_tree_height - Measures the height of a binary tree for perfect check.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree. If tree is NULL, return 0.
 * Note: This is a static helper for binary_tree_is_perfect
 */
static size_t get_tree_height(const binary_tree_t *tree)
{
	size_t left_h;
	size_t right_h;

	/* A NULL node has a height of 0 */
	if (tree == NULL)
		return (0);

	/* Recursively find the height of the left and right subtrees */
	left_h = get_tree_height(tree->left);
	right_h = get_tree_height(tree->right);

	/* The height of the current node is 1 + the max of its children's heights */
	if (left_h > right_h)
		return (1 + left_h);
	else
		return (1 + right_h);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_h;
	size_t right_h;

	/* Per the prompt, a NULL tree is not perfect */
	if (tree == NULL)
		return (0);

	/* Get the height of the left and right subtrees using the helper */
	left_h = get_tree_height(tree->left);
	right_h = get_tree_height(tree->right);

	/*
	 * Case 1: This is a leaf node.
	 * Its children (NULL) have equal heights (0).
	 * It is perfect by definition.
	 */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/*
	 * Case 2: This is an internal node.
	 * For the tree to be perfect, the left and right subtrees
	 * must have the exact same height, AND both subtrees
	 * must also be perfect.
	 */
	if (left_h == right_h)
	{
		return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));
	}

	/*
	 * Case 3: The subtrees have different heights.
	 * This tree cannot be perfect.
	 */
	return (0);
}

