#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right-child
 *                            of another in a binary tree.
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value to store in the new_binary node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new_binary node.
 *
 * Description: If parent already has a right-child, the new_binary node
 *              takes its place and the old right-child is set as
 *              the right-child of the new_binary node.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_binary;

	if (parent == NULL)
		return (NULL);

	new_binary = binary_tree_node(parent, value);
	if (new_binary == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_binary->right = parent->right;
		parent->right->parent = new_binary;
	}
	parent->right = new_binary;

	return (new_binary);
}
