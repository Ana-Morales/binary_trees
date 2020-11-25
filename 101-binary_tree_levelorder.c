#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: the height of a binary tree. 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	height_left = binary_tree_height(tree->left) + 1;
	height_right = binary_tree_height(tree->right) + 1;
	if (height_left > height_right)
		return (height_left);
	return (height_right);
}
/**
 * binary_tree_levelorder_print - prints a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @i: height of the nodes to print
 * @func:pointer to a function to call for each node. The value in the node
 * must be passed as a parameter to this function.
 */
void binary_tree_levelorder_print(
	const binary_tree_t *tree, size_t i, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (i == 0)
		func(tree->n);
	else if (i > 0)
	{
		binary_tree_levelorder_print(tree->left, i - 1, func);
		binary_tree_levelorder_print(tree->right, i - 1, func);
	}
}
/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node. The value in the node
 * must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = 0, i = 0;

	height = binary_tree_height(tree);
	while (i <= height)
	{
		binary_tree_levelorder_print(tree, i, func);
		i++;
	}
}
