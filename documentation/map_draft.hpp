#include <iostream>
/*
	This document is draft for the algorithms needed to do the map
*/
class node
{
	public:
		std::string		key;
		std::string		val;
		node			*next;
		node			*prev;
}

//list search, return pointer to the node that has the key
//O(n)
node	list_search(node *linked_list, std::string key)
{
	node	tmp = linked_list->head;
	while (tmp != NULL && tmp.key != key)
	{
		tmp = tmp->next;
	}
	return (tmp);

}

//adding element to the front of the linked list , they call it list prepend
//O(n)
void	list_front_insert(node new_node, node *linked_list)
{
	new_node->next = linked_list->head;
	new_node->prev = NULL;
	if (linked_list->head != NULL)
	{
		linked_list->head->perv = new_node;
	}
	//Congrtulation the new_node had just promoted to be the head of the doubly linked list
	linked_list->head = new_node
}

//inserting in double linked list
//O(1)
void	list_insert(node new_node, node position)
{
	new_node->next = position->next;
	new_node->prev = position;
	if (position.next != NULL)
	{
		position->next->perv = new_node;
	}
	position->next = new_node
	
}

//deleting from doubly linked list
//first call list_search(linked_list, key) => to retrieve the pointer to the node to be deleted
//O(n)
//Here I know for sure that the delete_me node exists in the linked list
//O(1)
//So the total O = O(1) + O(n) = O(n)
void	list_delete(node *linked_list, node delete_me)
{
	if (delete_me->prev != NULL) // the delete_me is not the head
	{
		delete_me->prev->next = delete_me->next;
	}
	else //Here delete_me is the head
	{
		linked_list->head == delete_me->next;
	}
	if (delete_me->next != NULL) //delete_me is not the last item
	{
		delete_me->next->prev = delete_me->prev;
	}

}

							//Binary search trees\\
//list of tree operations
// SEARCH, MINIMUM, MAXIMUM, PREDECESSOR, SUCCESSOR, INSERT, and DELETE.
typedef struct tree 
{
	int		key;
	tree	*left;
	tree	*right;
	tree	*parent;
}tree;
//printing the tree sorted from smallest to largest
void	print_tree_walk(tree *binary_tree)
{
	if (binary_tree = NULL)
		print_tree_walk(binary_tree->left);
		std::cout << binary_tree.key << std::endl;
		print_tree_walk(binary_tree->right);
}

//recursive tree searcj
tree	*search_k(int k, tree *btree)
{
	if (btree == NULL || btree.key == k)
		return (btree)
	if (k < btree.key)
		return search_k(k, btree->left);
	else
		return search_k(k, btree->right)
}

//iterative search
tree	*search_k_iterative(int k, tree *btree)
{
	while (btree != NULL && btree.key != k)
	{
		if (btree.key < k)
			btree = btree->left;
		else
			btree = btree->right;

	}
	return (btree);
}

//finiding minimum
//my implementation
// tree	*find_minimum(tree *btree)
// {
// 	if (btree->left == NULL)
// 		return (btree);
// 	else
// 		return (find_minimum(btree->left));
// }

tree	*find_minimum(tree *btree)
{
	if (!btree)
		return (NULL);
	while (btree->left != NULL)
		btree = btree->left;
	return (btree);
}

//my implementation
// tree	*find_maximum(tree *btree)
//{
//	if (btree->right == NULL)
//		return (btree);
//	else
//		return (find_maximum(btree->left));
// }

tree	*find_maximum(tree *btree)
{
	if (!btree)
		return (NULL);
	while (btree->right != NULL)
		btree = btree->right;
	return (btree);
}

//insertion