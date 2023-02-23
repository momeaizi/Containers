/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_bleck_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:52:21 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/22 11:54:00 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <iostream>
#include <string>

//


void printBT(const std::string& prefix, const BSTNode* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->m_val << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->m_left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->m_right, false);
    }
}

void printBT(const BSTNode* node)
{
    printBT("", node, false);    
}



//
enum    Color
{
    red,
    black
};

template <typename T, typename U>
class   RB_tree
{
    typedef T       key_type;
    typedef U       value_type;
    typedef size_t  size_type;
    

    class   Node
    {
        public:
            key_type    key;
            value_type  value;
            Color       color;
            Node        *parent;
            Node        *left;
            Node        *rightt;


            Node(key_type key, value_type value) : key (key), value (value) {}
    };
    

    public:
        RB_tree() : __root (nullptr) {}

        void    insert(Node *z);



        
    public:
        Node        *__root;
        size_type   __size;

        void    leftRotate(Node *x);
        void    rightRotate(Node *y);
        void    insert_fixup(Node *z);
        
};



template <typename T, typename U>
void    RB_tree<T, U>::leftRotate(Node *x)
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
void    RB_tree<T, U>::rightRotate(Node *y)
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
void    RB_tree<T, U>::insert(Node *z)
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

template <typename T, typename U>
void    RB_tree<T, U>::insert_fixup(Node *z)
{
    Node    *y;

    while (z.p.color == red)
    {
        if (z.p = z.p.p.left)
        {
            y = z.p.p.right;

            if (y.color == red)
            {
                z.p.color = black;
                y.color = black;
                z.p.p.color = red;
                z = z.p.p;
            }
            else if (z == z.p.right)
            {
                z = z.p;
                leftRotate(z);
                z.p.color = black;
                z.p.p.color = red;
                rightRotate(z.p.p);
            }
            else
            {
                z = z.p;
                rightRotate(z);
                z.p.color = black;
                z.p.p.color = red;
                leftRotate(z.p.p);
            }
        }
        else
        {}
    }
}

#endif