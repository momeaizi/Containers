/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:07:35 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/23 23:10:25 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "red_black_tree.hpp"
#include <string>

int main()
{
    redBlackTree <int, int64_t>    t;


    t.insert(t.createNode(20, 20));
    t.insert(t.createNode(17, 19));
    t.insert(t.createNode(19, 18));
    t.insert(t.createNode(15, 18));
    t.insert(t.createNode(25, 18));
    t.insert(t.createNode(26, 18));
    t.insert(t.createNode(16, 18));
    t.printBT();
    // std::cout << "--------------------------------------" << std::endl;
}