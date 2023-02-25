/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:50:50 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/25 23:01:39 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TREE_HPP
#define ITERATOR_TREE_HPP

template < class T, class Value_type>
class IteratorTree
{
    private:
        T           *m_ptr;
    public:
        typedef  std::bidirectional_iterator_tag    iterator_category;
        typedef  Value_type                         value_type;
        typedef  T*                                 pointer;
        typedef  T&                                 reference;
        typedef  IteratorTree                       iterator_type;



        IteratorTree() : m_ptr(NULL) {}
        IteratorTree(pointer ptr) : m_ptr(ptr) {}
        
        template < class U, class val>
        friend class IteratorTree;
        
        template <class U, class val>
        IteratorTree(const IteratorTree<U, val> &it) : m_ptr(it.m_ptr) {}
        template <class U, class val>
        IteratorTree<U, val>   &operator=(const iterator_type &it) const { m_ptr = it.m_ptr; return *this; }

        IteratorTree&                                   operator++();
        IteratorTree                                    operator++(int);
        IteratorTree&                                   operator--();
        IteratorTree                                    operator--(int);
        value_type&                                     operator*() const;
        value_type*                                     operator->() const;

        template < class _T, class _U, class val>
        friend bool                                        operator==(const IteratorTree<_T, val> &lhs, const IteratorTree<_U, val> &rhs) { return lhs.m_ptr == rhs.m_ptr; }
        template < class _T, class _U, class val>
        friend bool                                        operator!=(const IteratorTree<_T, val> &lhs, const IteratorTree<_U, val> &rhs) { return !(lhs == rhs); }

        private:
            pointer findMin(pointer node);
            pointer findMax(pointer node);
};


template < class T, class val>
typename IteratorTree<T, val>::pointer IteratorTree<T, val>::findMin(pointer node)
{
    pointer current = node;
 

    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

template < class T, class val>
typename IteratorTree<T, val>::pointer IteratorTree<T, val>::findMax(pointer node)
{
    pointer current = node;
 

    while (current->right != NULL) {
        current = current->right;
    }
    return current;
}


template < class T, class val>
IteratorTree<T, val>&    IteratorTree<T, val>::operator++()
{
    if (!m_ptr)
        return *this;


    if (m_ptr->right)
    {
        m_ptr = findMin(m_ptr->right);
        return *this;
    }

    pointer p = m_ptr->p;
    while (p && m_ptr == p->right)
    {
        m_ptr = p;
        p = p->p;
    }
    m_ptr = p;
    return *this;
}

template < class T, class val>
IteratorTree<T, val>     IteratorTree<T, val>::operator++(int) { IteratorTree temp = *this; ++*this; return temp; }

template < class T, class val>
IteratorTree<T, val>&    IteratorTree<T, val>::operator--()
{
    if (!m_ptr)
        return *this;


    if (m_ptr->left)
    {
        m_ptr = findMax(m_ptr->left);
        return *this;
    }


    pointer p = m_ptr->p;
    while (p && m_ptr == p->left)
    {
        m_ptr = p;
        p = p->p;
    }
    m_ptr = p;

    return *this;
}

template < class T, class val>
IteratorTree<T, val>     IteratorTree<T, val>::operator--(int) { IteratorTree temp = *this; --*this; return temp; }

template < class T, class val>
typename IteratorTree<T, val>::value_type                  &IteratorTree<T, val>::operator*() const { return m_ptr->value; }

template < class T, class val>
typename IteratorTree<T, val>::value_type                  *IteratorTree<T, val>::operator->() const { return &(m_ptr->value); }


#endif