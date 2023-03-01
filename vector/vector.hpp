/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:43:39 by momeaizi          #+#    #+#             */
/*   Updated: 2023/03/01 15:09:57 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include <iostream>
#include "../utils/enable_if.hpp"
#include "../utils/is_integral.hpp"
#include "../iterator/iterator.hpp"
#include "../iterator/reverse_iterator.hpp"
#include "../iterator/iterator_traits.hpp"

namespace   ft
{
    template < class T, class Alloc>
    class vector;

    template < class T, class Alloc>
    void    swap (ft::vector<T, Alloc>& x, ft::vector<T, Alloc>& y);
}


template < class T, class Alloc = std::allocator<T> >
class ft::vector
{
    public:
        typedef T                                           value_type;
        typedef Alloc                                       allocator_type;
        typedef T&                                          reference;
        typedef const T&                                    const_reference;
        typedef T*                                          pointer;
        typedef const T*                                    const_pointer;
        typedef Iterator<T>                                 iterator;
        typedef Iterator<const T>                           const_iterator;
        typedef ft::reverse_iterator<iterator>              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
        typedef std::ptrdiff_t                              difference_type;
        typedef std::size_t                                 size_type;


    public:
        explicit vector (const allocator_type& alloc = allocator_type());
        explicit vector (size_type n, const value_type &val = value_type(), const allocator_type& alloc = allocator_type());
        template <class InputIterator>
        vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last);
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
        iterator                begin() { return __data; }
        
        const_iterator          begin() const { return __data; }
       
        iterator                end() { return __data + __size; }
        
        const_iterator          end() const { return __data + __size; }
        
        reverse_iterator        rbegin() { return reverse_iterator(end()); }
        
        const_reverse_iterator  rbegin() const { return const_reverse_iterator(end()); }
        
        reverse_iterator        rend() { return reverse_iterator(begin()); }
        
        const_reverse_iterator  rend() const { return const_reverse_iterator(begin()); }
        
        size_type               capacity () const { return __capacity; }
        
        void                    clear ();
        
        bool                    empty() const { return __size == 0; }
        
        reference               front() { return __data[0]; }
        
        const_reference         front() const { return __data[0]; }
        
        size_type               size () const { return __size; }
        
        allocator_type          get_allocator() const { return __allocator; };
        
        size_type               max_size() const;
        
        reference               operator[] (size_type n) { return __data[n]; }
        
        const_reference         operator[] (size_type n) const { return __data[n]; }
        void                    swap (vector& x);
        void                    push_back (const value_type& val);
        void                    pop_back();
        void                    reserve (size_type n);
        void                    resize (size_type n, value_type val = value_type());
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
                
                if (__capacity)
                    __allocator.deallocate(__data, __capacity);
                __data = data;
                __capacity = n;
            }
            ++__size;
            return __data + p;
        }
        void                    insert (iterator pos, size_type n, const value_type& val);
        template <class InputIterator>
        void                    insert (iterator position, InputIterator first, InputIterator last);


        
        
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
        template <class InputIterator>
        size_type   distance(InputIterator first, InputIterator last);
    
};




/* *************************************************************************** */
/*                                 constructors                                */
/* *************************************************************************** */

template < class T, class Alloc>
ft::vector<T, Alloc>::vector (const allocator_type& alloc) : __data(nullptr), __size(0), __capacity (0), __allocator(alloc) {}


template < class T, class Alloc>
ft::vector<T, Alloc>::vector (size_type n, const value_type &val, const allocator_type& alloc) : __data(nullptr), __size(n), __capacity (n), __allocator(alloc)
{
    if (!n)
        return ;
    if (n > __allocator.max_size())
        throw std::length_error("vector");
    __data = __allocator.allocate(__capacity);
    for (size_type i = 0; i < __size; i++)
        __allocator.construct(__data + i, val);
}


template < class T, class Alloc>
template <class InputIterator>
ft::vector<T, Alloc>::vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last) : __data(nullptr), __size(0), __capacity (__size)
{
    size_type   n = distance(first, last);

    resize(n);

    for (size_type i = 0; i < __size; ++i, ++first)
        __data[i] = *first;
}


template < class T, class Alloc>
ft::vector<T, Alloc>::vector (const vector& x) : __data(nullptr), __size(x.__size), __capacity (x.__capacity)
{
    __data = __allocator.allocate(__capacity);
    for (size_type i = 0; i < __size; i++)
        __allocator.construct(__data + i, x.__data[i]);
}

template < class T, class Alloc>
ft::vector<T, Alloc>   &ft::vector<T, Alloc>::operator= (const ft::vector<T, Alloc> &x)
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
        if (__capacity)
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

template < class T, class Alloc>
ft::vector<T, Alloc>::~vector ()
{
    clear();
    if (__capacity)
        __allocator.deallocate(__data, __capacity);
}
        







/* *************************************************************************** */
/*                               member functions                              */
/* *************************************************************************** */

template < class T, class Alloc>
typename ft::vector<T, Alloc>::size_type   ft::vector<T, Alloc>::max_size() const 
{
    if (sizeof(value_type) == 1)
        return __allocator.max_size() / 2;
    return __allocator.max_size();
};

template < class T, class Alloc>
void    ft::vector<T, Alloc>::assign (size_type n, const value_type &val)
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
        if (__data)
        if (__capacity)
            __allocator.deallocate(__data, __capacity);
        __data = __allocator.allocate(n);
        __construct_at_end(0, n, val, __data);
    }

    __capacity = std::max(__capacity, n);
    __size = n;
}


template < class T, class Alloc>
template <class InputIterator>
void ft::vector<T, Alloc>::assign (InputIterator first, InputIterator last)
{
    vector  v;
    while (first != last)
        v.push_back((*first++));

    *this = v;
}

template < class T, class Alloc>
void    ft::vector<T, Alloc>::clear ()
{
    __destruct(0);
    __size = 0;
}

template < class T, class Alloc>
void            ft::vector<T, Alloc>::swap (vector<T, Alloc>& x)
{

    std::swap(x.__allocator, __allocator);
    std::swap(x.__data, __data);
    std::swap(x.__size, __size);
    std::swap(x.__capacity, __capacity);
}
   
template < class T, class Alloc>
void    ft::vector<T, Alloc>::push_back (const value_type& val)
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
    if (__capacity)
        __allocator.deallocate(__data, __capacity);
    __data = data;
    __capacity = n;
    ++__size;
}

template < class T, class Alloc>
void    ft::vector<T, Alloc>::pop_back()
{
    __allocator.destroy(__data + __size - 1);
    __size--;
}

template < class T, class Alloc>
void    ft::vector<T, Alloc>::reserve (size_type n)
{
    if (n <= __capacity)
        return ;
            
    T   *data = __allocator.allocate(n);
    for (size_type i = 0; i < __size; ++i)
        __allocator.construct(data + (__size - i - 1), __data[(__size - i - 1)]);

    __destruct(0);
    if (__capacity)
        __allocator.deallocate(__data, __capacity);
    __data = data;
    __capacity = n;
}

template < class T, class Alloc>
void    ft::vector<T, Alloc>::resize (size_type n, value_type val)
{
    if (n <= __size)
    {
        __destruct(n);
        __size = n;
        return ;
    }
    
    if (n <= __capacity)
    {
        for (size_type i = __size; i < n; ++i)
            __allocator.construct(__data + i, val);
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
    if (__capacity)
        __allocator.deallocate(__data, __capacity);
    __data = data;
    __capacity = capacity;
    __size = n;
}


template < class T, class Alloc>
void    ft::vector<T, Alloc>::insert (iterator pos, size_type n, const value_type& val)
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
        if (__capacity)
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

template < class T, class Alloc>
template <class InputIterator>
void    ft::vector<T, Alloc>::insert (iterator position, InputIterator first, InputIterator last)
{
    size_type			pos;
    iterator			it;
    size_type	        n = distance(first, last);

    if (!n)
        return ;

    pos = position - begin();
    resize(__size + n);

    for (size_type i = __size; i > pos + n; --i)
        __data[i - 1] = __data[i - n - 1];

    for (size_type i = pos; i < pos + n; ++i, ++first)
        __data[i] = *first;
}



/* *************************************************************************** */
/*                             non-member overloads                            */
/* *************************************************************************** */


template < class T, class Alloc>
void             ft::swap (ft::vector<T, Alloc>& x, ft::vector<T, Alloc>& y)
{
    x.swap(y);
}

template < class T, class Alloc>
bool    operator== (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
    if (lhs.size() != rhs.size())
        return false;

    for (size_t i = 0; i < lhs.size(); ++i)
        if (lhs[i] != rhs[i])
            return false;
    return true;
}

template < class T, class Alloc>
bool operator!= (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
    return !(lhs == rhs);
}


template < class T, class Alloc>
bool operator<  (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
    size_t  i = 0;

    while (i < lhs.size() && i < rhs.size())
    {
        if (lhs[i] < rhs[i]) return true;
        if (lhs[i] > rhs[i]) return false;
        ++i;
    }
        if (lhs.size() < rhs.size())
            return true;
    return false;
}

template < class T, class Alloc>
bool operator<=  (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
    return !(rhs < lhs);
}

template < class T, class Alloc>
bool operator>  (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
    return rhs < lhs;
}

template < class T, class Alloc>
bool operator>= (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
    return !(lhs < rhs);
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

template < class T, class Alloc>
void    ft::vector<T, Alloc>::__resize(size_type n)
{
    T   *data = __allocator.allocate(n);
    
    
    for (size_type i = __size; i < n; i++)
        __allocator.construct(data + i);
    for (size_type i = 0; i < __size; i++)
        __allocator.construct(data + i, __data[i]);
    __destruct(0);
    if (__capacity)
        __allocator.deallocate(__data, __capacity);
    __data = data;
    __size = n;
    __capacity = n;
}

template < class T, class Alloc>
void    ft::vector<T, Alloc>::__assign (size_type __start, size_type __end, const value_type &val)
{
    for (size_type i = __start; i < __end; ++i)
        __data[i] = val;
}

template < class T, class Alloc>
template <class InputIterator>
void    ft::vector<T, Alloc>::__assign_range (size_type __start, size_type __end, InputIterator range)
{
    for (size_type i = __start; i < __end; ++i)
        __data[i] = *(range++);
}

template < class T, class Alloc>
void    ft::vector<T, Alloc>::__destruct (size_type __n)
{
    for (size_type i = __size; i > __n; --i)
        __allocator.destroy(__data + i - 1);
}

template < class T, class Alloc>
void    ft::vector<T, Alloc>::__destruct_at_end (size_type __n)
{
    for (size_type i = 1; i <= __n; ++i)
        __allocator.destroy(__data + __size - i);
}

template < class T, class Alloc>
void    ft::vector<T, Alloc>::__construct_at_end (size_type __first, size_type __last, const value_type &val, value_type *data)
{
    for (size_type i = __first; i < __last; i++)
        __allocator.construct(data + i, val);
}

template < class T, class Alloc>
void    ft::vector<T, Alloc>::__copy_construct (size_type __start, size_type __end, value_type *data)
{
    for (size_type i = __start; i < __end; ++i)
        __allocator.construct(data + i, __data[i]);
}

template < class T, class Alloc>
template <class InputIterator>
void    ft::vector<T, Alloc>::__range_construct (InputIterator range, value_type *data, size_type n)
{
    for (size_type i = 0; i < n; ++i)
        __allocator.construct(data + i, *(range++));
}

template < class T, class Alloc>
void    ft::vector<T, Alloc>::__reverse_copy_construct (size_type i, value_type *data)
{
    while (i > 0)
    {
        __allocator.construct(data + i - 1, __data[i - 1]);
        --i;
    }
}

template < class T, class Alloc>
void    ft::vector<T, Alloc>::__shift_left (iterator first, iterator last, size_type n)
{
    while (++first != last)
        *(first - n) = *first;
}

template < class T, class Alloc>
void    ft::vector<T, Alloc>::__range_shift_left (iterator first, iterator last)
{
    while (last != end())
        *(first++) = *(last++);
}

template < class T, class Alloc>
void    ft::vector<T, Alloc>::__shift_right (iterator first, iterator last, size_type n)
{
    for (iterator it = last; it > first; --it)
        *it = *(it - n);
}

template < class T, class Alloc>
template <class InputIterator>
typename ft::vector<T, Alloc>::size_type   ft::vector<T, Alloc>::distance(InputIterator first, InputIterator last)
{
    size_type   n = 0;

    for (; first != last; ++first, ++n);

    return n;
}
#endif