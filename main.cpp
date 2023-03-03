/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:27:34 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/16 15:50:50 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include <type_traits>
#include <vector>
#include <unistd.h>
#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include "map/map.hpp"
#include <random>
#include <sstream>
#include "iterator/iterators.hpp"

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 4 // the ft::map methods can be slower up to std::map methods * TIME_FAC (MAX 20)

template <typename Iter1, typename Iter2>
bool comparemaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    return true;
}

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

#include <iostream>
#include <map>


int main ()
{
    ft::map<int, std::string> m1;

    for (size_t i = 0; i < 1000; i++)
    {
        m1.insert(ft::make_pair(i, "string2"));
    }


    m1.erase(m1.begin(), m1.end());

    ft::map<int, std::string>::iterator it = m1.begin();

    for (;it != m1.end(); ++it)
        std::cout << it->first << " " << it->second << std::endl;

    // system("leaks a.out");

    return 0;
}
