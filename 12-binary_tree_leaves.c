#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree:  a pointer to the root node of the tree to count the number of leaves
 * Return: the count of trees. 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int count = 0;

	if (!tree)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	count += binary_tree_leaves(tree->left);
	count += binary_tree_leaves(tree->right);

	return (count);
}
