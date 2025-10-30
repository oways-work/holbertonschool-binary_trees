#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node.
 * @node: A pointer to the node to find the uncle of.
 *
 * Return: A pointer to the uncle node.
 * If node is NULL, return NULL.
 * If node has no uncle, return NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;
	binary_tree_t *grandparent;

	/*
	 * If the node is NULL, or has no parent,
	 * or has no grandparent, then it cannot have an uncle.
	 */
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	parent = node->parent;
	grandparent = parent->parent;

	/* Check if the parent is the left child of the grandparent */
	if (grandparent->left == parent)
		return (grandparent->right); /* The uncle is the right child */

	/* Check if the parent is the right child of the grandparent */
	if (grandparent->right == parent)
		return (grandparent->left); /* The uncle is the left child */

	/* This should not be reachable in a valid tree */
	return (NULL);
}
