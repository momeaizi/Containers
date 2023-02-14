/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:01:43 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/14 19:38:47 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iTERATOR_HPP
#define iTERATOR_HPP

#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     
// #include "iterator_traits.hpp"

namespace   ft
{
    template <class T>
    class   reverse_iterator;

}

// template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>


/* *************************************************************************** */
/*                               vector: iterator                              */
/* *************************************************************************** */
template < class T, class Category = std::random_access_iterator_tag, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class Iterator
{
    private:
        T           *m_ptr;
    public:
        typedef  Category                           iterator_category;
        typedef  T                                  value_type;
        typedef  Distance                           difference_type;
        typedef  Pointer                            pointer;
        typedef  Reference                          reference;
        typedef  Iterator                           iterator_type;

        Iterator() : m_ptr(NULL) {}
        Iterator(pointer ptr) : m_ptr(ptr) {}
        template <class _T>
        Iterator(const _T &it) : m_ptr(&(*it)) {}
        template <class _Tp>
        _Tp   &operator=(const T &it) const { m_ptr = it.m_ptr; return *this; }

        Iterator&                                   operator++() { ++m_ptr; return *this; }
        Iterator                                    operator++(int) { Iterator temp = *this; ++*this; return temp; }
        Iterator&                                   operator--() { --m_ptr; return *this; }
        Iterator                                    operator--(int) { Iterator temp = *this; --*this; return temp; }
        bool                                        operator==(const Iterator &it) const { return m_ptr == it.m_ptr; }
        bool                                        operator!=(const Iterator &it) const { return !(*this == it); }
        T&                                          operator*() const { return *m_ptr; }
        T*                                          operator->() const { return m_ptr; }
        
        Iterator                                    operator+(difference_type n) const { return Iterator(m_ptr + n); }
        Iterator                                    operator-(difference_type n) const { return Iterator(m_ptr - n); }
        difference_type                             operator-(const Iterator& it) const { return m_ptr - it.m_ptr; }
        T&                                          operator[](difference_type n) const { return *(m_ptr + n); }
        Iterator&                                   operator+=(difference_type n) { m_ptr += n; return *this; }
        Iterator&                                   operator-=(difference_type n) { m_ptr -= n; return *this; }
        bool                                        operator<(const Iterator& it) const { return m_ptr < it.m_ptr; }
        bool                                        operator>(const Iterator& it) const { return m_ptr > it.m_ptr; }
        bool                                        operator<=(const Iterator& it) const { return m_ptr <= it.m_ptr; }
        bool                                        operator>=(const Iterator& it) const { return m_ptr >= it.m_ptr; }
};

template <class T>
Iterator<T>    operator+(std::ptrdiff_t n, const Iterator<T> &it) { return it + n; }

template <class T>
Iterator<T>    operator-(std::ptrdiff_t n, const Iterator<T> &it) { return it - n; }


/* *************************************************************************** */
/*                           vector: reverse_iterator                          */
/* *************************************************************************** */
template <class Iterator>
class ft::reverse_iterator
{
    public:
        typedef  Iterator                                                          iterator_type;
        typedef  typename std::iterator_traits<Iterator>::iterator_category        iterator_category;
        typedef  typename std::iterator_traits<Iterator>::value_type               value_type;
        typedef  typename std::iterator_traits<Iterator>::difference_type          difference_type;
        typedef  typename std::iterator_traits<Iterator>::pointer                  pointer;
        typedef  typename std::iterator_traits<Iterator>::reference                reference;

        

        reverse_iterator()
            : __base_it (nullptr) {};

        explicit reverse_iterator (iterator_type it)
            : __base_it (it) {};

        reverse_iterator (const Iterator &it)
            : __base_it (it) {};

        reverse_iterator (const reverse_iterator &rev_it)
            : __base_it (rev_it.base()) {};

    
        iterator_type                               base() const { return __base_it; };
        
        reference                                   operator*() const { return *(__base_it - 1); }

        reverse_iterator                            operator+(difference_type n) const { return __base_it - n; }

        reverse_iterator&                           operator++() { --__base_it; return *this; }
        
        reverse_iterator                            operator++(int) { reverse_iterator temp = *this; --*this; return temp; }

        reverse_iterator&                           operator+=(difference_type n) { __base_it -= n; return *this; }

        reverse_iterator                            operator- (difference_type n) const { return __base_it + n; }

        reverse_iterator&                           operator--() { ++__base_it; return *this; }
        
        reverse_iterator                            operator--(int) { reverse_iterator temp = *this; ++(*this); return temp; }

        reverse_iterator&                           operator-=(difference_type n) { __base_it += n; return *this; }

        pointer                                     operator->() const { return &(*__base_it); }

        reference                                   operator[] (difference_type n) const { return *(__base_it - n); }

        private:
            iterator_type   __base_it;

};

template <class Iterator>
ft::reverse_iterator<Iterator>      operator+ (typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator>& rev_it) { return rev_it + n; }


template <class Iterator>
typename ft::reverse_iterator<Iterator>::difference_type operator- (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) { return lhs.base() + rhs.base(); }


template <class T>
class input_iterator
{
    private:
        T           *m_ptr;
    public:
        typedef  T                                  value_type;
        typedef  T&                                 reference;
        typedef  T*                                 pointer;
        typedef  std::ptrdiff_t                     difference_type;
        typedef  std::input_iterator_tag            iterator_category;

        input_iterator() : m_ptr(NULL) {}
        input_iterator(T *ptr) : m_ptr(ptr) {}
        template <class _T>
        input_iterator(const _T &it) : m_ptr(&(*it)) {}
        template <class _Tp>
        T   &operator=(const _Tp &it) const { m_ptr = it.m_ptr; return *this; }

        input_iterator&                                   operator++() { ++m_ptr; return *this; }
        input_iterator                                    operator++(int) { input_iterator temp = *this; ++*this; return temp; }
        bool                                        operator==(const input_iterator& it) const { return m_ptr == it.m_ptr; }
        bool                                        operator!=(const input_iterator& it) const { return !(*this == it); }
        T&                                          operator*() const { return *m_ptr; }
        T*                                          operator->() const { return m_ptr; }
};

#endif