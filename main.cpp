/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:27:34 by momeaizi          #+#    #+#             */
/*   Updated: 2023/01/20 18:52:28 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <unistd.h>
#include "vector.hpp"


class   A
{
    public:
        static  int i;
        int id;
        A() {
            std::cout << "default constructor" << std::endl;
            id = i++;
        }
        ~A() {
            std::cout << "destructor -> " << id << std::endl; 
            }
        A(const A &x) {
            std::cout << "copy constructor -> " << x.id << std::endl;
            id = x.id;
            }
        A &operator=(const A &x) {
            std::cout << "copy assignement operator -> " << x.id << std::endl;
            id = x.id;
            return *this;
            }
};

int A::i = 0;

int main()
{
    {
        std::cout << "\n\nfill constructor without a value\n" << std::endl;
        std::vector<A> vec(10);
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
            std::cout << "\n\nassign  n = 0\n" << std::endl;
            std::vector<A> vec(5);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
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
        {
            int arr[] = {3, 6};
                std::vector<int> vec(arr, arr + 2);
                std::cout << "\n\nat function\n" << std::endl;
                try
                {
                    std::cout << vec.at(0) << std::endl;
                    std::cout << vec.at(1) << std::endl;
                    std::cout << vec.at(2) << std::endl;
                }
                catch (const std::out_of_range &e)
                {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
                std::vector<A> vec(4);
                std::cout << "\n\nat function\n" << std::endl;
                try
                {
                    vec.at(3);
                    vec.at(4);
                }
                catch (const std::out_of_range &e)
                {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
                std::vector<int> vec(4);
                std::cout << "\n\nback function\n" << std::endl;
                
                std::cout << vec.back() << std::endl;
                
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
                std::vector<int> vec;
                std::cout << "\n\nback function\n" << std::endl;
                
                // std::cout << vec.back() << std::endl;
                
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
            std::cout << "\n\begin and end  functions\n" << std::endl;
            {
                int arr[] = {1, 2, 3, 4, 5};
                std::vector<int>    myvector(arr, arr + 5);

                std::cout << "myvector contains:";
                for ( std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
                std::cout << ' ' << *it;
                std::cout << std::endl;
                std::cout << "capacity -> " << myvector.capacity() << std::endl;
                std::cout << "size     -> " << myvector.size()  << std::endl;
            }
            {
                std::vector<int>    myvector;

                std::cout << "myvector contains:";
                for ( std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
                std::cout << ' ' << *it;
                std::cout << std::endl;
                std::cout << "capacity -> " << myvector.capacity() << std::endl;
                std::cout << "size     -> " << myvector.size()  << std::endl;
            }
        }
        {
            std::cout << "\n\nempty  functions\n" << std::endl;
            std::vector<int> vec;
            std::cout << vec.empty() << std::endl;
            
            std::vector<int> vec1(2);
            std::cout << vec1.empty() << std::endl;
            std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
            std::cout << "\n\nfront  functions\n" << std::endl;
            int arr[] = {78, 16};
            std::vector<int> myvector(arr, arr + 2);

            myvector.front() -= myvector.back();

            std::cout << "myvector.front() is now " << myvector.front() << '\n';
            std::cout << "capacity -> " << myvector.capacity() << std::endl;
                std::cout << "size     -> " << myvector.size()  << std::endl;
        }
        {
            std::cout << "\n\n[]  functions\n" << std::endl;
            std::vector<int> myvector (10);   // 10 zero-initialized elements

            std::vector<int>::size_type sz = myvector.size();

            // assign some values:
            for (unsigned i=0; i<sz; i++) myvector[i]=i;

            // reverse std::vector using operator[]:
            for (unsigned i=0; i<sz/2; i++)
            {
                int temp;
                temp = myvector[sz-1-i];
                myvector[sz-1-i]=myvector[i];
                myvector[i]=temp;
            }

            std::cout << "myvector contains:";
            for (unsigned i=0; i<sz; i++)
            std::cout << ' ' << myvector[i];
            std::cout << '\n';
            std::cout << "capacity -> " << myvector.capacity() << std::endl;
            std::cout << "size     -> " << myvector.size()  << std::endl;
        }
        {
            std::cout << "\n\n= operator \n" << std::endl;
            {
                std::vector<A>  vec(4);
                std::vector<A>  vec1(2);

                vec = vec1;
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
            }
            {
                std::vector<A>  vec(2);
                std::vector<A>  vec1(4);

                vec = vec1;
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
            }
            {
                std::vector<A>  vec;
                std::vector<A>  vec1(4);

                vec = vec1;
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
            }
            {
                std::vector<A>  vec(4);
                std::vector<A>  vec1;

                vec = vec1;
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
            }
            
        }
        {
            std::cout << "\n\nswap function \n" << std::endl;
            {
                std::vector<A>  vec(4);
                std::vector<A>  vec1(2);
            
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
                std::cout << "capacity -> " << vec1.capacity() << std::endl;
                std::cout << "size     -> " << vec1.size()  << std::endl;
                std::cout << "---------" << std::endl;
                vec.swap(vec1);
                std::cout << "---------" << std::endl;
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
                std::cout << "capacity -> " << vec1.capacity() << std::endl;
                std::cout << "size     -> " << vec1.size()  << std::endl;
            }
            {
                std::vector<std::string> foo (3,"foo");   // three std::strings with a value of foo
                std::vector<std::string> bar (5,"bar");
                
                foo.swap(bar);
                for (unsigned i=0; i<foo.size(); i++)
                    std::cout << ' ' << foo[i];
                std::cout << std::endl;

                std::cout << "bar contains:";
                for (unsigned i=0; i<bar.size(); i++)
                    std::cout << ' ' << bar[i];
                std::cout << std::endl;
            }
        }
        {
            std::cout << "\n\nrbegin & rend functions \n" << std::endl;
            
            {
                std::vector<int> myvector (5);  // 5 default-constructed ints
    
                int i=0;
    
                std::vector<int>::reverse_iterator rit = myvector.rbegin();
                for (; rit!= myvector.rend(); ++rit)
                    *rit = ++i;
    
                std::cout << "myvector contains:";
                for ( std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
                    std::cout << ' ' << *it;
                std::cout << std::endl;
            }
            {
                std::vector<int> myvector (5);  // 5 default-constructed ints

                std::vector<int>::reverse_iterator rit = myvector.rbegin();

                int i=0;
                for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
                    *rit = ++i;

                std::cout << "myvector contains:";
                for ( std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
                    std::cout << ' ' << *it;
                std::cout << std::endl;
            }
        }
        {
            std::cout << "\n\npush bach & pop back functions\n" << std::endl;
            {
                std::vector<A> myvector;
    
                for (int i = 0; i < 3; i++)
                    myvector.push_back (A());
            }
            {
                A   range[] = {A(),A(),A(),A(),A()};
                std::vector<A> myvector(range, range + 5);
    
                for (int i = 0; i < 5; i++)
                    myvector.push_back (A());
                for (unsigned long i = 0; i < myvector.size(); i++)
                    myvector.pop_back ();
                
            }
        }
    }
        return 0;
}

