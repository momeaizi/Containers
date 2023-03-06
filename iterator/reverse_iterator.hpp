/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:44:17 by momeaizi          #+#    #+#             */
/*   Updated: 2023/03/06 05:57:27 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"

namespace   ft
{
    template <class Iterator>
    class   reverse_iterator;
}

template <class Iterator>
class ft::reverse_iterator
{
    public:
        typedef  Iterator                                                               iterator_type;
        typedef  typename std::iterator_traits<Iterator>::iterator_category              iterator_category;
        typedef  typename std::iterator_traits<Iterator>::value_type                     value_type;
        typedef  typename std::iterator_traits<Iterator>::difference_type                difference_type;
        typedef  typename std::iterator_traits<Iterator>::pointer                        pointer;
        typedef  typename std::iterator_traits<Iterator>::reference                      reference;

        

        reverse_iterator()
            : __base_it (NULL) {};

        explicit reverse_iterator (iterator_type it)
            : __base_it (it) {};

        template <class _iterator>
        reverse_iterator (const reverse_iterator<_iterator> &rev_it)
            : __base_it (rev_it.base()) {};

        template <class _iterator>
        friend class rev_iterator;

    
        iterator_type                               base() const { return __base_it; };
        
        reference                                   operator*() const
        {
            iterator_type   it = __base_it;
            return *(--it);
        }

        reverse_iterator                            operator+(difference_type n) const { return reverse_iterator(__base_it - n); }

        reverse_iterator&                           operator++() { --__base_it; return *this; }
        
        reverse_iterator                            operator++(int) { reverse_iterator temp = *this; ++(*this); return temp; }

        reverse_iterator&                           operator+=(difference_type n) { __base_it -= n; return *this; }

        reverse_iterator                            operator- (difference_type n) const { return reverse_iterator(__base_it + n); }

        reverse_iterator&                           operator--() { ++__base_it; return *this; }
        
        reverse_iterator                            operator--(int) { reverse_iterator temp = *this; --(*this); return temp; }

        reverse_iterator&                           operator-=(difference_type n) { __base_it += n; return *this; }

        pointer                                     operator->() const
        {
            iterator_type   it = __base_it;
            return &(*(--it));
        }

        reference                                   operator[] (difference_type n) const { return *(__base_it - n - 1); }

        private:
            iterator_type   __base_it;

        template<typename Iterator1, typename Iterator2>
        friend bool operator== (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) { return (lhs.__base_it  == rhs.__base_it); }
        
        template<typename Iterator1, typename Iterator2>
        friend bool operator!= (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) { return (lhs.__base_it  != rhs.__base_it); }

        
        template<typename Iterator1, typename Iterator2>
        friend bool operator<  (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) { return (lhs.__base_it  > rhs.__base_it); }
        
        template<typename Iterator1, typename Iterator2>
        friend bool operator<= (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {return !(rhs < lhs); }
        
        template<typename Iterator1, typename Iterator2>
        friend bool operator>  (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {return (rhs < lhs); }
        
        template<typename Iterator1, typename Iterator2>
        friend bool operator>= (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {return !(lhs < rhs); }
        

};



template <class Iterator>
ft::reverse_iterator<Iterator>      operator+ (typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator> &rev_it) { return rev_it + n; }


template <class Iterator>
typename ft::reverse_iterator<Iterator>::difference_type operator- (const ft::reverse_iterator<Iterator> &lhs, const ft::reverse_iterator<Iterator> &rhs) { return rhs.base() - lhs.base(); }

#endif
