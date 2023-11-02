#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of
 *                           of another in a binary tree.
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the new_binary node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new_binary node.
 *
 * Description: If parent already has a left-child, the new_binary node
 *              takes its place and the old left-child is set as
 *              the left-child of the new_binary node.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_binary;

	if (parent == NULL)
		return (NULL);

	new_binary = binary_tree_node(parent, value);
	if (new_binary == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_binary->left = parent->left;
		parent->left->parent = new_binary;
	}
	parent->left = new_binary;

	return (new_binary);
}
