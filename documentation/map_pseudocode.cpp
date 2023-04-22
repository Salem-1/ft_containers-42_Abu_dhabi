// AVL tree implementation in C++

#include <iostream>
using namespace std;

class Node {
   public:
  int key;
  Node *left;
  Node *right;
  int height;
};

int max(int a, int b);

// Calculate height
int height(Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// New node creation
Node *newNode(int key) {
  Node *node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Rotate right
Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  return x;
}

// Rotate left
Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  return y;
}

// Get the balance factor of each node
int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
       height(N->right);
}

// Insert a node
Node *insertNode(Node *node, int key) {
  // Find the correct postion and insert the node
  if (node == NULL)
    return (newNode(key));
  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (key < node->left->key) {
      return rightRotate(node);
    } else if (key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (key > node->right->key) {
      return leftRotate(node);
    } else if (key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

// Node with minimum value
Node *nodeWithMimumValue(Node *node) {
  Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// Delete a node
Node *deleteNode(Node *root, int key) {
  // Find the node and delete it
  if (root == NULL)
    return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if ((root->left == NULL) ||
      (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      Node *temp = nodeWithMimumValue(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right,
                   temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));
  int balanceFactor = getBalanceFactor(root);
  if (balanceFactor > 1) {
    if (getBalanceFactor(root->left) >= 0) {
      return rightRotate(root);
    } else {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(root->right) <= 0) {
      return leftRotate(root);
    } else {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

// Print the tree
void printTree(Node *root, string indent, bool last) {
  if (root != nullptr) {
    cout << indent;
    if (last) {
      cout << "R----";
      indent += "   ";
    } else {
      cout << "L----";
      indent += "|  ";
    }
    cout << root->key << endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
  }
}

int main() {
  Node *root = NULL;
  root = insertNode(root, 33);
  root = insertNode(root, 13);
  root = insertNode(root, 53);
  root = insertNode(root, 9);
  root = insertNode(root, 21);
  root = insertNode(root, 61);
  root = insertNode(root, 8);
  root = insertNode(root, 11);
  printTree(root, "", true);
  root = deleteNode(root, 13);
  cout << "After deleting " << endl;
  printTree(root, "", true);
}





//my old insert code 
tree	*new_node(const value_type &val)
		{
			// comp()
			//use allocator instead of new here;
			tree	*inserted = new tree;
			inserted->key_val = val;
			
			return (inserted);
		}

		tree	*right_rotate(tree *y)
		{
			tree	*x = y->left;
			tree	*T2 = x->right;

			x->right = y;
			y->left = T2;
			y->height = max_height(height(y->left), height(y->right)) + 1;
			x->height = max_height(height(x->left), height(x->right)) + 1;
			return (x);
		}
		tree	*left_rotate(tree *x)
		{
			tree	*y = x->right;
			tree	*T2 = x->left;

			y->left = x;
			x->right = T2;
			y->height = max_height(height(y->left), height(y->right)) + 1;
			x->height = max_height(height(x->left), height(x->right)) + 1;
			return (y);
		}

		int	getBalanceFactor(tree *N)
		{
			if (!N)
				return (0);
			return (height(N->left) - height(N->right));
		}
		tree	*do_insert(
			tree *node, const value_type &val)
		{
			// std::cout << "inserting " << val.first << " : " << val.second << std::endl;
			if (!node)
				return (new_node(val));
			if (val.first < node->key_val.first)
				node->left = do_insert(node->left, val);
			if (val.first > node->key_val.first)
				node->right = do_insert(node->right, val);
			else
				return (node);
			node->height = 1 + max_height(height(node->left), height(node->right));
			int balance_factor = getBalanceFactor(node);
			if (balance_factor > 1)
			{
				if (val.first < node->left->key_val.first)
					return (right_rotate(node));
				else if (val.first > node->left->key_val.first)
				{
					node->left = left_rotate(node->left);
					return (right_rotate(node));
				}
			}
			else if (balance_factor < -1)
			{
				if (val.first > node->right->key_val.first)
					return (left_rotate(node));
				else if (val.first < node->right->key_val.first)
				{
					node->right = right_rotate(node->right);
					return (left_rotate(node));
				}
			}
			return (node);
		}


//comp relational operators
/*

operation	equivalent operation
a!=b	!(a==b)
a>b	b<a
a<=b	!(b<a)
a>=b	!(a<b)

*/
		void	visualize_node(tree *y, std::string name, std::string indent)

		{
			std::cout << indent;
			std::cout << "    " << name << std::endl;
			std::cout << indent;
			if (y->parent)
				std ::cout << "    " << y->parent->key_val.first << std::endl;
			else
				std::cout << "   root" << std::endl;
			std::cout << indent;
			
			std::cout << "    ^" << std::endl;
			std::cout << indent;
			
			std::cout << "    | " << std::endl;
			std::cout << indent;
			
			std::cout << "    "<< y->key_val.first << std::endl;
			std::cout << indent;
			
			std::cout << " /    \\" << std::endl;
			std::cout << indent;
			
			if (y->left)
				std::cout  << y->left->key_val.first;
			else
				std::cout <<"(null)";
			std::cout << "      ";
			if (y->right)
				std::cout << y->right->key_val.first << std::endl;
			else
				std::cout << "(null)" << std::endl;
		}
