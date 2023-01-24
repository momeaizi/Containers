/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:43:39 by momeaizi          #+#    #+#             */
/*   Updated: 2023/01/24 11:48:39 by momeaizi         ###   ########.fr       */
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
    public:
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


    public:
        explicit vector ();
        explicit vector (size_type n);
        explicit vector (size_type n, const value_type& val);
        template <class InputIterator>
        vector (InputIterator first, InputIterator last);
        vector (const vector& x);
        vector& operator= (const vector& x);
        ~vector ();


        template <class InputIterator>
        void                    assign (InputIterator first, InputIterator last);
        void                    assign (size_type n, const value_type &val);
        reference               at (size_type n)
        {
            if (n >= __size)
                throw std::out_of_range("vector");
            return __data[n];
        }
        const_reference         at (size_type n) const
        {
            if (n >= __size)
                throw std::out_of_range("vector");
            return __data[n];
        }
        reference               back()
        {
            return __data[__size - 1];
        }
        const_reference         back() const
        {
            return __data[__size - 1];
        }
        iterator                begin() { return iterator(__data); }
        const_iterator          begin() const { return const_iterator(__data); }
        reverse_iterator        rbegin() { return reverse_iterator(__data + __size - 1); }
        const_reverse_iterator  rbegin() const { return const_reverse_iterator(__data + __size - 1); }
        iterator                end() { return iterator(__data + __size); }
        const_iterator          end() const { return const_iterator(__data + __size); }
        reverse_iterator        rend() { return reverse_iterator(__data - 1); }
        const_reverse_iterator  rend() const { return const_reverse_iterator(__data - 1); }
        size_type               capacity () const { return __capacity; }
        void                    clear ();
        bool                    empty() const { return __size == 0; }
        reference               front() { return __data[0]; }
        const_reference         front() const { return __data[0]; }
        size_type               size () const { return __size; }
        allocator_type          get_allocator() const { return __allocator; };
        size_type               max_size() const { return __allocator.max_size(); };
        reference               operator[] (size_type n) { return __data[n]; }
        const_reference         operator[] (size_type n) const { return __data[n]; }
        void                    swap (vector& x);
        void                    push_back (const value_type& val);
        void                    pop_back();
        void                    reserve (size_type n);
        void                    resize (size_type n);
        void                    resize (size_type n, value_type val);
        iterator                erase (iterator pos)
        {
            __shift_left(pos, end());
            --__size;
            __allocator.destroy(__data + __size);

            return pos;
        }
        iterator                erase (iterator first, iterator last)
        {
            __range_shift_left(first, last);
            __destruct_at_end(last - first);

            __size -= (last - first);
            return first;
        }
        iterator                insert (iterator pos, const value_type &val)
        {
            size_type   p = pos - begin();
            if (__size < __capacity)
            {
                if (pos >= end())
                    __allocator.construct(__data + __size, val);
                else
                {
                    iterator    it = end() - 1;
    
                    __allocator.construct(__data + __size, *it);
                    __shift_right(pos);
                    *pos = val;
                }
            }
            else
            {
                size_type   n = (!__capacity) ? 1 : __capacity * 2;
                T   *data = __allocator.allocate(n);
    
                __allocator.construct(data + p, val);

                __reverse_copy_construct(p - 1, data); // construt             0 <- (p - 1)
                __copy_construct(p, data);             // construt             p <- end
                __destruct(0);
                
                __data = data;
                __capacity = n;
            }
            ++__size;
            return __data + p;
        }
        void                    insert (iterator pos, size_type n, const value_type& val);
        void                    swap (vector& x, vector& y); 
        


        
        
    private:
        T               *__data;
        size_type       __size;
        size_type       __capacity;
        allocator_type  __allocator;

        void    __resize(size_type n);
        void    __assign_at_begin (size_type __n, const value_type &val);
        void    __destruct (size_type __n);
        void    __destruct_at_end (size_type __n);
        void    __construct_at_end (size_type __first, size_type __last, const value_type &val);
        void    __range_shift_left (iterator first, iterator last);
        void    __shift_left (iterator first, iterator last);
        void    __shift_right (iterator pos);
        void    __copy_construct (size_type i, value_type *data);
        void    __reverse_copy_construct (size_type i, value_type *data);
    
};
/* *************************************************************************** */
/*                                 constructors                                */
/* *************************************************************************** */

template <class T>
vector<T>::vector () : __size(0), __capacity (0)
{
    __data = nullptr;
}


template <class T>
vector<T>::vector (size_type n) : __size(n), __capacity (n)
{
    __data = __allocator.allocate(__capacity);
    for (size_type i = 0; i < __size; i++)
        __allocator.construct(__data + i);
}


template <class T>
vector<T>::vector (size_type n, const value_type& val) : __size(n), __capacity (n)
{
    __data = __allocator.allocate(__capacity);
    for (size_type i = 0; i < __size; i++)
        __allocator.construct(__data + i, val);
}


template <class T>
template <class InputIterator>
vector<T>::vector (InputIterator first, InputIterator last) : __size(last - first), __capacity (__size)
{
    if (first > last)
        throw std::length_error("vector");

    __data = __allocator.allocate(__capacity);
    for (size_type i = 0; i < __size; ++i)
        __allocator.construct(__data + i, *(first + i));
}


template <class T>
vector<T>::vector (const vector& x) : __size(x.__size), __capacity (x.__capacity)
{
    __data = __allocator.allocate(__capacity);
    for (size_type i = 0; i < __size; i++)
        __allocator.construct(__data + i, x.__data[i]);
}

template <class T>
vector<T>   &vector<T>::operator= (const vector<T> &x)
{
    size_type   n = x.size();

    if (n <= __capacity)
    {
        size_type   min = std::min(n, __size);

        for (size_type i = 0; i < min; i++)
            __data[i] = x[i];    
        for (size_type i = min; i < n; i++)
            __allocator.construct(__data + i, x[i]);
        __destruct(n);
        __size = n;
    }
    else
    {
        __destruct(0);
        __allocator.deallocate(__data, __capacity);
        __data = __allocator.allocate(n);
        for (size_type i = 0; i < n; i++)
            __allocator.construct(__data + i, x[i]);       
    }
    __capacity = std::max(__capacity, n);
    __size = n;
    return *this;
}


template <class T>
vector<T>::~vector ()
{
    clear();
    if (__capacity)
        __allocator.deallocate(__data, __capacity);
}
        









template <class T>
void    vector<T>::assign (size_type n, const value_type &val)
{
    if (n <= __capacity)
    {
        size_type   min = std::min(n, __size);
        
        __assign_at_begin(min, val);
        __construct_at_end(min, n, val);
        __destruct(n);
    }
    else
    {
        clear();
        __allocator.deallocate(__data, __capacity);
        __data = __allocator.allocate(n);
        __construct_at_end(0, n, val);
    }

    __capacity = std::max(__capacity, n);
    __size = n;
}

template <class T>
template <class InputIterator>
void vector<T>::assign (InputIterator first, InputIterator last)
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
        __destruct(n);
        __size = n;
    }
    else
    {
        __destruct(0);
        __allocator.deallocate(__data, __capacity);
        __data = __allocator.allocate(n);
        for (size_type i = 0; i < n; i++)
            __allocator.construct(__data + i, *(first + i));       
    }
    __capacity = std::max(__capacity, n);
    __size = n;
}

template <class T>
void    vector<T>::clear ()
{
    __destruct(0);
    __size = 0;
}

template <class T>
void            vector<T>::swap (vector<T>& x)
{
    allocator_type  allocator = x.__allocator;
    value_type      *data = x.__data;
    size_type      size = x.__size;
    size_type      capacity = x.__capacity;

    x.__allocator = __allocator;
    x.__data = __data;
    x.__size = __size;
    x.__capacity = __capacity;
    __allocator = allocator;
    __data = data;
    __size = size;
    __capacity = capacity;
}
   
template <class T>
void    vector<T>::push_back (const value_type& val)
{
    if (__size < __capacity)
    {
        __allocator.construct(__data + __size, val);
        ++__size;
        return ;
    }
    
    size_type n = (!__capacity) ? 1 : __capacity * 2;

    T   *data = __allocator.allocate(n);

    __allocator.construct(data + __size, val);
    for (size_type i = 0; i < __size; ++i)
        __allocator.construct(data + (__size -i - 1), __data[(__size -i - 1)]);

    __destruct(0);
    __allocator.deallocate(__data, __capacity);
    __data = data;
    __capacity = n;
    ++__size;
}

template <class T>
void    vector<T>::pop_back()
{
    __allocator.destroy(__data + __size - 1);
    __size--;
}

template <class T>
void    vector<T>::reserve (size_type n)
{
    if (n <= __capacity)
        return ;
            
    T   *data = __allocator.allocate(n);
    for (size_type i = 0; i < __size; ++i)
        __allocator.construct(data + (__size - i - 1), __data[(__size - i - 1)]);

    __destruct(0);
    __allocator.deallocate(__data, __capacity);
    __data = data;
    __capacity = n;
}

template <class T>
void    vector<T>::resize (size_type n, value_type val)
{
    if (n <= __size)
    {
        __destruct(n);
        __size = n;
        return ;
    }
    
    size_type   capacity = (n > __capacity * 2) ? n : __capacity * 2;

    T   *data = __allocator.allocate(capacity);


    for (size_type i = __size; i < n; ++i)
        __allocator.construct(data + i, val);

    for (size_type i = 0; i < __size; ++i)
        __allocator.construct(data + (__size -i - 1), __data[(__size - i - 1)]);

    __destruct(0);
    __allocator.deallocate(__data, __capacity);
    __data = data;
    __capacity = capacity;
    __size = n;
}

template <class T>
void    vector<T>::resize (size_type n)
{
    if (n <= __size)
    {
        __destruct(n);
        __size = n;
        return ;
    }
    
    size_type   capacity = (n > __capacity * 2) ? n : __capacity * 2;

    T   *data = __allocator.allocate(capacity);


    for (size_type i = __size; i < n; ++i)
        __allocator.construct(data + i);

    for (size_type i = 0; i < __size; ++i)
        __allocator.construct(data + (__size -i - 1), __data[(__size - i - 1)]);

    __destruct(0);
    __allocator.deallocate(__data, __capacity);
    __data = data;
    __capacity = capacity;
    __size = n;
}
















template <class T>
void             swap (vector<T>& x, vector<T>& y)
{
    x.swap(y);
}

template <class T>
bool    operator== (const vector<T>& lhs, const vector<T>& rhs)
{
    if (lhs.size() != rhs.size())
        for (size_t i = 0; i < lhs.size(); i++)
            if (lhs[i] != rhs[i])
                return false;
    return false;
}

template <class T>
bool operator!= (const vector<T>& lhs, const vector<T>& rhs)
{
    if (lhs.size() != rhs.size())
        return true;
        
    for (size_t i = 0; i < lhs.size(); i++)
        if (lhs[i] != rhs[i])
            return true;
    return false;
}


template <class T>
bool operator<  (const vector<T>& lhs, const vector<T>& rhs)
{
    size_t    minSize = std::min(lhs.size(), rhs.size());
    for (size_t i = 0; i < minSize; i++)
        if (!(lhs[i] < rhs[i]))
            return false;
    if (lhs.size() < rhs.size())
        return true;
    return false;
}

template <class T>
bool operator<= (const vector<T>& lhs, const vector<T>& rhs)
{
    size_t    minSize = std::min(lhs.size(), rhs.size());
    for (size_t i = 0; i < minSize; i++)
        if (!(lhs[i] <= rhs[i]))
            return false;
    if (lhs.size() <= rhs.size())
        return true;
    return false;
}

template <class T>
bool operator>  (const vector<T>& lhs, const vector<T>& rhs)
{
    size_t    minSize = std::min(lhs.size(), rhs.size());
    for (size_t i = 0; i < minSize; i++)
        if (!(lhs[i] > rhs[i]))
            return false;
    if (lhs.size() > rhs.size())
        return true;
    return false;
    
}

template <class T>
bool operator>= (const vector<T>& lhs, const vector<T>& rhs)
{
    size_t    minSize = std::min(lhs.size(), rhs.size());
    for (size_t i = 0; i < minSize; i++)
        if (!(lhs[i] >= rhs[i]))
            return false;
    if (lhs.size() >= rhs.size())
        return true;
    return false;
}













































































































template <class T>
void    vector<T>::__resize(size_type n)
{
    T   *data = __allocator.allocate(n);
    
    
    for (size_type i = __size; i < n; i++)
        __allocator.construct(data + i);
    for (size_type i = 0; i < __size; i++)
        __allocator.construct(data + i, __data[i]);
    __destruct(0);
    __allocator.deallocate(__data, __capacity);
    __data = data;
    __size = n;
    __capacity = n;
}

template <class T>
void    vector<T>::__assign_at_begin (size_type __n, const value_type &val)
{
    for (size_type i = 0; i < __n; i++)
        __data[i] = val;
}

template <class T>
void    vector<T>::__destruct (size_type __n)
{
    reverse_iterator    it = rbegin();

    for (; it != rend() && ++__n <= __size; ++it)
        __allocator.destroy(&(*it));
}

template <class T>
void    vector<T>::__destruct_at_end (size_type __n)
{
    for (size_type i = 1; i <= __n; ++i)
        __allocator.destroy(__data + __size - i);
}

template <class T>
void    vector<T>::__construct_at_end (size_type __first, size_type __last, const value_type &val)
{
    for (size_type i = __first; i < __last; i++)
        __allocator.construct(__data + i, val);
}

template <class T>
void    vector<T>::__copy_construct (size_type i, value_type *data)
{
    for (; i < __size; ++i)
        __allocator.construct(data + i + 1, __data[i]);
}

template <class T>
void    vector<T>::__reverse_copy_construct (size_type i, value_type *data)
{
    for (; i >= 0; --i)
    {
        __allocator.construct(data + i, __data[i]);
        if (!i)
            break ;
    }
}

template <class T>
void    vector<T>::__shift_left (iterator first, iterator last)
{
    while (++first != last)
        *(first - 1) = *first;
}

template <class T>
void    vector<T>::__range_shift_left (iterator first, iterator last)
{
    while (last != end())
        *(first++) = *(last++);
}

template <class T>
void    vector<T>::__shift_right (iterator pos)
{
    for (iterator it = end() - 1; it > pos; --it)
        *it = *(it - 1);
}


#endif