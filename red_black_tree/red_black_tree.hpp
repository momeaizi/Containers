/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:52:21 by momeaizi          #+#    #+#             */
/*   Updated: 2023/03/03 11:58:15 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <iostream>
#include <string>
#include "../iterator/IteratorTree.hpp"
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
                Alloc               __pair_alloc;
    
    
                Node(value_type val, Node *nil) : color (red), p (nil), left (nil), right (nil)
                {
                    value = __pair_alloc.allocate(1);

                    __pair_alloc.construct(value, val);
                }
                ~Node ()
                {
                    __pair_alloc.destroy(value);
                    __pair_alloc.deallocate(value, 1);
                }
        };
        typedef Compare                                         key_compare;
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
        redBlackTree() : __size (0)
        {
            nil = __allocator.allocate(1);
            __allocator.construct(nil, value_type(), nullptr);
            nil->color = black;
            __root = nil;
        }
        redBlackTree(const redBlackTree &x) : __size (x.__size)
        {
            nil = __allocator.allocate(1);
            __allocator.construct(nil, value_type(), nullptr);
            nil->color = black;
            __root = nil;
            __root = cloneBinaryTree(x, x.__root, nil);
        }
        redBlackTree    &operator= (const redBlackTree &x)
        {
            clear(__root);
            __root = cloneBinaryTree(x, x.__root, nil);
            __size = x.__size;
            return *this;
        }
        ~redBlackTree()
        {
            clear(__root);
            deleteNode(nil);
        }
        void                    insert(value_type val);
        void                    transplant(Node *u, Node *v);
        void                    erase(Node *z);
        void                    erase_fixup(Node *x);
        void                    deleteNode(Node *z)
        {
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
            if (root == nil)
                return nil;
            while (root->left != nil) root = root->left;
            return root;
        }
        Node                    *findMax(Node *root) const
        {
            if (root == nil)
                return nil;
            while (root->right != nil) root = root->right;
            return root;
        }
        Node                    *find(key_type   key) const
        {
            Node    *p = __root;

            while (p != nil)
            {
                if (p->value->first == key)
                    return p;
                else if (cmp(key, p->value->first))
                    p = p->left;
                else
                    p = p->right;
            }
            return nil;
        }
        void                    clear()
        {
            clear(__root);
            __size = 0;
            __root = nil;
        }
        bool                    empty() const { return !__size; }
        void                    print();
        iterator                begin()
        {
            return iterator(findMin(__root), nil, __root);
        }
        const_iterator          begin() const
        {
            return const_iterator(findMin(__root), nil, __root);
        }
        reverse_iterator        rbegin()
        {
            return reverse_iterator(end());
        }
        const_reverse_iterator  rbegin() const
        {
            return const_reverse_iterator(end());
        }
        iterator                end()
        {
            return iterator(nil, nil, __root);
        }
        const_iterator          end() const
        {
            return iterator(nil, nil, __root);
        }
        reverse_iterator        rend()
        {
            return reverse_iterator(begin());
        }
        const_reverse_iterator  rend() const
        {
            return const_reverse_iterator(begin());
        }
        size_type               max_size() const
        {
            return __allocator.max_size();
        }
        Node                    *lower_bound (const key_type &key) const
        {
            Node    *p = __root;
            Node    *result = nullptr;

            while (p != nil)
            {
                if (key == p->value->first)
                    return p;
                else if (cmp(key, p->value->first))
                {
                    result = p;
                    p = p->left;
                }
                else
                    p = p->right;
            }
            return result;
        }
        Node                    *upper_bound (const key_type &key) const
        {
            Node    *p = __root;
            Node    *result = nullptr;

            while (p != nil)
            {
                if (cmp(key, p->value->first))
                {
                    result = p;
                    p = p->left;
                }
                else
                    p = p->right;
            }
            return result;
        }
        void                    swap (redBlackTree &x)
        {
            std::swap(__root, x.__root);
            std::swap(nil, x.nil);
            std::swap(__size, x.__size);
        }
        Node            *nil;
    private:
        Node            *__root;
        allocator_type  __allocator;
        size_type       __size;
        key_compare     cmp;


        void    print(const std::string& prefix, const Node* node, bool isLeft);
        Node    *createNode(value_type val)
        {
            Node    *node = __allocator.allocate(1);

            __allocator.construct(node, val, nil);
            
            return node;
        }
        void    leftRotate(Node *x);
        void    rightRotate(Node *y);
        void    insert_fixup(Node *z);
        void    clear(Node *root)
        {
            if(root == nil)
                return ;

            clear(root->left);
            clear(root->right);

            deleteNode(root);
        }
        Node    *cloneBinaryTree(const redBlackTree &x, Node *root, Node *p)
        {
            if (root == x.nil)
                return nil;
        
            Node* root_copy = createNode(*(root->value));
            root_copy->color = root->color;
            root_copy->p = p;
        
            root_copy->left = cloneBinaryTree(x, root->left, root_copy);
            root_copy->right = cloneBinaryTree(x, root->right, root_copy);

            return root_copy;
        } 
};

template < class Key, class T, class Compare, class Alloc>
void    redBlackTree< Key, T, Compare, Alloc>::print(const std::string& prefix, const Node* node, bool isLeft)
{
    if( node != nil )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        if (node->color == red)
            std::cout << "\033[31m";
        std::cout << "(" << node->value->first << ")" << std::endl;

        // enter the next tree level - left and right branch
        std::cout << "\033[0m";
        print( prefix + (isLeft ? "│   " : "    "), node->left, true);
        print( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

template < class Key, class T, class Compare, class Alloc>
void    redBlackTree< Key, T, Compare, Alloc>::print()
{
    print("", __root, false);    
}

template < class Key, class T, class Compare, class Alloc>
void    redBlackTree< Key, T, Compare, Alloc>::leftRotate(Node *x)
{
    if (x->right == nil)
        return ;

    Node    *y = x->right;

    x->right = y->left;
    if (y->left != nil)
        y->left->p = x;

    y->p = x->p;

    if (x->p == nil)
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
    if (y->left == nil)
        return ;

    Node    *x = y->left;

    y->left = x->right;
    if (x->right != nil)
        x->right->p = y;

    x->p = y->p;

    if (y->p == nil)
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
    Node    *y = nil;
    Node    *x = __root;
    Node    *z = createNode(val);

    while (x != nil)
    {
        y = x;
        if (cmp(z->value->first, x->value->first))
            x = x->left;
        else x = x->right;
    }

    z->p = y;
    
    if (y == nil)
        __root = z;
    else if (cmp(z->value->first, y->value->first))
        y->left = z;
    else y->right = z;

    ++__size;

    insert_fixup(z);
}

template < class Key, class T, class Compare, class Alloc>
void    redBlackTree< Key, T, Compare, Alloc>::insert_fixup(Node *z)
{
    Node    *y;

    while (z->p->color == red)
    {
        if (z->p == z->p->p->left)
        {
            y = z->p->p->right;

            if (y->color == red)
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

            if (y->color == red)
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
    if (u->p == nil)
        __root = v;
    else if (u == u->p->left)
        u->p->left = v;
    else
        u->p->right = v;

    v->p = u->p;
}

template < class Key, class T, class Compare, class Alloc>
void    redBlackTree< Key, T, Compare, Alloc>::erase(Node *z)
{
    Node    *x;
    Node    *y = z;
    Color   y_original_color = y->color;

    if (z->left == nil)
    {
        x = z->right;
        transplant(z, z->right);
    }
    else if (z->right == nil)
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
    --__size;
    if (y_original_color == black)
        erase_fixup(x);
    print();
    exit(1);
}

template < class Key, class T, class Compare, class Alloc>
void    redBlackTree< Key, T, Compare, Alloc>::erase_fixup(Node *x)
{
    while (x != __root && x->color == black)
    {
        if (x == x->p->left)
        {
            Node    *w = x->p->right;

            if (w->color == red)
            {
                w->color = black;
                x->p->color = red;
                leftRotate(x->p);
                w = x->p->right;
            }
            if (w->left->color == black && w->right->color == black)
            {
                w->color = red;
                x = x->p;
            }
            else
            {
                if (w->right->color == black)
                {
                    w->left->color = black;
                    w->color = red;
                    rightRotate(w);
                    w = x->p->right;
                }
                w->color = x->p->color;
                x->p->color = black;
                w->right->color = black;
                leftRotate(x->p);
                x = __root;
            }
        }
        else
        {
            Node    *w = x->p->left;

            if (w->color == red)
            {
                w->color = black;
                x->p->color = red;
                rightRotate(x->p);
                w = x->p->left;
            }
            if (w->left->color == black && w->right->color == black)
            {
                w->color = red;
                x = x->p;
            }
            else
            {
                if (w->left->color == black)
                {
                    w->right->color = black;
                    w->color = red;
                    leftRotate(w);
                    w = x->p->left;
                }
                w->color = x->p->color;
                x->p->color = black;
                w->left->color = black;
                rightRotate(x->p);
                x = __root;
            }
        }
    }
    __root->color = black;
}
#endif

