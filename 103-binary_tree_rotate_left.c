#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree || tree->right == NULL)
		return (tree);

	pivot = tree->right;

	tree->right = pivot->left;
	if (tree->right)
		tree->right->parent = tree;
	tree->parent = pivot;

	pivot->left = tree;
	pivot->parent = NULL;

	return (pivot);
}
