#include "binary_trees.h"

/**
 * bst_insert_impl - inserts a value in a BSt recursively
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert_impl(bst_t **tree, int value)
{
	if (value == (*tree)->n)
		return (NULL);

	if (value > (*tree)->n)
	{
		if ((*tree)->right)
			return (bst_insert_impl(&((*tree)->right), value));
		(*tree)->right = binary_tree_node(*tree, value);
		return ((*tree)->right);
	}

	if ((*tree)->left)
		return (bst_insert_impl(&((*tree)->left), value));
	(*tree)->left = binary_tree_node(*tree, value);
	return ((*tree)->left);
}

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	return (bst_insert_impl(tree, value));
}
