#include "binary_trees.h"

/**
 * binary_tree_nodes -  counts the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of nodes
 * Return: 0 if tree is NULL, otherwise the count of the nodes with
 * at least 1 child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
}
