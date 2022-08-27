#include "binary_trees.h"

/**
 * bst_min_node - find the minimum node in a given BST
 * @tree: a pointer to the root node of the tree where you will find min node
 * Return: a pointer to the min value node on success, NULL otherwise
 */
bst_t *bst_min_node(bst_t *tree)
{
	if (!tree)
		return (NULL);

	if (!(tree->left) && !(tree->right))
		return (tree);

	if (tree->left == NULL)
		return (tree);
	return (bst_min_node(tree->left));
}

/**
 * remove_node_with_one_child - remove a node with one child for a bst
 * @root: a pointer to the root node of the tree where you will remove a node
 * @node: a pointer to the node to remove
 * Return: a pointer to the new root node of the tree
 * after removing the desired value
 */
bst_t *remove_node_with_one_child(bst_t *root, bst_t *node)
{
	bst_t *replace;

	if (!node)
		return (root);

	if (node->right && node->left == NULL)
		replace = node->right;
	else if (node->left && node->right == NULL)
		replace = node->left;

	replace->parent = node->parent;
	if (node->parent && node == node->parent->left)
		node->parent->left = replace;
	if (node->parent && node == node->parent->right)
		node->parent->right = replace;
	if (root == node)
		root = replace;

	free(node);
	return (root);
}

/**
 * remove_node_with_two_children - remove a full node for a bst
 * @root: a pointer to the root node of the tree where you will remove a node
 * @node: a pointer to the node to remove
 * Return: a pointer to the new root node of the tree
 * after removing the desired value
 */
bst_t *remove_node_with_two_children(bst_t *root, bst_t *node)
{
	bst_t *replace;

	replace = bst_min_node(node->right);

	if (replace->parent && replace == replace->parent->left)
		replace->parent->left = NULL;

	if (replace->parent && replace == replace->parent->right)
		replace->parent->right = NULL;

	replace->parent = node->parent;
	if (replace != node->left)
	{
		replace->left = node->left;
		if (node->left)
			node->left->parent = replace;
	}

	if (replace != node->right)
	{
		replace->right = node->right;
		if (node->right)
			node->right->parent = replace;
	}

	if (node->parent && node == node->parent->left)
		node->parent->left = replace;
	if (node->parent && node == node->parent->right)
		node->parent->right = replace;

	if (root == node)
		root = replace;

	free(node);
	return (root);
}

/*
 * - find the targetted node

 * Case 0: node with no children
 * - clean removal
 *
 * Case 1: node with one child
 * - connect the child to the parent
 *
 * Case 2: node with two children:
 * - find min in right
 * - replace min with targetted node
 * - wipe targetted node from memory
 */

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree where
 * you will remove a node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree after
 * removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;

	node = bst_search(root, value);
	if (!node)
		return (root);

	if (!(node->left) && !(node->right))
	{
		if (node == node->parent->left)
			node->parent->left = NULL;
		if (node == node->parent->right)
			node->parent->right = NULL;
		if (node == root)
			root = NULL;
		free(node);
		return (root);
	}

	if ((node->right && !(node->left)) || (node->left && !(node->right)))
		root = remove_node_with_one_child(root, node); /* one child */
	else /* 2 children */
		root = remove_node_with_two_children(root, node);

	return (root);
}

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: a pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree && value < tree->n)
		return (bst_search(tree->left, value));

	if (tree && value > tree->n)
		return (bst_search(tree->right, value));

	return ((bst_t *)tree);
}
