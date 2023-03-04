/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:50:50 by momeaizi          #+#    #+#             */
/*   Updated: 2023/03/04 18:32:19 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TREE_HPP
#define ITERATOR_TREE_HPP

template < class T, class Value_type>
class IteratorTree
{
    public:
        typedef  Value_type                         value_type;
        typedef  value_type*                        pointer;
        typedef  value_type&                        reference;
        typedef  IteratorTree                       iterator_type;
        typedef  std::bidirectional_iterator_tag    iterator_category;
        typedef  std::ptrdiff_t                     difference_type;




        IteratorTree() : m_ptr (NULL), nil (nullptr), max (nullptr) {}
        IteratorTree(T *ptr, T *nil = nullptr, T *max = nullptr) : m_ptr (ptr), nil (nil), max (max) {}
        
        template < class U, class val>
        friend class IteratorTree;
        
        template <class U, class val>
        IteratorTree(const IteratorTree<U, val> &it) : m_ptr (it.m_ptr), nil (it.nil), max (it.max) {}
        template <class U, class val>
        IteratorTree<U, val>   &operator=(const iterator_type &it) const
        {
            m_ptr = it.m_ptr;
            nil = it.nil;
            max = it.max;
            return *this;
        }

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
            T *m_ptr;
            T *nil;
            T *max;
            T *findMin(T *node) const;
            T *findMax(T *node) const;
};


template < class T, class val>
T   *IteratorTree<T, val>::findMin(T *node) const
{
    if (node == nil)
        return nullptr;
    T   *current = node;
 

    while (current->left != nil) {
        current = current->left;
    }
    return current;
}

template < class T, class val>
T    *IteratorTree<T, val>::findMax(T *node) const
{
    if (node == nil)
        return nullptr;
    T   *current = node;
 

    while (current->right != nil) {
        current = current->right;
    }
    return current;
}


template < class T, class val>
IteratorTree<T, val>&    IteratorTree<T, val>::operator++()
{

    if (m_ptr->right != nil)
    {
        m_ptr = findMin(m_ptr->right);
        return *this;
    }

    T   *p = m_ptr->p;
    while (p != nil && m_ptr == p->right)
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
    if (m_ptr == nil)
    {
        m_ptr = max;
        return *this;
    }


    if (m_ptr->left != nil)
    {
        m_ptr = findMax(m_ptr->left);
        return *this;
    }


    T   *p = m_ptr->p;
    while (p != nil && m_ptr == p->left)
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
typename IteratorTree<T, val>::value_type                  &IteratorTree<T, val>::operator*() const { return *(m_ptr->value); }

template < class T, class val>
typename IteratorTree<T, val>::value_type                  *IteratorTree<T, val>::operator->() const { return &(operator*()) ; }


#endif
