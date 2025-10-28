#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 *
 * @parent: Pointer to the node to insert the left-child in
 * @value: The value to store in the new node
 *
 * Return: Pointer to the created node,
 * or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Check if parent is NULL */
	if (parent == NULL)
		return (NULL);

	/* Create the new node */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL); /* Malloc failed */

	/* Check if parent already has a left-child */
	if (parent->left != NULL)
	{
		/* The new node takes the place of the old left-child */
		new_node->left = parent->left;
		/* The old left-child's parent is now the new node */
		parent->left->parent = new_node;
	}

	/* Set the new node as the parent's left-child */
	parent->left = new_node;

	return (new_node);
}
