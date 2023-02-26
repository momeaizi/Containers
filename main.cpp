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



#include <iostream>
#include <type_traits>
#include <vector>
#include <unistd.h>
#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include "map/map.hpp"
#include "map"
#include "iterator/iterators.hpp"


int main()
{

    ft::map<std::string, int>   list;

    list["taha"] = 20;
    list["mounaim"] = 21;
    list["amine"] = 19;

    
    ft::pair<std::string, int> arr[] = {ft::make_pair("ahmed", 27), ft::make_pair("taha", 20), ft::make_pair("hamid", 36)};

    list.insert(arr, arr + 3);

    ft::map<std::string, int>::iterator   it = list.begin();

    for (; it != list.end(); ++it)
        std::cout << it->first << " " << it->second << std::endl;


    ft::map<std::string, int>   list1(list);

    it = list1.begin();

    std::cout << std::endl;

    for (; it != list.end(); ++it)
        std::cout << it->first << " " << it->second << std::endl;
    
}
