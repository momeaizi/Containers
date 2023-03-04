/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:33:04 by momeaizi          #+#    #+#             */
/*   Updated: 2023/03/04 18:32:29 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP




namespace ft
{
    template <typename Iterator>
        struct iterator_traits;
    
    template <typename T>
        struct iterator_traits<T*>;
    
    template <typename T>
        struct iterator_traits<const T*>;

}



template <typename Iterator>
struct ft::iterator_traits
{
    typedef  typename  Iterator::iterator_category        iterator_category;
    typedef  typename  Iterator::value_type               value_type;
    typedef  typename  Iterator::difference_type          difference_type;
    typedef  typename  Iterator::pointer                  pointer;
    typedef  typename  Iterator::reference                reference;
};


template <typename T>
struct ft::iterator_traits<T*>
{
    typedef std::ptrdiff_t                                  difference_type;
    typedef T                                               value_type;
    typedef T*                                              pointer;
    typedef T&                                              reference;
    typedef typename std::random_access_iterator_tag        iterator_category;
    
};


template <typename T>
struct ft::iterator_traits<const T*>
{
    typedef std::ptrdiff_t                              difference_type;
    typedef const T                                     value_type;
    typedef const T*                                    pointer;
    typedef const T&                                    reference;
    typedef class std::random_access_iterator_tag       iterator_category;
    
};



#endif
