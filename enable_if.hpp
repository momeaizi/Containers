/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:57:05 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/05 15:15:05 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP

#define ENABLE_IF_HPP
#include "is_integral.hpp"

template<bool B, class T = void>
struct  enable_if {};
 
template<class T>
struct  enable_if<true, T> { typedef T type; };


template<typename T, typename U>
struct is_same : std::false_type {};

template<typename T>
struct is_same<T, T> : std::true_type {};

#endif