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

void testIterators()
{
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " find method "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond(true);
        {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::map<int, std::string> ft_m1;
            for (size_t i = 0; i < 1e6; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair(i, "string2"));
            }

            start = get_time();

            for (size_t i = 1e1; i < 1e5; i += 10)
                m1.find(i);

            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            for (size_t i = 1e1; i < 1e5; i += 10)
                ft_m1.find(i);
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }

        std::vector<int> vec;
        std::vector<int> ft_vec;
        std::random_device randDev;
        std::mt19937 generator(randDev());
        std::uniform_int_distribution<int> distr(0, 1e8);

        std::map<int, std::string> m1;
        ft::map<int, std::string> ft_m1;
        std::map<int, std::string>::iterator it;
        ft::map<int, std::string>::iterator ft_it;

        for (size_t i = 0; i < 1e6; i++)
        {
            m1.insert(std::make_pair(i, "string2"));
            ft_m1.insert(ft::make_pair(i, "string2"));
        }

        for (size_t i = 0; i < 1e6; i++)
        {
            int n = distr(generator);
            it = m1.find(n);
            ft_it = ft_m1.find(n);
            if (it == m1.end() && ft_it == ft_m1.end())
                continue;
            if (it == m1.end() && ft_it != ft_m1.end())
            {
                cond = false;
                break;
            }
            else
            {
                vec.push_back(it->first);
                ft_vec.push_back(ft_it->first);
            }
        }
        std::map<char, int> m;
        ft::map<char, int> ft_m;
        std::map<char, int>::iterator it2;
        ft::map<char, int>::iterator ft_it2;

        m['a'] = 50;
        m['b'] = 100;
        m['c'] = 150;
        m['d'] = 200;

        ft_m['a'] = 50;
        ft_m['b'] = 100;
        ft_m['c'] = 150;
        ft_m['d'] = 200;

        it2 = m.find('b');
        ft_it2 = ft_m.find('b');

        cond = cond && it2->first == ft_it2->first && it2->second == ft_it2->second;

        if (it2 != m.end())
            m.erase(it2);
        if (ft_it2 != ft_m.end())
            ft_m.erase(ft_it2);

        cond = cond && comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());
        it2 = m.begin();
        ft_it2 = ft_m.begin();
        for (; it2 != m.end(); ++it2)
            std::cout << it2->first << " " << it2->second << std::endl;
        std::cout << std::endl;
        for (; ft_it2 != ft_m.end(); ++ft_it2)
            std::cout << ft_it2->first << " " << ft_it2->second << std::endl;

        EQUAL(cond && vec == ft_vec);
    }
}


int main ()
{
    testIterators();

    return 0;
}
