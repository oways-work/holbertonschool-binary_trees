#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 *
 * Description: If @tree or @func is NULL, do nothing.
 * Traversal order: Left -> Root -> Right
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* 1. Traverse the left subtree */
	binary_tree_inorder(tree->left, func);

	/* 2. Visit the root node */
	func(tree->n);

	/* 3. Traverse the right subtree */
	binary_tree_inorder(tree->right, func);
}

