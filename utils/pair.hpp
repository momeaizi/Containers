/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:50:06 by momeaizi          #+#    #+#             */
/*   Updated: 2023/03/01 05:10:45 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP


namespace ft
{
    template <class T1, class T2>
    struct  pair;

    template <class T1, class T2>
    ft::pair<T1, T2>    make_pair (T1 x, T2 y);
}

template <class T1, class T2>
struct ft::pair
{
    typedef T1      first_type;
    typedef T2      second_type;

    first_type      first;
    second_type     second;


    pair() : first (), second () {}

    template<class U, class V>
    pair (const ft::pair<U, V> &pr) : first(pr.first), second(pr.second) {}

    pair (const first_type &a, const second_type &b) : first(a), second(b) {}

    pair    &operator= (const pair &pr)
    {
        first = pr.first;
        second = pr.second;
        return *this;
    }
};


template <class T1, class T2>
    bool operator== (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) { return lhs.first == rhs.first && lhs.second == rhs.second; }

template <class T1, class T2>
    bool operator!= (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) { return !(lhs == rhs); }

template <class T1, class T2>
    bool operator<  (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) { return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second<rhs.second); }

template <class T1, class T2>
    bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return !(rhs<lhs); }

template <class T1, class T2>
    bool operator>  (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) { return rhs < lhs; }

template <class T1, class T2>
    bool operator>= (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) { return !(lhs < rhs); }





template <class T1, class T2>
ft::pair<T1, T2>    ft::make_pair (T1 x, T2 y)
{
    return ( ft::pair<T1, T2>(x, y) );
}


#endif
