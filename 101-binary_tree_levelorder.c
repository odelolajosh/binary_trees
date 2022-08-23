#include "binary_trees.h"

/**
 * binary_tree_levelorder_impl - recursion helper function for
 * binary_tree_levelorder
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node. The value in the
 * node must be passed as a parameter to this function
 * @level: level at which the func should be mapped
 */
void binary_tree_levelorder_impl(const binary_tree_t *tree, void (*func)(int),
size_t level)
{
	if (!tree || !func)
		return;

	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		binary_tree_levelorder_impl(tree->left, func, level - 1);
		binary_tree_levelorder_impl(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node. The value in the
 * node must be passed as a parameter to this function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, height = binary_tree_height(tree);

	for (level = 0; level <= height; level++)
		binary_tree_levelorder_impl(tree, func, level);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height of tree on success, otherwise 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l = binary_tree_height(tree->left) + 1;
	if (tree->right)
		r = binary_tree_height(tree->right) + 1;

	if (l > r)
		return (l);
	return (r);
}
