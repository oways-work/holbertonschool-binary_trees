#include "binary_trees.h"

/**
 * get_height_for_balance - Measures height of a binary tree for balance check.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree. If tree is NULL, return 0.
 * Note: This is a static helper for binary_tree_balance
 */
static size_t get_height_for_balance(const binary_tree_t *tree)
{
	size_t left_h;
	size_t right_h;

	/* A NULL node has a height of 0 for balance calculation */
	if (tree == NULL)
		return (0);

	/* Recursively find the height of the left and right subtrees */
	/* We add 1 to the recursive call to count the current level */
	left_h = get_height_for_balance(tree->left);
	right_h = get_height_for_balance(tree->right);

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
	 * The height function returns size_t (unsigned), so we cast to int
	 * for the subtraction, as the balance factor can be negative.
	 */
	left_height = (int)get_height_for_balance(tree->left);
	right_height = (int)get_height_for_balance(tree->right);

	return (left_height - right_height);
}
