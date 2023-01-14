/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:27:34 by momeaizi          #+#    #+#             */
/*   Updated: 2023/01/14 18:52:26 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"


class   A
{
    public:
        A() {std::cout << "default" << std::endl; }
        A(const A &) {std::cout << "copy" << std::endl; }
};

int main()
{
    // std::vector<int>  vec;
    const vector<int>  vec1;

    int a = vec1.back();

    std::cout << a << std::endl;
    
}
