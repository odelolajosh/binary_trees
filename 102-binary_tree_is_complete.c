#include "binary_trees.h"

/**
 * tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the tree root
 * @i: node index
 * @count: count of nodes
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete_impl(const binary_tree_t *tree, int i, int count)
{
	if (tree == NULL)
		return (1);

	if (i >= count)
		return (0);

	return (binary_tree_is_complete_impl(tree->left, (2 * i) + 1, count) &&
		binary_tree_is_complete_impl(tree->right, (2 * i) + 2, count));
}


/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t count;

	if (tree == NULL)
		return (0);

	count = binary_tree_size(tree);

	return (binary_tree_is_complete_impl(tree, 0, count));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree root
 * Return: size of the tree or 0 if tree is NULL;
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
