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
//assume that the node is fill with key with the left and right = NULL

void	insert_in_tree(tree **T, tree *node)
{
	tree	*tmp = T.root; //tmp = root
	tree	*node_parent;
	//find location to insert node in
	while (tmp != NULL)
	{
		node_parent = tmp;
		if (node.key < tmp.key)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	node.parent = node_parent;
	if (node_parent != NULL)
		T.root = node;      // the tree was empty
	else if (node.key < node_parent.key)
		node_parent->left = node;
	else
		node_parent->right = node;
}

// transplantation
void	transplant(tree **T, old, tree *new_node)
{
	tree *root = *T;

	if (old.parent == NULL) //old is the root of the tree
		T.root = new_node; 
	else if (old == old.parent->left) //old is the left child of it's parent
		old.parent->left = new_node;
	else  //old is left child of it's parent
		old.parent->right = new_node;
	if (new_node != NULL)
		new_node.parent = old.parent;
}
//transplant is not responsible for updating new_node left and right


//deleting node 😑
void	tree_delete(tree **T, tree *delete_me)
{
	//delete_me has no left child
	if (delete_me->left == NULL)
		Transplant(T, delete_me, delete_me->right);
	//delete_me has no right child
	else if (delete_me->right == NULL)
		Transplant(T, delete_me, delete_me->left);
	else
	{//delete me has 2 children
		tree *successor = tree_minimum(delete_me->right);
		if (successor != delete_me->right)
		{
			//replase successor with it's right child
			transplant(T, successor, successor->right);
			//delete_me right child becomes successor right child
			succcessor->right = delete_me->right;
			succcessor->right.parent = successor;
			//replace delete_me by it's successor
			transplant(T, delete_me, successor);
			successor->left = delete_me->left;
			succcessor->left.parent = successor;
		}
	}
}

enum	Color
{
	red,
	black;
};
struct	red_black_tree
{
	int				key;
	Color			color;
	red_black_tree	*left;
	red_black_tree	*right;
	red_black_tree	*parent;
}

//root and NULL leaves are black
//if node is red it's children are black
//for each node all simple pathes to nodes below have same number of black

//rotate left

void	left-rotate(T, x)
{
	y = x.right;
	x.right = y.left
	if (y.left != NULL)
		y.left.parent = x;
	y.parent = x.parent;
	if (x.parent == T.nill) //if x was root, change the root to be y
		T.root = y;
	else if (x == x.parent.left) //x was the left child
		x.parent.left = y; //change the parent of y to be x's parent
	else	//other wise x was the right child to it's parent
		x.parent.right = y;
	y.left = x;
	x.parent = y;
}
//the right rotate is unverified
// void	right-rotate(T, y)
// {
// 	x = y.left;
// 	y.left = x.right
// 	if (x.right != NULL)
// 		x.right.parent = y;
// 	x.parent = y.parent;
// 	if (y.parent == T.nill) //if y was root, change the root to be x
// 		T.root = x;
// 	else if (y == y.parent.right) //y was the right child
// 		y.parent.right = x; //change the parent of x to be y's parent
// 	else	//other wise y was the left child to it's parent
// 		y.parent.left = x;
// 	x.right = y;
// 	y.parent = x;
// }
void	right-rotate(T, y);
//note that all instance of NULL, replaced with T.nill
//insert in redblack tree

//fixing up the red black tree
void	red_black_insert_fixup(T, z)
{
	while (z.parent.color == red)
	{
		if (z.parent == z.parent.parent.left)
		{
			y = z.parent.parent.right;
			if (y.color == red)
			{
				z.parent.color = black;
				y.color = black;
				z.parent.parent.color = red;
				z = z.parent.parent;
			}
			else
			{
				if (z == z.p.right)
				{
					z = z.p;
					left_rotate(T,z);
				}
				z.parent.color = black;
				z.parent.parent.color = red;
				right_rotate(T, z.parent.parent);
			}
		}
		else
		{
			y = z.parent.parent.left;
			if (y.color == red)
			{
				z.parent.color = black;
				y.color = black;
				z.parent.parent.color = red;
				z = z.parent.parent;
			}
			else
			{
				if (z == z.parent.left)
				{
					z = z.parent;
					right_rotate(T, z);
				}
				z.parent.color = black;
				z.parent.parent.color = red;
				left_rotate(t, z.parent.parent);
			}
		}
	}
	T.root.color = black;
}
void	red_black_insert(T, z)
{
	x = T.root //first node to compare with z
	y = T.nill //y is the parent of z
	while (x != T.nill)
	{
		y = x;
		//shearching where to insert z
		if (z.key < x.key)
			x = x.left;
		else
			x = x.right;
	}
	z.parent = y; //found location to insert z with parent y
	if (y == T.nill)
		T.root = z; //the tree was empty
	else if (z.key < y.key)
		y.left = z;
	else
		y.right = z;
	z.left = T.nill; //T.nill ensure maintaining healthy tree structure
	z.right = T.nill;
	z.color = red;  //the new node start red
	red_black_insert_fixup(T, Z); //correct any violation in the redblack tree
}
