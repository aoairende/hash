#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void father(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates a new_binary levelorder_queue_t node.
 * @node: The binary tree node for the new_binary node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new_binary node.
 */

levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_binary;

	new_binary = malloc(sizeof(levelorder_queue_t));
	if (new_binary == NULL)
		return (NULL);

	new_binary->node = node;
	new_binary->next = NULL;

	return (new_binary);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */

void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new_binary;

	new_binary = create_node(node);
	if (new_binary == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new_binary;
	*tail = new_binary;
}

/**
 * father - fathers the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void father(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		father(&head);
	}
	return (1);
}
