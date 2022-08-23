#include "binary_trees.h"

/**
 * binary_tree_depth -  measures the depth of a node in a binary tree
 * @tree:  a pointer to the node to measure the depth
 * Return: 0 on failure, otherwise the depth of node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int d = -1;

	if (!tree)
		return (0);

	while (tree)
	{
		tree = tree->parent;
		d++;
	}

	return (d);
}
