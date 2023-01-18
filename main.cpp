/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:27:34 by momeaizi          #+#    #+#             */
/*   Updated: 2023/01/18 22:18:01 by momeaizi         ###   ########.fr       */
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
    {
        std::cout << "\n\nfill constructor without a value\n" << std::endl;
        std::vector<A> vec(100);
        std::cout << "\n\ncopy constructor\n" << std::endl;
        std::vector<A> vec_copy(vec);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
    }
    std::cout << "********************" << std::endl;
    {
        std::cout << "\n\nfill constructor with a value\n" << std::endl;
        std::vector<A> vec(100, A());
        std::cout << "\n\ncopy constructor\n" << std::endl;
        std::vector<A> vec_copy(vec);
        std::cout << "capacity -> " << vec.capacity() << std::endl;
        std::cout << "size     -> " << vec.size()  << std::endl;
    }
    std::cout << "********************" << std::endl;
    {
        A   range[] = {A(), A(), A(), A(), A(), A(), A(), A()};
        std::cout << "\n\nfill range constructor\n" << std::endl;
        try
        {
            std::vector<A> vec(range, range - 8);
        }
        catch (const std::length_error &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::vector<A> vec(range, range + 8);
        std::cout << "\n\ncopy constructor\n" << std::endl;
        std::vector<A> vec_copy(vec);
        std::cout << "capacity -> " << vec.capacity() << std::endl;
        std::cout << "size     -> " << vec.size()  << std::endl;
    }
    std::cout << "********************" << std::endl;
    {
        {
            std::cout << "\n\nassign capacity >= n\n" << std::endl;
            std::vector<A> vec(10);
            vec.assign(5, A());
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
            std::cout << "\n\nassign capacity < n\n" << std::endl;
            std::vector<A> vec(5);
            vec.assign(10, A());
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
            std::cout << "\n\nassign capacity < n\n" << std::endl;
            std::vector<A> vec(5);
            vec.assign(0, A());
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
    }
    std::cout << "********************" << std::endl;
    {
        {
                std::vector<A> vec(8);
                A   range[] = {A(), A(), A(), A()};
                std::cout << "\n\nassign capacity >= n\n" << std::endl;

                vec.assign(range, range + 4);
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
                std::vector<A> vec(2);
                A   range[] = {A(), A(), A(), A()};
                std::cout << "\n\nassign capacity < n\n" << std::endl;
                vec.assign(range, range + 4);
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
        }
                
        {
                std::vector<A> vec(1);
                A   range[] = {A(), A(), A(), A()};
                std::cout << "\n\nassign 1\n" << std::endl;
                vec.assign(range, range);
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
                std::vector<A> vec(2);
                A   range[] = {A(), A(), A(), A()};
                std::cout << "\n\nassign exception\n" << std::endl;
                try
                {
                    vec.assign(range, range - 1);
                }
                catch (const std::length_error &e)
                {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
        }
    }
    // system("leaks Containers");
}
