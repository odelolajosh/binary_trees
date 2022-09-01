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

	pivot->right = tree;

	/* revalidate parents */
	pivot->parent = tree->parent;
	if (tree->parent && tree == tree->parent->left)
		tree->parent->left = pivot;
	if (tree->parent && tree == tree->parent->right)
		tree->parent->right = pivot;
	tree->parent = pivot;

	return (pivot);
}
