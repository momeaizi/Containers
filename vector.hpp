/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:43:39 by momeaizi          #+#    #+#             */
/*   Updated: 2023/01/27 22:00:54 by momeaizi         ###   ########.fr       */
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
            __shift_left(pos, end(), 1);
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
                    __shift_right(pos, it, 1);
                    *pos = val;
                }
            }
            else
            {
                size_type   n = (!__capacity) ? 1 : __capacity * 2;
                T   *data = __allocator.allocate(n);
    
                __allocator.construct(data + p, val);

                __reverse_copy_construct(p, data);
                __copy_construct(p, __size, data + 1);
                __destruct(0);
                
                __data = data;
                __capacity = n;
            }
            ++__size;
            return __data + p;
        }
        void                    insert (iterator pos, size_type n, const value_type& val);
        template <class InputIterator>
        void                    insert (iterator pos, InputIterator first, InputIterator last);


        
        
    private:
        T               *__data;
        size_type       __size;
        size_type       __capacity;
        allocator_type  __allocator;

        void    __resize(size_type n);
        void    __assign (size_type __start, size_type __end, const value_type &val);
        template <class InputIterator>
        void    __assign_range (size_type __start, size_type __end, InputIterator range);
        void    __destruct (size_type __n);
        void    __destruct_at_end (size_type __n);
        void    __construct_at_end (size_type __first, size_type __last, const value_type &val, value_type *data);
        void    __range_shift_left (iterator first, iterator last);
        void    __shift_left (iterator first, iterator last, size_type n);
        void    __shift_right (iterator first, iterator last, size_type n);
        void    __copy_construct (size_type __start, size_type __end, value_type *data);
        void    __reverse_copy_construct (size_type i, value_type *data);
        template <class InputIterator>
        void    __range_construct (InputIterator range, value_type *data, size_type n);
    
};




/* *************************************************************************** */
/*                                 constructors                                */
/* *************************************************************************** */

template <class T>
vector<T>::vector () : __data(nullptr), __size(0), __capacity (0) {}


template <class T>
vector<T>::vector (size_type n) : __data(nullptr), __size(n), __capacity (n)
{
    __data = __allocator.allocate(__capacity);
    for (size_type i = 0; i < __size; i++)
        __allocator.construct(__data + i);
}


template <class T>
vector<T>::vector (size_type n, const value_type& val) : __data(nullptr), __size(n), __capacity (n)
{
    __data = __allocator.allocate(__capacity);
    for (size_type i = 0; i < __size; i++)
        __allocator.construct(__data + i, val);
}


template <class T>
template <class InputIterator>
vector<T>::vector (InputIterator first, InputIterator last) : __data(nullptr), __size(last - first), __capacity (__size)
{
    if (first > last)
        throw std::length_error("vector");

    __data = __allocator.allocate(__capacity);
    for (size_type i = 0; i < __size; ++i)
        __allocator.construct(__data + i, *(first++));
}


template <class T>
vector<T>::vector (const vector& x) : __data(nullptr), __size(x.__size), __capacity (x.__capacity)
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


/* *************************************************************************** */
/*                                  destructor                                 */
/* *************************************************************************** */

template <class T>
vector<T>::~vector ()
{
    clear();
    if (__capacity)
        __allocator.deallocate(__data, __capacity);
}
        







/* *************************************************************************** */
/*                               member functions                              */
/* *************************************************************************** */

template <class T>
void    vector<T>::assign (size_type n, const value_type &val)
{
    if (n <= __capacity)
    {
        size_type   min = std::min(n, __size);
        
        __assign(0, min, val);
        __construct_at_end(min, n, val, __data);
        __destruct(n);
    }
    else
    {
        clear();
        __allocator.deallocate(__data, __capacity);
        __data = __allocator.allocate(n);
        __construct_at_end(0, n, val, __data);
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

    size_type n = last - first;

    if (n <= __capacity)
    {
        size_type   min = std::min(n, __size);

        __assign_range(0, std::min(n, __size), first);
        for (size_type i = min; i < n; i++)
            __allocator.construct(__data + i, *(first++));
        __destruct(n);
        __size = n;
    }
    else
    {
        __destruct(0);
        __allocator.deallocate(__data, __capacity);
        __data = __allocator.allocate(n);
        for (size_type i = 0; i < n; i++)
            __allocator.construct(__data + i, *(first++));       
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

    std::swap(x.__allocator, __allocator);
    std::swap(x.__data, __data);
    std::swap(x.__size, __size);
    std::swap(x.__capacity, __capacity);
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
    __reverse_copy_construct(__size, data);

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
void    vector<T>::insert (iterator pos, size_type n, const value_type& val)
{
    size_type   p = pos - begin();
    if (__size + n > __capacity)
    {
        size_type   capacity = (__capacity * 2 < n + __size) ? __size + n : __capacity * 2;;
        T   *data = __allocator.allocate(capacity);


        __construct_at_end(0, n, val, data + p);
        __reverse_copy_construct(p, data);
        __copy_construct(p, __size, data + n);
        __destruct(0);
        __allocator.deallocate(__data, __capacity);
        __data = data;
        __capacity = capacity;
    }
    else
    {
        if (pos + n > end())
        {
            size_type   __n = end() - pos;
            __construct_at_end(0, n - __n, val, __data + __size);
            __copy_construct(__size - __n, __size, __data + n);
            __assign(p, __size, val);
        }
        else
        {
            __copy_construct(__size - n, __size, __data + n);
            __shift_right(pos + n - 1, end() - 1, n);
            __assign(p, p + n, val);
        }
        
    }
    __size += n;
}

template <class T>
template <class InputIterator>
void    vector<T>::insert (iterator pos, InputIterator first, InputIterator last)
{
    size_type   p = pos - begin();
    size_type   n = last - first;

    if (__size + n > __capacity)
    {
        size_type   capacity = (__capacity * 2 < n + __size) ? __size + n : __capacity * 2;;
        T   *data = __allocator.allocate(capacity);


        __range_construct(first, data + p, n);
        __reverse_copy_construct(p, data);
        __copy_construct(p, __size, data + n);
        __destruct(0);
        __allocator.deallocate(__data, __capacity);
        __data = data;
        __capacity = capacity;
    }
    else
    {
        if (pos + n > end())
        {
            size_type   __n = end() - pos;
            
            __range_construct(first + __n, __data + __size, n - __n);
            __copy_construct(__size - __n, __size, __data + n);
            __assign_range(p, __size, first);
        }
        else
        {
            __copy_construct(__size - n, __size, __data + n);
            __shift_right(pos + n - 1, end() - 1, n);
            __assign_range(p, p + n, first);
        }
    }
    __size += n;
}












/* *************************************************************************** */
/*                             non-member overloads                            */
/* *************************************************************************** */

template <class T>
bool    is_integral(const T &type);

template <class T>
void             swap (vector<T>& x, vector<T>& y)
{
    x.swap(y);
}

template <class T>
bool    operator== (const vector<T>& lhs, const vector<T>& rhs)
{
    if (lhs.size() != rhs.size())
        return false;

    if (lhs.size() == rhs.size())
        for (size_t i = 0; i < lhs.size(); ++i)
            if (lhs[i] != rhs[i])
                return false;
    return true;
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

    for (size_t i = 0; i < minSize; ++i)
    {
        if (lhs[i] < rhs[i])
            return true;
        else if (lhs[i] > rhs[i])
            return false;
    }
    if (lhs.size() < rhs.size())
        return true;
    return false;
}

template <class T>
bool operator<=  (const vector<T>& lhs, const vector<T>& rhs)
{
    size_t    minSize = std::min(lhs.size(), rhs.size());

    for (size_t i = 0; i < minSize; ++i)
    {
        if (lhs[i] <= rhs[i])
            return true;
        else if (lhs[i] > rhs[i])
            return false;
    }
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

template <class InputIterator>
InputIterator   operator+ (InputIterator inputit, size_t n)
{
    InputIterator   it = inputit;

    for (size_t i = 0; i < n; ++i)
        ++it;

    return it;
}









/* *************************************************************************** */
/*                           private-member overloads                          */
/* *************************************************************************** */

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
void    vector<T>::__assign (size_type __start, size_type __end, const value_type &val)
{
    for (size_type i = __start; i < __end; ++i)
        __data[i] = val;
}

template <class T>
template <class InputIterator>
void    vector<T>::__assign_range (size_type __start, size_type __end, InputIterator range)
{
    for (size_type i = __start; i < __end; ++i)
        __data[i] = *(range++);
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
void    vector<T>::__construct_at_end (size_type __first, size_type __last, const value_type &val, value_type *data)
{
    for (size_type i = __first; i < __last; i++)
        __allocator.construct(data + i, val);
}

template <class T>
void    vector<T>::__copy_construct (size_type __start, size_type __end, value_type *data)
{
    for (size_type i = __start; i < __end; ++i)
        __allocator.construct(data + i, __data[i]);
}

template <class T>
template <class InputIterator>
void    vector<T>::__range_construct (InputIterator range, value_type *data, size_type n)
{
    for (size_type i = 0; i < n; ++i)
        __allocator.construct(data + i, *(range++));
}

template <class T>
void    vector<T>::__reverse_copy_construct (size_type i, value_type *data)
{
    while (i > 0)
    {
        __allocator.construct(data + i - 1, __data[i - 1]);
        --i;
    }
}

template <class T>
void    vector<T>::__shift_left (iterator first, iterator last, size_type n)
{
    while (++first != last)
        *(first - n) = *first;
}

template <class T>
void    vector<T>::__range_shift_left (iterator first, iterator last)
{
    while (last != end())
        *(first++) = *(last++);
}

template <class T>
void    vector<T>::__shift_right (iterator first, iterator last, size_type n)
{
    for (iterator it = last; it > first; --it)
        *it = *(it - n);
}


#endif