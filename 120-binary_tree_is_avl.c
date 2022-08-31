#include "binary_trees.h"
#include "limits.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height of tree on success, otherwise 0
 */
int binary_tree_height2(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (-1);

	left = binary_tree_height2(tree->left);
	right = binary_tree_height2(tree->right);

	return ((left > right ? left : right) + 1);
}

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
 * binary_tree_is_bst - checks if a binary tree is a valid BST Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);	

	return (binary_tree_is_bst_impl(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height of tree on success, otherwise 0
 */
size_t binary_tree_is_balanced(const binary_tree_t *tree)
{
	int balance;

	if (!tree)
		return (1);

	balance = binary_tree_height2(tree->left) - binary_tree_height2(tree->right);
	if (balance < 0)
		balance *= -1;
	
	if (balance > 1)
		return (0);
	
	return (binary_tree_is_balanced(tree->left)
		&& binary_tree_is_balanced(tree->right));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_is_bst(tree) && binary_tree_is_balanced(tree));
}
