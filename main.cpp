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

    ft::map<std::string, int>::reverse_iterator rit = list.rbegin();

    for (; rit != list.rend(); ++rit)
        std::cout << rit->first << " " << rit->second << std::endl;


}
