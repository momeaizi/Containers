/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:57:05 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/15 15:49:32 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

#include "is_integral.hpp"

namespace ft
{
    template<bool B, class T>
    struct  enable_if;

    template<class T>
    struct  enable_if<true, T>;
}

template<bool B, class T = void>
struct  ft::enable_if {};
 
template<class T>
struct  ft::enable_if<true, T> { typedef T type; };


#endif