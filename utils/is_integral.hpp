/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 07:54:42 by momeaizi          #+#    #+#             */
/*   Updated: 2023/03/05 09:36:02 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft
{
    struct false_type
    {
        static const bool value = false;
        typedef bool value_type;
    };

    struct true_type
    {
        static const bool value = true;
        typedef bool value_type;
    };
    
    template <class T>
    struct is_integral : false_type {};
    
    template <>
    struct is_integral<bool> : true_type {};
    
    template <>
    struct is_integral<const bool> : true_type {};
    template <>
    struct is_integral<volatile bool> : true_type {};
    template <>
    struct is_integral<const volatile bool> : true_type {};
    
    template <>
    struct is_integral<char> : true_type {};
    
    template <>
    struct is_integral<const char> : true_type {};
    template <>
    struct is_integral<volatile char> : true_type {};
    template <>
    struct is_integral<const volatile char> : true_type {};
    
    template <>
    struct is_integral<char16_t> : true_type {};
    
    template <>
    struct is_integral<const char16_t> : true_type {};
    template <>
    struct is_integral<volatile char16_t> : true_type {};
    template <>
    struct is_integral<const volatile char16_t> : true_type {};
    
    template <>
    struct is_integral<char32_t> : true_type {};
    
    template <>
    struct is_integral<const char32_t> : true_type {};
    template <>
    struct is_integral<volatile char32_t> : true_type {};
    template <>
    struct is_integral<const volatile char32_t> : true_type {};
    
    template <>
    struct is_integral<wchar_t> : true_type {};
    
    template <>
    struct is_integral<const wchar_t> : true_type {};
    template <>
    struct is_integral<volatile wchar_t> : true_type {};
    template <>
    struct is_integral<const volatile wchar_t> : true_type {};
    
    template <>
    struct is_integral<signed char> : true_type {};
    
    template <>
    struct is_integral<const signed char> : true_type {};
    template <>
    struct is_integral<volatile signed char> : true_type {};
    template <>
    struct is_integral<const volatile signed char> : true_type {};
    
    template <>
    struct is_integral<short int> : true_type {};
    
    template <>
    struct is_integral<const short int> : true_type {};
    template <>
    struct is_integral<volatile short int> : true_type {};
    template <>
    struct is_integral<const volatile short int> : true_type {};
    
    template <>
    struct is_integral<int> : true_type {};
    
    template <>
    struct is_integral<const int> : true_type {};
    template <>
    struct is_integral<volatile int> : true_type {};
    template <>
    struct is_integral<const volatile int> : true_type {};
    
    template <>
    struct is_integral<long int> : true_type {};
    
    template <>
    struct is_integral<const long int> : true_type {};
    template <>
    struct is_integral<volatile long int> : true_type {};
    template <>
    struct is_integral<const volatile long int> : true_type {};
    
    template <>
    struct is_integral<long long int> : true_type {};
    
    template <>
    struct is_integral<const long long int> : true_type {};
    template <>
    struct is_integral<volatile long long int> : true_type {};
    template <>
    struct is_integral<const volatile long long int> : true_type {};
    
    template <>
    struct is_integral<unsigned char> : true_type {};
    
    template <>
    struct is_integral<const unsigned char> : true_type {};
    template <>
    struct is_integral<volatile unsigned char> : true_type {};
    template <>
    struct is_integral<const volatile unsigned char> : true_type {};
    
    template <>
    struct is_integral<unsigned short int> : true_type {};
    
    template <>
    struct is_integral<const unsigned short int> : true_type {};
    template <>
    struct is_integral<volatile unsigned short int> : true_type {};
    template <>
    struct is_integral<const volatile unsigned short int> : true_type {};
    
    template <>
    struct is_integral<unsigned int> : true_type {};
    
    template <>
    struct is_integral<const unsigned int> : true_type {};
    template <>
    struct is_integral<volatile unsigned int> : true_type {};
    template <>
    struct is_integral<const volatile unsigned int> : true_type {};
    
    template <>
    struct is_integral<unsigned long int> : true_type {};
    
    template <>
    struct is_integral<const unsigned long int> : true_type {};
    template <>
    struct is_integral<volatile unsigned long int> : true_type {};
    template <>
    struct is_integral<const volatile unsigned long int> : true_type {};
    
    template <>
    struct is_integral<unsigned long long int> : true_type {};
    
    template <>
    struct is_integral<const unsigned long long int> : true_type {};
    template <>
    struct is_integral<volatile unsigned long long int> : true_type {};
    template <>
    struct is_integral<const volatile unsigned long long int> : true_type {};
}
#endif
