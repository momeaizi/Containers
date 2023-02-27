/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:52:21 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/27 13:42:49 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <iostream>
#include <string>
#include "IteratorTree.hpp"
#include "../iterator/reverse_iterator.hpp"
#include "../utils/pair.hpp"

enum    Color
{
    red,
    black
};

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class   redBlackTree
{
    public:
        typedef Key                                             key_type;
        typedef T                                               mapped_type;
        typedef ft::pair<const key_type, mapped_type>           value_type;
        struct   Node
        {
            public:
                Color               color;
                value_type          *value;
                Node                *p;
                Node                *left;
                Node                *right;
    
    
                Node(value_type *val) : value (val), p (nullptr), left (nullptr), right (nullptr) {
                    
                }
        };
        typedef Compare                                         key_compare;
        // typedef Compare                                         value_compare;
        typedef typename Alloc::template rebind<Node>::other    allocator_type;
        typedef typename allocator_type::reference              reference;
        typedef typename allocator_type::const_reference        const_reference;
        typedef typename allocator_type::pointer                pointer;
        typedef typename allocator_type::const_pointer          const_pointer;
        typedef IteratorTree<Node, value_type>                  iterator;
        typedef IteratorTree<const Node, value_type>            const_iterator;
        typedef ft::reverse_iterator<iterator>                  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
        typedef std::ptrdiff_t                                  difference_type;
        typedef std::size_t                                     size_type;
    

    public:
        redBlackTree() : __root (nullptr), __size (0) {}
        redBlackTree(const redBlackTree &x) : __root (nullptr), __size (x.__size)
        {
            __root = cloneBinaryTree(x.__root, nullptr);
        }
        redBlackTree    &operator= (const redBlackTree &x)
        {
            clear(__root);
            __root = cloneBinaryTree(x.__root, nullptr);
            __size = x.__size;
            return *this;
        }
        ~redBlackTree()
        {
            clear(__root);
        }
        void                    insert(value_type val);
        void                    transplant(Node *u, Node *v);
        void                    erase(Node *z);
        void                    deleteNode(Node *z)
        {
            __pair_alloc.destroy(z->value);
            __pair_alloc.deallocate(z->value, 1);
            __allocator.destroy(z);
            __allocator.deallocate(z, 1);
        }
        size_type               size() const
        {
            return __size;
        }
        Node                    *root() const
        {
            return __root;
        }
        Node                    *findMin(Node *root) const
        {
            if (!root)
                return nullptr;
            while (root->left) root = root->left;
            return root;
        }
        Node                    *findMax(Node *root) const
        {
            if (!root)
                return nullptr;
            while (root->right) root = root->right;
            return root;
        }
        Node                    *find(key_type   key) const
        {
            Node    *p = __root;

            while (p)
            {
                if (p->value->first == key)
                    return p;
                else if (cmp(key, p->value->first))
                    p = p->left;
                else
                    p = p->right;
            }
            return nullptr;
        }
        void                    clear()
        {
            clear(__root);
            __size = 0;
            __root = nullptr;
        }
        bool                    empty() const { return !__size; }
        void                    printBT();
        iterator                begin()
        {
            return iterator(findMin(__root), __root);
        }
        const_iterator          begin() const
        {
            return const_iterator(findMin(__root), __root);
        }
        reverse_iterator        rbegin()
        {
            return reverse_iterator(--end());
        }
        const_reverse_iterator  rbegin() const
        {
            return const_reverse_iterator(--end());
        }
        iterator                end()
        {
            return iterator(nullptr, __root);
        }
        const_iterator          end() const
        {
            return iterator(nullptr, __root);
        }
        reverse_iterator        rend()
        {
            return reverse_iterator(--begin());
        }
        const_reverse_iterator  rend() const
        {
            return const_reverse_iterator(--begin());
        }
    
    private:
        Node            *__root;
        allocator_type  __allocator;
        Alloc           __pair_alloc;
        size_type       __size;
        key_compare     cmp;


        void    printBT(const std::string& prefix, const Node* node, bool isLeft);
        Node    *createNode(value_type val)
        {
            Node    *node = __allocator.allocate(1);
            value_type       *pair = __pair_alloc.allocate(1);

            __pair_alloc.construct(pair, val);
            __allocator.construct(node,pair);
            
            return node;
        }
        void    leftRotate(Node *x);
        void    rightRotate(Node *y);
        void    insert_fixup(Node *z);
        void    clear(Node *root)
        {
            if(!root)
                return ;

            clear(root->left);
            clear(root->right);

            deleteNode(root);
        }
        Node    *cloneBinaryTree(Node *root, Node *p)
        {
            if (!root)
                return nullptr;
        
            Node* root_copy = createNode(*(root->value));
            root_copy->color = root->color;
            root_copy->p = p;
        
            root_copy->left = cloneBinaryTree(root->left, root_copy);
            root_copy->right = cloneBinaryTree(root->right, root_copy);

            return root_copy;
        } 
};

template < class Key, class T, class Compare, class Alloc>
void    redBlackTree< Key, T, Compare, Alloc>::printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        if (node->color == red)
            std::cout << "\033[31m";
        std::cout << "(" << node->value->first << ")" << std::endl;

        // enter the next tree level - left and right branch
        std::cout << "\033[0m";
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

template < class Key, class T, class Compare, class Alloc>
void    redBlackTree< Key, T, Compare, Alloc>::printBT()
{
    printBT("", __root, false);    
}

template < class Key, class T, class Compare, class Alloc>
void    redBlackTree< Key, T, Compare, Alloc>::leftRotate(Node *x)
{
//        |      x         |                     |      y       |
//        |     / \        |                     |     / \      |
//        |    a   y       |      -------- >     |    x   c     |
//        |       / \      |      -------- >     |   / \        |
//        |      b   c     |                     |  a   b       |
//        |                |                     |              |
    if (!x->right)
        return ;

    Node    *y = x->right;

    x->right = y->left;
    if (y->left)
        y->left->p = x;

    y->p = x->p;

    if (!x->p)
        __root = y;
    else if (x == x->p->left)
        x->p->left = y;
    else
        x->p->right = y;

    y->left = x;
    x->p = y;
}

template < class Key, class T, class Compare, class Alloc>
void    redBlackTree< Key, T, Compare, Alloc>::rightRotate(Node *y)
{
//       |      y       |                      |      x         |
//       |     / \      |                      |     / \        |
//       |    x   c     |       -------- >     |    a   y       |
//       |   / \        |       -------- >     |       / \      |
//       |  a   b       |                      |      b   c     |
//       |              |                      |                |
    if (!y->left)
        return ;

    Node    *x = y->left;

    y->left = x->right;
    if (x->right)
        x->right->p = y;

    x->p = y->p;

    if (!y->p)
        __root = x;
    else if (y == y->p->right)
        y->p->right = x;
    else
        y->p->left = x;

    x->right = y;
    y->p = x;
}


template < class Key, class T, class Compare, class Alloc>
void    redBlackTree< Key, T, Compare, Alloc>::insert(value_type val)
{
    Node    *y = nullptr;
    Node    *x = __root;
    Node    *z = createNode(val);

    while (x)
    {
        y = x;
        if (cmp(z->value->first, x->value->first))
            x = x->left;
        else x = x->right;
    }

    z->p = y;
    
    if (!y)
        __root = z;
    else if (cmp(z->value->first, y->value->first))
        y->left = z;
    else y->right = z;

    z->left = nullptr;
    z->right = nullptr;
    z->color = red;
    ++__size;

    insert_fixup(z);
}

template < class Key, class T, class Compare, class Alloc>
void    redBlackTree< Key, T, Compare, Alloc>::insert_fixup(Node *z)
{
    Node    *y;

    while (z->p && z->p->p && z->p->color == red)
    {
        if (z->p == z->p->p->left)
        {
            y = z->p->p->right;

            if (y && y->color == red)
            {
                z->p->color = black;
                y->color = black;
                z->p->p->color = red;
                z = z->p->p;
            }
            else
            {
                if (z == z->p->right)
                {
                    z = z->p;
                    leftRotate(z);
                }
                z->p->color = black;
                z->p->p->color = red;
                rightRotate(z->p->p);
            }
        }
        else
        {
            y = z->p->p->left;

            if (y && y->color == red)
            {
                z->p->color = black;
                y->color = black;
                z->p->p->color = red;
                z = z->p->p;
            }
            else
            {
                if (z == z->p->left)
                {
                    z = z->p;
                    rightRotate(z);
                }
                z->p->color = black;
                z->p->p->color = red;
                leftRotate(z->p->p);
            }
        }
    }
    __root->color = black;
}


template < class Key, class T, class Compare, class Alloc>
void    redBlackTree< Key, T, Compare, Alloc>::transplant(Node *u, Node *v)
{
    if (!u)
        return ;


    if (!u->p)
        __root = v;
    else if (u == u->p->left)
        u->p->left = v;
    else
        u->p->right = v;

    if (v)
        v->p = u->p;
}

template < class Key, class T, class Compare, class Alloc>
void    redBlackTree< Key, T, Compare, Alloc>::erase(Node *z)
{
    Node    *y = z;
    Node    *x;
    Color   y_original_color = y->color;

    if (!z->left)
    {
        x = z->right;
        transplant(z, z->right);
    }
    else if (!z->right)
    {
        x = z->left;
        transplant(z, z->left);
    }
    else
    {
        y = findMin(z->right);
        y_original_color = y->color;
        x = y->right;

        if (y->p == z)
            x->p = y;
        else
        {
            transplant(y, y->right);
            y->right = z->right;
            y->right->p = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->p = y;
        y->color = z->color;
    }

    deleteNode(z);
    // if (y_original_color == black)
    //     delete_fixup(x);
}

#endif