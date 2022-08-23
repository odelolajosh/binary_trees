#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: node to check
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return (node && !(node->left) && !(node->right));
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height of tree on success, otherwise 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left = binary_tree_height(tree->left) + 1;
	if (tree->right)
		right = binary_tree_height(tree->right) + 1;

	if (left > right)
		return (left);
	return (right);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is perfect otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int h_diff;

	if (!tree)
		return (0);

	if (binary_tree_is_leaf(tree))
		return (1);

	h_diff = binary_tree_height(tree->left) - binary_tree_height(tree->right);

	if (h_diff < -1 || h_diff > 1) /* must have a balance factor of atleast 1 */
		return (0);

	if (tree->right && !(tree->left)) /* have a right without left? */
		return (0);

	return (binary_tree_is_complete(tree->left) &&
		binary_tree_is_complete(tree->right));
}
