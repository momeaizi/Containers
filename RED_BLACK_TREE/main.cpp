/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:07:35 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/23 11:10:39 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "red_bleck_tree.hpp"
#include <string>

int main()
{
    redBlackTree <int, int64_t>    t;


    t.insert(t.createNode(20, 20));
    // t.insert(t.createNode(21, 21));
    // t.insert(t.createNode(27, 27));
    t.printBT();
}