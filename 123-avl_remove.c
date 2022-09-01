#include "binary_trees.h"

/**
 * avl_retrace2 - check each of the node's ancestors for consistency
 * with the invariants of AVL trees
 * @root: a pointer to the root node of the tree
 * @node: a pointer to the node to retrace from
 * Return: a pointer to the new root
 */
avl_t *avl_retrace2(avl_t *root, avl_t *node)
{
	int factor; /* balance factor */

	if (!node)
		return (NULL);

	factor = binary_tree_balance(node);
	switch (factor)
	{
		case +2:
			if (binary_tree_balance(node->left) >= 0)
				node = binary_tree_rotate_right(node); /* RR rotation */
			else
			{ /* LR rotation */
				binary_tree_rotate_left(node->left);
				node = binary_tree_rotate_right(node);
			}
			break;
		case -2:
			if (binary_tree_balance(node->right) <= 0)
				node = binary_tree_rotate_left(node); /* LL rotation */
			else
			{ /* RL rotation */
				binary_tree_rotate_right(node->right);
				node = binary_tree_rotate_left(node);
			}
			break;
	}

	if (node->parent == NULL)
		return (root = node);

	return (avl_retrace2(root, node->parent));
}

/**
 * remove_node_with_one_child - remove a node with one child for a bst
 * @root: a pointer to the root node of the tree where you will remove a node
 * @node: a pointer to the node to remove
 * Return: a pointer to the new root node of the tree
 * after removing. the desired value
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

	root = avl_retrace2(root, replace);
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

	replace = node->right;
	while (replace->left)
		replace = replace->left;

	if (replace != node->right)
	{
		if (replace->parent && replace == replace->parent->left)
		replace->parent->left = NULL;
		if (replace->parent && replace == replace->parent->right)
			replace->parent->right = NULL;
	}

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

	root = avl_retrace2(root, replace);
	free(node);
	return (root);
}

/**
 * avl_remove - removes a node from a AVL
 * @root: a pointer to the root node of the tree where
 * you will remove a node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree after
 * removing the desired value
 */
avl_t *avl_remove(avl_t *root, int value)
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
		else
			root = avl_retrace2(root, node->parent);

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
