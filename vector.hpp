/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:43:39 by momeaizi          #+#    #+#             */
/*   Updated: 2023/01/18 22:19:31 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <stdexcept>
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

        void    __reserve(size_type n)
        {
            T   *data = __allocator.allocate(n);


            for (size_type i = __size; i < n; i++)
                __allocator.construct(data + i);
            for (size_type i = 0; i < __size; i++)
                __allocator.construct(data + i, __data[i]);
            clear();
            __allocator.deallocate(__data, __capacity);
            __data = data;
            __size = n;
            __capacity = n;
        }

    public:

        /* *************************************************************************** */
        /*                                 constructors                                */
        /* *************************************************************************** */
        explicit vector () : __size(0), __capacity (0)
        {
            __data = nullptr;
        }
        
        explicit vector (size_type n) : __size(n), __capacity (n)
        {
            __data = __allocator.allocate(__capacity);
            for (size_type i = 0; i < __size; i++)
                __allocator.construct(__data + i);
        }
        
        explicit vector (size_type n, const value_type& val) : __size(n), __capacity (n)
        {
            __data = __allocator.allocate(__capacity);
            for (size_type i = 0; i < __size; i++)
                __allocator.construct(__data + i, val);
        }

        template <class InputIterator>
        vector (InputIterator first, InputIterator last) : __size(last - first), __capacity (__size)
        {
            if (first > last)
                throw std::length_error("vector");

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

        ~vector ()
        {
            clear();
            if (__capacity)
                __allocator.deallocate(__data, __capacity);
        }
        

        void    __assign_at_begin (size_type __n, const value_type &val)
        {
            for (size_type i = 0; i < __n; i++)
                    __data[i] = val;
        }
        
        void    __destruct_at_end (size_type __n)
        {
            for (size_type i = __n; i < __size; i++)
                __allocator.destroy(__data + i);
        }
        
        void    __construct_at_end (size_type __first, size_type __last, const value_type &val)
        {
            for (size_type i = __first; i < __last; i++)
                    __allocator.construct(__data + i, val);
        }
        
        void    assign (size_type n, const value_type &val)
        {
            if (n <= __capacity)
            {
                size_type   min = std::min(n, __size);
                
                __assign_at_begin(min, val);
                __construct_at_end(min, n, val);
                __destruct_at_end(n);
            }
            else
            {
                __destruct_at_end(0);
                __allocator.deallocate(__data, __capacity);
                __data = __allocator.allocate(n);
                __construct_at_end(0, n, val);

                __capacity = n;
            }
            __size = n;
            
        }
        
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last)
        {
            if (first > last)
            {
                clear();
                __allocator.deallocate(__data, __capacity);
                __capacity = 0;
                throw std::length_error("vector");
            }

            size_type   n = last - first;

            if (n <= __capacity)
            {
                size_type   min = std::min(n, __size);
        
                for (size_type i = 0; i < min; i++)
                    __data[i] = *(first + i);    
                for (size_type i = min; i < n; i++)
                    __allocator.construct(__data + i, *(first + i));
                __destruct_at_end(n);
                __size = n;
            }
            else
            {
                __destruct_at_end(0);
                __allocator.deallocate(__data, __capacity);
                __data = __allocator.allocate(n);
                __capacity = n;
                for (size_type i = 0; i < n; i++)
                    __allocator.construct(__data + i, *(first + i));       
            }
            __size = n;
        }
        
        iterator                                            begin () { return iterator(__data); }
        iterator                                            end () { return iterator(__data + __size); }
        reverse_iterator                                    rend () { return reverse_iterator(__data); }
        reverse_iterator                                    rbegin () { return reverse_iterator(__data + __size - 1); }
        reference                                           back () { return __data[__size - 1]; }
        const_reference                                     back () const { return __data[__size - 1]; }
        size_type                                           size () const { return __size; }
        size_type                                           capacity () const { return __capacity; }
        bool                                                empty () const {__size == 0; }
        allocator_type                                      get_allocator () const { return __allocator; }
        size_type                                           max_size () const;

        reference operator[] (size_type n) { return __data[n]; }
        const_reference operator[] (size_type n) const { return __data[n]; }
        
        reference at (size_type n)
        {
            if (n >= __size)
                throw std::out_of_range("vector");
            return __data[n];
        }
        const_reference at (size_type n) const
        {
            if (n >= __size)
                throw std::out_of_range("vector");
            return __data[n];
        }

        

        
        void    clear ()
        {
            for (size_type i = 0; i < __size; i++)
                __allocator.destroy(__data + i);
            __size = 0;
        }
        
        void    reserve (size_type n)
        {
            if (n <= __capacity)
                return ;
            
            T   *data = __allocator.allocate(n);
            for (size_type i = 0; i < __size; i++)
                __allocator.construct(data + i, __data[i]);

            clear();
            __allocator.deallocate(__data, __capacity);
            __data = data;
            __capacity = n;
        }
        
        void    resize (size_type n, value_type val = value_type())
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
                    __reserve(n);
                else
                    __reserve(__capacity * 2);
                for (size_type i = __size; i < n; i++)
                    __allocator.construct(__data + i, val);
                    
            }
        }
    
};



#endif