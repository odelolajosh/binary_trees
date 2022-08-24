#include "binary_trees.h"

/**
 * binary_tree_rotate_right -  performs a right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree || tree->left == NULL)
		return (tree);

	pivot = tree->left;

	tree->left = pivot->right;
	if (tree->left)
		tree->left->parent = tree;
	tree->parent = pivot;

	pivot->right = tree;
	pivot->parent = NULL;

	return (pivot);
}
