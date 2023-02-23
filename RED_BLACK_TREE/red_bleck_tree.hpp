/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_bleck_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:52:21 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/23 11:10:54 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <iostream>
#include <string>




enum    Color
{
    red,
    black
};

template <typename T, typename U>
class   redBlackTree
{
    typedef T       key_type;
    typedef U       value_type;
    typedef size_t  size_type;
    

    class   Node
    {
        public:
            Color       color;
            key_type    key;
            value_type  value;
            Node        *p;
            Node        *left;
            Node        *right;


            Node(key_type key, value_type value) : key (key), value (value) {}
    };
    

    public:
        redBlackTree() : __root (nullptr) {}

        void    insert(Node *z);
        void    printBT(const std::string& prefix, const Node* node, bool isLeft);
        void    printBT();

        Node    *createNode(key_type key, value_type val)
        {
            return new Node (key, val);
        }



        
    private:
        Node        *__root;
        size_type   __size;

        void    leftRotate(Node *x);
        void    rightRotate(Node *y);
        void    insert_fixup(Node *z);
};

template <typename T, typename U>
void    redBlackTree<T, U>::printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        if (node->color == red)
            std::cout << "\033[31m";
        std::cout << "(" << node->key << ")" ;
        std::cout << "(" << node->color << ")" << std::endl;

        // enter the next tree level - left and right branch
        std::cout << "\033[0m";
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

template <typename T, typename U>
void    redBlackTree<T, U>::printBT()
{
    printBT("", __root, false);    
}

template <typename T, typename U>
void    redBlackTree<T, U>::leftRotate(Node *x)
{
//        |      x         |                     |      y       |
//        |     / \        |                     |     / \      |
//        |    a   y       |      -------- >     |    x   c     |
//        |       / \      |      -------- >     |   / \        |
//        |      b   c     |                     |  a   b       |
//        |                |                     |              |
    Node    *y = x->right;

    x->right = y->left;
    if (y->left)
        y->left->p = x;
    if (!x->p)
        __root = y;
    else if (x == x->p->left)
        x->p->left = y;
    else
        x->p->right = y;

    y->left = x;
    x->p = y;
}

template <typename T, typename U>
void    redBlackTree<T, U>::rightRotate(Node *y)
{
//       |      y       |                      |      x         |
//       |     / \      |                      |     / \        |
//       |    x   c     |       -------- >     |    a   y       |
//       |   / \        |       -------- >     |       / \      |
//       |  a   b       |                      |      b   c     |
//       |              |                      |                |
    Node    *x = y->left;

    y->left = x->right;
    if (x->right)
        x->right->p = y;
    if (!y->p)
        __root = x;
    else if (y == y->p->left)
        y->p->left = x;
    else
        y->p->right = x;

    x->right = y;
    y->p = x;
}


template <typename T, typename U>
void    redBlackTree<T, U>::insert(Node *z)
{
    Node    *y = nullptr;
    Node    *x = __root;

    while (x)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else x = x->right;
    }

    z->p = y;
    
    if (!y)
        __root = z;
    else if (z->key < y->key)
        y->left = z;
    else y->right = z;

    z->left = nullptr;
    z->right = nullptr;
    z->color = red;

    insert_fixup(z);
}

#endif