/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:07:35 by momeaizi          #+#    #+#             */
/*   Updated: 2023/03/02 12:39:41 by momeaizi         ###   ########.fr       */
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
    redBlackTree <std::string, std::string >    m;

    m.insert(ft::make_pair("", ""));
    m.insert(ft::make_pair("123", "kjhgfdsdffghsfghdfgh"));
    m.insert(ft::make_pair("1234", "gfdsadgg"));
    m.insert(ft::make_pair("123456789123456789123456789", "49857459898674568464"));
    m.insert(ft::make_pair("0", "2345456456456456"));
    m.insert(ft::make_pair("000000000000000000000000", "1111111111111111111111111111"));

    m.print();
    redBlackTree <std::string, std::string >::Node *p = m.find("0");
    if (p)
        m.erase(p);
        
    std::cout << std::endl;
    m.print();
        
    p = m.find("1234");
    if (p)
        m.erase(p);

    std::cout << std::endl;
    m.print();

    
    p = m.find("000000000000000000000000");
    if (p)
        m.erase(p);

    std::cout << std::endl;
    m.print();
}

int main()
{
    f();

    
}