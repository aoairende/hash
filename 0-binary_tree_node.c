#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: A pointer to the parent of the node to create.
 * @value: The value of the new_binary node.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new_binary node.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_binary;

	new_binary = malloc(sizeof(binary_tree_t));
	if (new_binary == NULL)
		return (NULL);

	new_binary->n = value;
	new_binary->parent = parent;
	new_binary->left = NULL;
	new_binary->right = NULL;

	return (new_binary);
}
