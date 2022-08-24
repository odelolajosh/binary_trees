#include "binary_trees.h"
#include "limits.h"

/**
 * binary_tree_is_bst_impl - checks if a binary tree is a valid BST
 * @tree: a pointer to the root node of the tree to check
 * @min: minimum value range for node
 * @max: manimum value range for node
 * Return: 1 if tree is valid BST, 0 otherwise
 */
int binary_tree_is_bst_impl(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (binary_tree_is_bst_impl(tree->left, min, tree->n - 1) &&
		binary_tree_is_bst_impl(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_is_bst_impl(tree, INT_MIN, INT_MAX));
}
