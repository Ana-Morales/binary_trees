#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: the depth of a node in a binary tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL || tree->parent == NULL)
		return (0);
	depth = binary_tree_depth(tree->parent) + 1;
	return (depth);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first,
	const binary_tree_t *second)
{
	size_t depth_f = 0, depth_s = 0;
	int dif = 0;

	if (first == NULL || second == NULL)
		return (NULL);
	depth_f = binary_tree_depth(first);
	depth_s = binary_tree_depth(second);
	if (depth_f > depth_s)
	{
		dif = depth_f - depth_s;
		while (dif > 0)
		{
			first = first->parent;
			dif--;
		}
	}
	else if (depth_s > depth_f)
	{
		dif = depth_s - depth_f;
		while (dif > 0)
		{
			second = second->parent;
			dif--;
		}
	}
	if (first == second)
		return ((binary_tree_t *)first);
	while (first)
	{
		if (first->parent == second->parent)
			return (first->parent);
		first = first->parent;
		second = second->parent;
	}
	return (NULL);
}
