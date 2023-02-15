/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:48:50 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/15 15:49:26 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_SAME_HPP
#define IS_SAME_HPP


namespace ft
{
    template<typename T, typename U>
    struct is_same;

    template<typename T>
    struct is_same<T, T>;   
}

template<typename T, typename U>
struct ft::is_same : std::false_type {};

template<typename T>
struct ft::is_same<T, T> : std::true_type {};

#endif