#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 *
 * Description: If @tree or @func is NULL, do nothing.
 * Traversal order: Left -> Right -> Root
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* 1. Traverse the left subtree */
	binary_tree_postorder(tree->left, func);

	/* 2. Traverse the right subtree */
	binary_tree_postorder(tree->right, func);

	/* 3. Visit the root node */
	func(tree->n);
}
