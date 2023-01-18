/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:27:34 by momeaizi          #+#    #+#             */
/*   Updated: 2023/01/18 12:14:39 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"


class   A
{
    public:
        A() {std::cout << "default constructor" << std::endl; }
        ~A() {std::cout << "destructor" << std::endl; }
        A(const A &) {std::cout << "copy constructor" << std::endl; }
        A &operator=(const A &){std::cout << "copy assignement operator" << std::endl; return *this;}
};

int main()
{
    // {
    //     std::cout << "\n\nfill constructor without a value\n" << std::endl;
    //     vector<A> vec(100);
    //     std::cout << "\n\ncopy constructor\n" << std::endl;
    //     vector<A> vec_copy(vec);
    // }
    // std::cout << "********************" << std::endl;
    // {
    //     std::cout << "\n\nfill constructor with a value\n" << std::endl;
    //     vector<A> vec(100, A());
    //     std::cout << "\n\ncopy constructor\n" << std::endl;
    //     vector<A> vec_copy(vec);
    // }
    // std::cout << "********************" << std::endl;
    // {
    //     A   range[] = {A(), A(), A(), A(), A(), A(), A(), A()};
    //     std::cout << "\n\nfill range constructor\n" << std::endl;
    //     vector<A> vec(range, range + 8);
    //     std::cout << "\n\ncopy constructor\n" << std::endl;
    //     vector<A> vec_copy(vec);
    // }
    std::cout << "********************" << std::endl;
    {
        std::cout << "\n\nassign\n" << std::endl;
        std::vector<A> vec(5);
    std::cout << "********************" << std::endl;
        vec.assign(10, A());
    std::cout << "********************" << std::endl;
    }
    // std::cout << "********************" << std::endl;
    // {
    //     // A   range[] = {A(), A(), A(), A(), A(), A(), A(), A()};
    //     std::cout << "\n\nassign range\n" << std::endl;
    //     vector<A> vec.assign(range, range + 8)
    // }
}
