/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:01:43 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/15 15:47:56 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iTERATORS_HPP
#define iTERATORS_HPP

#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     



// template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>


/* *************************************************************************** */
/*                               vector: iterator                              */
/* *************************************************************************** */



/* *************************************************************************** */
/*                           vector: reverse_iterator                          */
/* *************************************************************************** */








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
        bool                                              operator==(const input_iterator& it) const { return m_ptr == it.m_ptr; }
        bool                                              operator!=(const input_iterator& it) const { return !(*this == it); }
        T&                                                operator*() const { return *m_ptr; }
        T*                                                operator->() const { return m_ptr; }
};

#endif