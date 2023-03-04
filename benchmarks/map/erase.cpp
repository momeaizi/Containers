/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:31:42 by mleblanc          #+#    #+#             */
/*   Updated: 2022/05/23 20:07:08 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_prelude.hpp"
#include <iterator>

int main()
{
    SETUP;

    NAMESPACE::map<int, int> data;

    for (std::size_t i = 0; i < MAXSIZE / 2; ++i) {
        data.insert(NAMESPACE::make_pair(rand(), rand()));
    }

    NAMESPACE::map<int, int> m(data);

    timer t;
    for (int i = 0; i < 300000; ++i) {
        m.erase(m.begin());
    }

    for (int i = 0; i < 1000000; ++i) {
        NAMESPACE::map<int, int>::iterator it = m.begin();
        std::advance(it, i % 2 == 0 ? 2400 : 3064);
        m.erase(it);
    }

    for (int i = 0; i < 100000; ++i) {
        NAMESPACE::map<int, int>::iterator it = m.end();
        std::advance(it, i % 2 == 0 ? -1 : -364);
        m.erase(it);
    }

    PRINT_TIME(t);
}
