#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @root: a pointer to the root tree pointer
 * @tree: a pointer to the current parent
 * @array: a pointer to the first element of the array to be converted
 * @low: lower boundary of array range
 * @high: upper boundary of array range;
 * @left: 0 if new node should be place on the left of tree, else 1
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
void sorted_array_to_avl_impl(
	avl_t **root, avl_t *tree, int *array,
	size_t low, size_t high, int left)
{
	size_t mid = (low + high) / 2;
	avl_t *node = binary_tree_node(tree, array[mid]);

	if (!node)
		return;

	if (*root == NULL)
		*root = node;

	node->parent = tree;
	if (tree)
	{
		if (left)
			tree->left = node;
		else
			tree->right = node;
	}

	if (low < mid)
		sorted_array_to_avl_impl(root, node, array, low, mid - 1, 1);
	if (mid < high)
		sorted_array_to_avl_impl(root, node, array, mid + 1, high, 0);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (!array)
		return (NULL);

	sorted_array_to_avl_impl(&tree, tree, array, 0, size - 1, 0);
	return (tree);
}
