/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:07:35 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/25 15:35:43 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "red_black_tree.hpp"
#include <string>
#include <map>
#include <unistd.h>
#include "../utils/pair.hpp"
#include "../map/map.hpp"

void    f()
{
    redBlackTree <int, int, std::greater<int> >    t1;
    {
        redBlackTree <int, int, std::greater<int> >    t;


        t.insert(make_pair(1, 1));
        t.insert(make_pair(2, 2));
        t.insert(make_pair(3, 3));
        t.insert(make_pair(4, 20));
        t.insert(make_pair(5, 5));
        t.insert(make_pair(6, 6));
        t.insert(make_pair(7, 7));
        t.insert(make_pair(8, 8));

        t.printBT();

        t1 = t;
    }
    t1.printBT();
}

int main()
{
    f();
    system("leaks a.out");
    // // IteratorTree<redBlackTree <int, int> >    it(t.__root);
    // // std::cout << "--------------------------------------" << std::endl;

    // // redBlackTree <int, int>::iterator   first(nullptr);
    // // redBlackTree <int, int>::iterator   last(t.findMax(t.__root));

    // // for(; first != last; --last)
    // // {
    // //     std::cout << last->key << " " << last->value << std::endl;
    // // }

    // redBlackTree <int, int>::Node   *p = t.findKey(4);

    // std::cout << p->value << std::endl;
}