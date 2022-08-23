#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the
 * two given nodes, If no common ancestor was found, returns NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	size_t d_first, d_second;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	d_first = binary_tree_depth(first);
	d_second = binary_tree_depth(second);

	if (d_first > d_second)
		return (binary_trees_ancestor(first->parent, second));

	if (d_second > d_first)
		return (binary_trees_ancestor(first, second->parent));

	return (binary_trees_ancestor(first->parent, second->parent));
}

/**
 * binary_tree_depth -  measures the depth of a node in a binary tree
 * @tree:  a pointer to the node to measure the depth
 * Return: 0 on failure, otherwise the depth of node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = -1;

	if (!tree)
		return (0);

	while (tree)
	{
		tree = tree->parent;
		depth++;
	}

	return (depth);
}
