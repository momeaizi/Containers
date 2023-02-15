/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 07:54:42 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/05 11:30:29 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include <iostream>

template <class T>
struct is_integral : std::false_type {};

template <>
struct is_integral<bool> : std::true_type {};

template <>
struct is_integral<const bool> : std::true_type {};

template <>
struct is_integral<char> : std::true_type {};

template <>
struct is_integral<const char> : std::true_type {};

template <>
struct is_integral<char16_t> : std::true_type {};

template <>
struct is_integral<const char16_t> : std::true_type {};

template <>
struct is_integral<char32_t> : std::true_type {};

template <>
struct is_integral<const char32_t> : std::true_type {};

template <>
struct is_integral<wchar_t> : std::true_type {};

template <>
struct is_integral<const wchar_t> : std::true_type {};

template <>
struct is_integral<signed char> : std::true_type {};

template <>
struct is_integral<const signed char> : std::true_type {};

template <>
struct is_integral<short int> : std::true_type {};

template <>
struct is_integral<const short int> : std::true_type {};

template <>
struct is_integral<int> : std::true_type {};

template <>
struct is_integral<const int> : std::true_type {};

template <>
struct is_integral<long int> : std::true_type {};

template <>
struct is_integral<const long int> : std::true_type {};

template <>
struct is_integral<long long int> : std::true_type {};

template <>
struct is_integral<const long long int> : std::true_type {};

template <>
struct is_integral<unsigned char> : std::true_type {};

template <>
struct is_integral<const unsigned char> : std::true_type {};

template <>
struct is_integral<unsigned short int> : std::true_type {};

template <>
struct is_integral<const unsigned short int> : std::true_type {};

template <>
struct is_integral<unsigned int> : std::true_type {};

template <>
struct is_integral<const unsigned int> : std::true_type {};

template <>
struct is_integral<unsigned long int> : std::true_type {};

template <>
struct is_integral<const unsigned long int> : std::true_type {};

template <>
struct is_integral<unsigned long long int> : std::true_type {};

template <>
struct is_integral<const unsigned long long int> : std::true_type {};

#endif