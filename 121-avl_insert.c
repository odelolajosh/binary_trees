#include "binary_trees.h"
#include "stdio.h"

/**
 * avl_insert_impl - inserts a value in an AVL Tree
 * @tree: a double pointer to the root node of the AVL tree for
 * inserting the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the inserted node
 */
avl_t *avl_insert_impl(avl_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value > (*tree)->n)
	{
		if ((*tree)->right)
			return (avl_insert_impl(&((*tree)->right), value));
		(*tree)->right = binary_tree_node(*tree, value);
		return ((*tree)->right);
	}

	if ((*tree)->left)
		return (avl_insert_impl(&((*tree)->left), value));
	(*tree)->left = binary_tree_node(*tree, value);
	return ((*tree)->left);
}

/**
 * avl_retrace - check each of the node's ancestors for consistency
 * with the invariants of AVL trees
 * @root: a pointer to the root node of the tree
 * @node: a pointer to the node to retrace from
 * Return: a pointer to the new root
 */
avl_t *avl_retrace(avl_t **root, avl_t *node)
{
	int factor; /* balance factor */

	if (!node)
		return (NULL);

	factor = binary_tree_balance(node);
	switch (factor)
	{
		case +2:
			if (binary_tree_balance(node->left) >= 0)
				node = binary_tree_rotate_right(node); /* RR rotation */
			else
			{ /* LR rotation */
				binary_tree_rotate_left(node->left);
				node = binary_tree_rotate_right(node);
			}
			break;
		case -2:
			if (binary_tree_balance(node->right) <= 0)
				node = binary_tree_rotate_left(node); /* LL rotation */
			else
			{ /* RL rotation */
				binary_tree_rotate_right(node->right);
				node = binary_tree_rotate_left(node);
			}
			break;
	}

	if (node->parent == NULL)
		return (*root = node);

	return (avl_retrace(root, node->parent));
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: a double pointer to the root node of the AVL tree
 * for inserting the value
 * @value: the value to store in the node to be inserted
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *inserted;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	inserted = avl_insert_impl(tree, value);
	avl_retrace(tree, inserted->parent);

	return (inserted);
}
