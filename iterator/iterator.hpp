/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:43:07 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/15 15:43:55 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP



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
        
        template < class U, class _Category, class _Distance, class _Pointer, class _Reference>
        friend class Iterator;
        
        template <class U>
        Iterator(const Iterator<U> &it) : m_ptr(it.m_ptr) {}
        template <class U>
        Iterator<U>   &operator=(const iterator_type &it) const { m_ptr = it.m_ptr; return *this; }

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



#endif