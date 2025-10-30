#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* Per prompt, a NULL tree is not considered full */
	if (tree == NULL)
		return (0);

	/* Case 1: This is a leaf node (0 children). This is full. */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Case 2: This node has 2 children. */
	if (tree->left != NULL && tree->right != NULL)
	{
		/*
		 * It's only full if *both* its left and right subtrees
		 * are also full. We check this recursively.
		 */
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
	}

	/*
	 * Case 3: This node has only 1 child (either left or right is NULL,
	 * but not both). This is not a full tree.
	 */
	return (0);
}
