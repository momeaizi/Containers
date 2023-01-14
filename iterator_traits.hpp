/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:33:04 by momeaizi          #+#    #+#             */
/*   Updated: 2023/01/14 15:54:37 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP


template <class Iterator>
class iterator_traits
{
    typedef class Iterator::difference_type       difference_type;
    typedef class Iterator::value_type            value_type;
    typedef class Iterator::pointer               pointer;
    typedef class Iterator::reference             reference;
    typedef class Iterator::iterator_category     iterator_category;
};



template <class T>
class iterator_traits<T*>
{
    typedef std::ptrdiff_t                              difference_type;
    typedef T                                           value_type;
    typedef T*                                          pointer;
    typedef T&                                          reference;
    typedef class std::random_access_iterator_tag       iterator_category;
    
};


template <class T>
class iterator_traits<const T*>
{
    typedef std::ptrdiff_t                              difference_type;
    typedef const T                                     value_type;
    typedef const T*                                    pointer;
    typedef const T&                                    reference;
    typedef class std::random_access_iterator_tag       iterator_category;
    
};


#endif