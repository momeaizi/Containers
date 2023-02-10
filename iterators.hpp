/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:01:43 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/10 16:26:56 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iTERATOR_HPP
#define iTERATOR_HPP

namespace   ft
{
    template <class T>
    class   iterator;

    template <class T>
    class   reverse_iterator;

}

// template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>


/* *************************************************************************** */
/*                               vector: iterator                              */
/* *************************************************************************** */
template <class T>
class ft::iterator
{
    private:
        T           *m_ptr;
    public:
        typedef  T                                  value_type;
        typedef  T&                                 reference;
        typedef  T*                                 pointer;
        typedef  std::ptrdiff_t                     difference_type;
        typedef  std::random_access_iterator_tag    iterator_category;
        typedef  iterator<T>                        iterator_type;

        iterator() : m_ptr(NULL) {}
        iterator(T *ptr) : m_ptr(ptr) {}
        template <class _T>
        iterator(const _T &it) : m_ptr(&(*it)) {}
        template <class _Tp>
        _Tp   &operator=(const T &it) const { m_ptr = it.m_ptr; return *this; }

        iterator&                                   operator++() { ++m_ptr; return *this; }
        iterator                                    operator++(int) { iterator temp = *this; ++*this; return temp; }
        iterator&                                   operator--() { --m_ptr; return *this; }
        iterator                                    operator--(int) { iterator temp = *this; --*this; return temp; }
        bool                                        operator==(const iterator &it) const { return m_ptr == it.m_ptr; }
        bool                                        operator!=(const iterator &it) const { return !(*this == it); }
        T&                                          operator*() const { return *m_ptr; }
        T*                                          operator->() const { return m_ptr; }
        
        iterator                                    operator+(difference_type n) const { return iterator(m_ptr + n); }
        iterator                                    operator-(difference_type n) const { return iterator(m_ptr - n); }
        difference_type                             operator-(const iterator& it) const { return m_ptr - it.m_ptr; }
        T&                                          operator[](difference_type n) const { return *(m_ptr + n); }
        iterator&                                   operator+=(difference_type n) { m_ptr += n; return *this; }
        iterator&                                   operator-=(difference_type n) { m_ptr -= n; return *this; }
        bool                                        operator<(const iterator& it) const { return m_ptr < it.m_ptr; }
        bool                                        operator>(const iterator& it) const { return m_ptr > it.m_ptr; }
        bool                                        operator<=(const iterator& it) const { return m_ptr <= it.m_ptr; }
        bool                                        operator>=(const iterator& it) const { return m_ptr >= it.m_ptr; }
};

template <class T>
ft::iterator<T>    operator+(std::ptrdiff_t n, const ft::iterator<T> &it) { return it + n; }

template <class T>
ft::iterator<T>    operator-(std::ptrdiff_t n, const ft::iterator<T> &it) { return it - n; }


/* *************************************************************************** */
/*                           vector: reverse_iterator                          */
/* *************************************************************************** */
template <class T>
class ft::reverse_iterator
{
    public:
        typedef  T                                  value_type;
        typedef  T&                                 reference;
        typedef  T*                                 pointer;
        typedef  std::ptrdiff_t                     difference_type;
        typedef  std::random_access_iterator_tag    iterator_category;
        typedef  iterator<T>                        iterator_type;
        

        reverse_iterator()
            : __base_it (nullptr) {};

        explicit reverse_iterator (iterator_type it)
            : __base_it (it) {};

        template <class Iter>  reverse_iterator (const reverse_iterator<Iter>& rev_it)
            : __base_it (rev_it.base()) {};

        template <class _Tp>
        _Tp   &operator=(const T &rev_it) const { __base_it = rev_it.base(); return *this; }
    
        T&                                          operator*() const { return *__base_it; }
        T*                                          operator->() const { return &(*__base_it); }
        reverse_iterator&                           operator++() { --__base_it; return *this; }
        reverse_iterator                            operator++(int) { reverse_iterator temp = *this; --*this; return temp; }
        reverse_iterator&                           operator--() { ++__base_it; return *this; }
        reverse_iterator                            operator--(int) { reverse_iterator temp = *this; ++*this; return temp; }
        bool                                        operator==(const reverse_iterator& it) const { return __base_it == it.__base_it; }
        bool                                        operator!=(const reverse_iterator& it) const { return !(*this == it); }
        reverse_iterator                            operator+(difference_type n) const { return reverse_iterator(__base_it - n); }
        reverse_iterator                            operator-(difference_type n) const { return reverse_iterator(__base_it + n); }
        difference_type                             operator-(const reverse_iterator& it) const { return __base_it + it.__base_it; }
        T&                                          operator[](difference_type n) const { return __base_it[n]; }
        reverse_iterator&                           operator+=(difference_type n) { __base_it -= n; return *this; }
        reverse_iterator&                           operator-=(difference_type n) { __base_it += n; return *this; }
        bool                                        operator<(const reverse_iterator& it) const { return __base_it < it.__base_it; }
        bool                                        operator>(const reverse_iterator& it) const { return __base_it > it.__base_it; }
        bool                                        operator<=(const reverse_iterator& it) const { return __base_it <= it.__base_it; }
        bool                                        operator>=(const reverse_iterator& it) const { return __base_it >= it.__base_it; }
        iterator_type                               base() const { return __base_it; };

        private:
            iterator_type   __base_it;

};

template <class T>
ft::reverse_iterator<T>    operator+(std::ptrdiff_t n, const ft::reverse_iterator<T> &it) { return it + n; }

template <class T>
ft::reverse_iterator<T>    operator-(std::ptrdiff_t n, const ft::reverse_iterator<T> &it) { return it - n; }




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