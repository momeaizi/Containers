/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:52:59 by momeaizi          #+#    #+#             */
/*   Updated: 2023/03/08 16:21:59 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;
#else
	#include "../vector/vector.hpp"
	#include "../stack/stack.hpp"
	#include "../map/map.hpp"
	#include "../set/set.hpp"

#endif

#include <iostream>
#include <iomanip>

int    vector_tests();
int    stack_tests();
int    map_tests();
int    set_tests();

int main()
{
    vector_tests();
    stack_tests();
    map_tests();
    set_tests();
}