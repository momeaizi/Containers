/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:44:17 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/15 15:47:20 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace   ft
{
    template <class T>
    class   reverse_iterator;
}

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

        template <class _iterator>
        reverse_iterator (const reverse_iterator<_iterator> &rev_it)
            : __base_it (rev_it.base()) {};

    
        iterator_type                               base() const { return __base_it; };
        
        reference                                   operator*() const { return *(__base_it - 1); }

        reverse_iterator                            operator+(difference_type n) const { return reverse_iterator(__base_it - n); }

        reverse_iterator&                           operator++() { --__base_it; return *this; }
        
        reverse_iterator                            operator++(int) { reverse_iterator temp = *this; ++(*this); return temp; }

        reverse_iterator&                           operator+=(difference_type n) { __base_it -= n; return *this; }

        reverse_iterator                            operator- (difference_type n) const { return reverse_iterator(__base_it + n); }

        reverse_iterator&                           operator--() { ++__base_it; return *this; }
        
        reverse_iterator                            operator--(int) { reverse_iterator temp = *this; --(*this); return temp; }

        reverse_iterator&                           operator-=(difference_type n) { __base_it += n; return *this; }

        pointer                                     operator->() const { return &(*(__base_it - 1)); }

        reference                                   operator[] (difference_type n) const { return *(__base_it - n - 1); }

        private:
            iterator_type   __base_it;

};



template <class Iterator>
bool operator== (const ft::reverse_iterator<Iterator> &lhs, const ft::reverse_iterator<Iterator> &rhs) { return lhs.base() == rhs.base(); }

template <class Iterator>
bool operator!= (const ft::reverse_iterator<Iterator> &lhs, const ft::reverse_iterator<Iterator> &rhs) { return lhs.base() != rhs.base(); }

template <class Iterator>
bool operator<  (const ft::reverse_iterator<Iterator> &lhs, const ft::reverse_iterator<Iterator> &rhs) { return lhs.base() > rhs.base(); }

template <class Iterator>
bool operator<= (const ft::reverse_iterator<Iterator> &lhs, const ft::reverse_iterator<Iterator> &rhs) { return lhs.base() >= rhs.base(); }

template <class Iterator>
bool operator>  (const ft::reverse_iterator<Iterator> &lhs, const ft::reverse_iterator<Iterator> &rhs) { return lhs.base() < rhs.base(); }

template <class Iterator>
bool operator>= (const ft::reverse_iterator<Iterator> &lhs, const ft::reverse_iterator<Iterator> &rhs) { return lhs.base() <= rhs.base(); }



template <class Iterator>
ft::reverse_iterator<Iterator>      operator+ (typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator> &rev_it) { return rev_it + n; }


template <class Iterator>
typename ft::reverse_iterator<Iterator>::difference_type operator- (const ft::reverse_iterator<Iterator> &lhs, const ft::reverse_iterator<Iterator> &rhs) { return rhs.base() - lhs.base(); }

#endif