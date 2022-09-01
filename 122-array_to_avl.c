#include "binary_trees.h"

/**
 * array_to_bst - builds a AVL Tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: a pointer to the root node of the created BST, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
