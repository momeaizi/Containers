/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:43:39 by momeaizi          #+#    #+#             */
/*   Updated: 2023/01/14 18:52:51 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include "iterator.hpp"
#include "iterator_traits.hpp"

template <class T>
class vector
{
    typedef T                                           value_type;
    typedef std::allocator<T>                           allocator_type;
    typedef T&                                          reference;
    typedef const T&                                    const_reference;
    typedef T*                                          pointer;
    typedef const T*                                    const_pointer;
    typedef Iterator<T>                                 iterator;
    typedef Iterator<const T>                           const_iterator;
    typedef Reverse_iterator<T>                         reverse_iterator;
    typedef Reverse_iterator<const T>                   const_reverse_iterator;
    typedef std::ptrdiff_t                              difference_type;
    typedef std::size_t                                 size_type;

    private:
        T               *__data;
        size_type       __size;
        size_type       __capacity;
        allocator_type  __allocator;
    public:

        /* *************************************************************************** */
        /*                                 constructors                                */
        /* *************************************************************************** */
        explicit vector() : __size(0), __capacity (1)
        {
            __data = __allocator.allocate(1);
        }
        
        explicit vector (size_type n, const value_type& val = value_type()) : __size(n), __capacity (n)
        {
            __data = __allocator.allocate(__capacity);
            for (size_type i = 0; i < __size; i++)
                __allocator.construct(__data + i, val);
        }

        template <class InputIterator>
        vector (InputIterator first, InputIterator last) : __size(last - first), __capacity (__size)
        {
            __data = __allocator.allocate(__capacity);
            for (size_type i = 0; i < __size; ++i)
                __allocator.construct(__data + i, *(first + i));
        }

        vector (const vector& x) : __size(x.__size), __capacity (x.__capacity)
        {
            __data = __allocator.allocate(__capacity);
            for (size_type i = 0; i < __size; i++)
                __allocator.construct(__data + i, x.__data[i]);
        }

        
        iterator                                            begin() { return iterator(__data); }
        iterator                                            end() { return iterator(__data + __size); }
        reverse_iterator                                    rend() { return reverse_iterator(__data); }
        reverse_iterator                                    rbegin() { return reverse_iterator(__data + __size - 1); }
        size_type                                           size() const { return __size; }
        size_type                                           capacity() const { return __capacity; }
        bool                                                empty() const {__size == 0; }
        allocator_type                                      get_allocator() const { return __allocator; }
        size_type                                           max_size() const;
        void                                                clear()
        {
            for (size_type i = 0; i < __size; i++)
                __allocator.destroy(__data + i);
            __size = 0;
        }
        
        void                                                reserve (size_type n)
        {
            if (n <= __capacity)
                return ;
            
            T   *data = __allocator.allocate(n);
            for (size_type i = 0; i < __size; i++)
                __allocator.construct(data + i, __data[i]);
            
            clear();
            __data = data;
            __capacity = n;
        }
        
        void                                                resize (size_type n, value_type val = value_type())
        {
            if (n < __size)
            {
                for (size_type i = n; i < __size; i++)
                    __allocator.destroy(__data + i);
                __size = n;
            }
            else if (n > __size)
            {
                if (n > (__capacity * 2))
                    reserve(n);
                else
                    reserve(__capacity * 2);
                for (size_type i = __size; i < n; i++)
                    __allocator.construct(__data + i, val);
                    
            }
        }
        reference                                           back() { return __data[__size - 1]; }
        const_reference                                     back() const { return __data[__size - 1]; }
    
};



#endif