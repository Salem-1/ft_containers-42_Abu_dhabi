#include "../../srcs/map/map.hpp"


//rplacing one subtree as child for it's parent with another su

void    transplant(tree *root, tree *u, tree *v)
{
    if (u->parent == NULL)
    {
         root = v;
        if (_tree->parent == NULL)
            _tree = v;
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
        u->parent->right = v;
    if (v != NULL)
        v->parent = u->parent;
}

do_delete(tree *root, tree *z)
{
    if (z->left == NULL)
        transplant(root, z, z->root);
    else if (z->right == NULL)
        transplant(root, z, z->left);
    else
    {
        tree    *y = seek_left_most(z->right);
        if (y != z->right)
        {
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
}