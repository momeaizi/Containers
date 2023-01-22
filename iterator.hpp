/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:01:43 by momeaizi          #+#    #+#             */
/*   Updated: 2023/01/22 23:06:01 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP



// template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>


/* *************************************************************************** */
/*                               vector: Iterator                              */
/* *************************************************************************** */
template <class T>
class Iterator
{
    private:
        T           *m_ptr;
    public:
        typedef  T                                  value_type;
        typedef  T&                                 reference;
        typedef  T*                                 pointer;
        typedef  std::ptrdiff_t                     difference_type;
        typedef  std::random_access_iterator_tag    iterator_category;

        Iterator() : m_ptr(nullptr) {}
        Iterator(T *ptr) : m_ptr(ptr) {}
        Iterator(const Iterator &it) : m_ptr(it.m_ptr) {}
        T   &operator=(const Iterator &it) const { m_ptr = it.m_ptr; return *this; }

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
/*                           vector: Reverse_Iterator                          */
/* *************************************************************************** */
template <class T>
class Reverse_iterator
{
    private:
        T       *m_ptr;

    public:
        typedef  T                                  value_type;
        typedef  T&                                 reference;
        typedef  T*                                 pointer;
        typedef  std::ptrdiff_t                     difference_type;
        typedef  std::random_access_iterator_tag    iterator_category;
    
        Reverse_iterator(T *ptr) : m_ptr(ptr) {}
    
        T&                                          operator*() const { return *m_ptr; }
        T*                                          operator->() const { return m_ptr; }
        Reverse_iterator&                           operator++() { --m_ptr; return *this; }
        Reverse_iterator                            operator++(int) { Reverse_iterator temp = *this; --*this; return temp; }
        Reverse_iterator&                           operator--() { ++m_ptr; return *this; }
        Reverse_iterator                            operator--(int) { Reverse_iterator temp = *this; ++*this; return temp; }
        bool                                        operator==(const Reverse_iterator& it) const { return m_ptr == it.m_ptr; }
        bool                                        operator!=(const Reverse_iterator& it) const { return !(*this == it); }
        Reverse_iterator                            operator+(difference_type n) const { return Reverse_iterator(m_ptr - n); }
        Reverse_iterator                            operator-(difference_type n) const { return Reverse_iterator(m_ptr + n); }
        difference_type                             operator-(const Reverse_iterator& it) const { return m_ptr + it.m_ptr; }
        T&                                          operator[](difference_type n) const { return *(m_ptr + n); }
        Reverse_iterator&                           operator+=(difference_type n) { m_ptr -= n; return *this; }
        Reverse_iterator&                           operator-=(difference_type n) { m_ptr += n; return *this; }
        bool                                        operator<(const Reverse_iterator& it) const { return m_ptr < it.m_ptr; }
        bool                                        operator>(const Reverse_iterator& it) const { return m_ptr > it.m_ptr; }
        bool                                        operator<=(const Reverse_iterator& it) const { return m_ptr <= it.m_ptr; }
        bool                                        operator>=(const Reverse_iterator& it) const { return m_ptr >= it.m_ptr; }

};

template <class T>
Reverse_iterator<T>    operator+(std::ptrdiff_t n, const Reverse_iterator<T> &it) { return it + n; }

template <class T>
Reverse_iterator<T>    operator-(std::ptrdiff_t n, const Reverse_iterator<T> &it) { return it - n; }


#endif