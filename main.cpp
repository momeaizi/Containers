/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:27:34 by momeaizi          #+#    #+#             */
/*   Updated: 2023/01/27 18:32:23 by momeaizi         ###   ########.fr       */
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
            id = i++;
            std::cout << "default constructor -> " << id<< std::endl;
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

int main1()
{

    return 1;
}

int main()
{
    {
        std::cout << "\n\nfill constructor without a value\n" << std::endl;
        vector<A> vec(10);
        std::cout << "\n\ncopy constructor\n" << std::endl;
        vector<A> vec_copy(vec);
        std::cout << "capacity -> " << vec.capacity() << std::endl;
        std::cout << "size     -> " << vec.size()  << std::endl;
    }
    std::cout << "********************" << std::endl;
    {
        std::cout << "\n\nfill constructor with a value\n" << std::endl;
        vector<A> vec(100, A());
        std::cout << "\n\ncopy constructor\n" << std::endl;
        vector<A> vec_copy(vec);
        std::cout << "capacity -> " << vec.capacity() << std::endl;
        std::cout << "size     -> " << vec.size()  << std::endl;
    }
    std::cout << "********************" << std::endl;
    {
        A   range[] = {A(), A(), A(), A(), A(), A(), A(), A()};
        std::cout << "\n\nfill range constructor\n" << std::endl;
        try
        {
            vector<A> vec(range, range - 8);
        }
        catch (const std::length_error &e)
        {
            std::cout << e.what() << std::endl;
        }
        vector<A> vec(range, range + 8);
        std::cout << "\n\ncopy constructor\n" << std::endl;
        vector<A> vec_copy(vec);
        std::cout << "capacity -> " << vec.capacity() << std::endl;
        std::cout << "size     -> " << vec.size()  << std::endl;
    }
    std::cout << "********************" << std::endl;
    {
        {
            std::cout << "\n\nassign capacity >= n\n" << std::endl;
            vector<A> vec(10);
            vec.assign(5, A());
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
            std::cout << "\n\nassign capacity < n\n" << std::endl;
            vector<A> vec(5);
            vec.assign(10, A());
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
            std::cout << "\n\nassign  n = 0\n" << std::endl;
            vector<A> vec(5);
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
                vector<A> vec(8);
                A   range[] = {A(), A(), A(), A()};
                std::cout << "\n\nassign capacity >= n\n" << std::endl;

                vec.assign(range, range + 4);
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
                vector<A> vec(2);
                A   range[] = {A(), A(), A(), A()};
                std::cout << "\n\nassign capacity < n\n" << std::endl;
                vec.assign(range, range + 4);
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
        }
                
        {
                vector<A> vec(1);
                A   range[] = {A(), A(), A(), A()};
                std::cout << "\n\nassign 1\n" << std::endl;
                vec.assign(range, range);
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
                vector<A> vec(2);
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
                vector<int> vec(arr, arr + 2);
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
                vector<A> vec(4);
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
                vector<int> vec(4);
                std::cout << "\n\nback function\n" << std::endl;
                
                std::cout << vec.back() << std::endl;
                
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
                vector<int> vec;
                std::cout << "\n\nback function\n" << std::endl;
                
                // std::cout << vec.back() << std::endl;
                
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
            std::cout << "\n\begin and end  functions\n" << std::endl;
            {
                int arr[] = {1, 2, 3, 4, 5};
                vector<int>    myvector(arr, arr + 5);

                std::cout << "myvector contains:";
                for ( vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
                std::cout << ' ' << *it;
                std::cout << std::endl;
                std::cout << "capacity -> " << myvector.capacity() << std::endl;
                std::cout << "size     -> " << myvector.size()  << std::endl;
            }
            {
                vector<int>    myvector;

                std::cout << "myvector contains:";
                for ( vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
                std::cout << ' ' << *it;
                std::cout << std::endl;
                std::cout << "capacity -> " << myvector.capacity() << std::endl;
                std::cout << "size     -> " << myvector.size()  << std::endl;
            }
        }
        {
            std::cout << "\n\nempty  functions\n" << std::endl;
            vector<int> vec;
            std::cout << vec.empty() << std::endl;
            
            vector<int> vec1(2);
            std::cout << vec1.empty() << std::endl;
            std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
            std::cout << "\n\nfront  functions\n" << std::endl;
            int arr[] = {78, 16};
            vector<int> myvector(arr, arr + 2);

            myvector.front() -= myvector.back();

            std::cout << "myvector.front() is now " << myvector.front() << '\n';
            std::cout << "capacity -> " << myvector.capacity() << std::endl;
                std::cout << "size     -> " << myvector.size()  << std::endl;
        }
        {
            std::cout << "\n\n[]  functions\n" << std::endl;
            vector<int> myvector (10);   // 10 zero-initialized elements

            vector<int>::size_type sz = myvector.size();

            // assign some values:
            for (unsigned i=0; i<sz; i++) myvector[i]=i;

            // reverse vector using operator[]:
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
                vector<A>  vec(4);
                vector<A>  vec1(2);

                vec = vec1;
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
            }
            {
                vector<A>  vec(2);
                vector<A>  vec1(4);

                vec = vec1;
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
            }
            {
                vector<A>  vec;
                vector<A>  vec1(4);

                vec = vec1;
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
            }
            {
                vector<A>  vec(4);
                vector<A>  vec1;

                vec = vec1;
                std::cout << "capacity -> " << vec.capacity() << std::endl;
                std::cout << "size     -> " << vec.size()  << std::endl;
            }
            
        }
        {
            std::cout << "\n\nswap function \n" << std::endl;
            {
                vector<A>  vec(4);
                vector<A>  vec1(2);
            
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
                vector<std::string> foo (3,"foo");   // three std::strings with a value of foo
                vector<std::string> bar (5,"bar");
                
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
                vector<int> myvector (5);  // 5 default-constructed ints
    
                int i=0;
    
                vector<int>::reverse_iterator rit = myvector.rbegin();
                for (; rit!= myvector.rend(); ++rit)
                    *rit = ++i;
    
                std::cout << "myvector contains:";
                for ( vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
                    std::cout << ' ' << *it;
                std::cout << std::endl;
            }
            {
                vector<int> myvector (5);  // 5 default-constructed ints

                vector<int>::reverse_iterator rit = myvector.rbegin();

                int i=0;
                for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
                    *rit = ++i;

                std::cout << "myvector contains:";
                for ( vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
                    std::cout << ' ' << *it;
                std::cout << std::endl;
            }
        }
        {
            std::cout << "\n\npush bach & pop back functions\n" << std::endl;
            {
                vector<A> myvector;
    
                for (int i = 0; i < 3; i++)
                    myvector.push_back (A());
            }
            {
                A   range[] = {A(),A(),A(),A(),A()};
                vector<A> myvector(range, range + 5);
    
                for (int i = 0; i < 5; i++)
                    myvector.push_back (A());
                for (unsigned long i = 0; i < myvector.size(); i++)
                    myvector.pop_back ();
                
            }
        }
    }
    {
        std::cout << "\n\nresize function\n" << std::endl;
        {
            vector<A>  vec(7);
    
            vec.resize(2);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
            vector<A>  vec(7);
    
            vec.resize(2, A());
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
            vector<A>  vec(2);
            vec.resize(7);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
        
            vector<A>  vec(2);
            vec.resize(7, A());
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
            vector<A>  vec(2);
            vec.resize(2);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
        
            vector<A>  vec(2);
            vec.resize(2, A());
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
    }
    {
        std::cout << "\n\nerase function\n" << std::endl;
        {
            vector<A> myvector(6);
        
            myvector.erase (myvector.begin());
            myvector.erase (myvector.begin() + 2);
            // myvector.erase (myvector.begin() + 5);
            // myvector.erase (myvector.begin() - 1);
        }
        {
            vector<A> myvector(6);
    
            std::cout << "::::::::::::::::::::::" << std::endl;
        
            myvector.erase (myvector.begin() + 4, myvector.begin() + 5);
        
            std::cout << "::::::::::::::::::::::" << std::endl;
        }
    }
    {
        std::cout << "\n\nINSERT function\n" << std::endl;
        {
            vector<A> vec (4);
            vec.reserve(6);

            A a;
                std::cout << "\n\n*****************************\n" << std::endl;
            vec.insert(vec.begin() + 3, a);
                std::cout << "\n\n*****************************\n" << std::endl;
                std::cout << vec.capacity() << std::endl;
        }
        {
            vector<A> vec (4);
            vec.reserve(6);

            A a;
                std::cout << "\n\n*****************************\n" << std::endl;
            vec.insert(vec.begin() + 4, a);
                std::cout << "\n\n*****************************\n" << std::endl;
                std::cout << vec.capacity() << std::endl;
        }
        {
            vector<A> vec (4);
            vec.reserve(6);

            A a;
                std::cout << "\n\n*****************************\n" << std::endl;
            vec.insert(vec.begin(), a);
                std::cout << "\n\n*****************************\n" << std::endl;
                std::cout << vec.capacity() << std::endl;
        }
    }
    {
        std::cout << "\n\ninsert n function\n" << std::endl;
        {
            std::cout << "\nsize + n > capacity\n" << std::endl;
            vector<A>  vec(4);
            A   a;

            vec.insert(vec.end(), 4, a);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
            vec.insert(vec.begin(), 4, a);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
            vec.insert(vec.begin() + 2, 6, a);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
            std::cout << "\nsize + n <= capacity\n" << std::endl;
            vector<A>  vec(10);
            vec.reserve(300);
            A   a;

            vec.insert(vec.begin(), 4, a);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
            vec.insert(vec.begin() + 2, 7, a);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
            vec.insert(vec.end() - 3, 9, a);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
            vec.insert(vec.end(), 2, a);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
    }
    {
        std::cout << "\n\ninsert range function\n" << std::endl;
        A   a[] = {A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A()};
        {
            vector<A>  vec(4);
            std::cout << "\nsize + n > capacity\n" << std::endl;

            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
            vec.insert(vec.end(), a, a + 6);

            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
            vec.insert(vec.begin(), a, a + 4);

            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
            vec.insert(vec.begin() + 2, a, a + 7);
 

            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
            std::cout << "\nsize + n <= capacity\n" << std::endl;
            vector<A>  vec(10);
            vec.reserve(300);

            vec.insert(vec.begin(), a, a + 4);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;

            vec.insert(vec.begin() + 2, a, a + 2);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;

            vec.insert(vec.end() - 3, a, a + 9);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;

            vec.insert(vec.end(), a, a + 2);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
            
        }
    }
//     {
//         // std::cout << "\n\nnon member overloads\n" << std::endl;
//         {
//             vector<std::string> foo (3, "abc");
//             vector<std::string> bar (4, "abc");

//             if (foo==bar) std::cout << "foo and bar are equal\n";
//             if (foo!=bar) std::cout << "foo and bar are not equal\n";
//             if (foo< bar) std::cout << "foo is less than bar\n";
//             // if (foo> bar) std::cout << "foo is greater than bar\n";
//             if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//             // if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
//         }
//         {
//             vector<std::string> foo (4, "abc");
//             vector<std::string> bar (4, "abc");

//             if (foo==bar) std::cout << "foo and bar are equal\n";
//             if (foo!=bar) std::cout << "foo and bar are not equal\n";
//             if (foo< bar) std::cout << "foo is less than bar\n";
//         //     if (foo> bar) std::cout << "foo is greater than bar\n";
//             if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//         //     if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
//         }
//         {
//             vector<std::string> foo (4, "abc");
//             vector<std::string> bar (3, "abc");

//             if (foo==bar) std::cout << "foo and bar are equal\n";
//             if (foo!=bar) std::cout << "foo and bar are not equal\n";
//             if (foo< bar) std::cout << "foo is less than bar\n";
//         //     if (foo> bar) std::cout << "foo is greater than bar\n";
//             if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//         //     if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
//         }
//         {
//             vector<std::string> foo (3, "abd");
//             vector<std::string> bar (4, "abc");

//             if (foo==bar) std::cout << "foo and bar are equal\n";
//             if (foo!=bar) std::cout << "foo and bar are not equal\n";
//             if (foo< bar) std::cout << "foo is less than bar\n";
//         //     if (foo> bar) std::cout << "foo is greater than bar\n";
//             // if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//         //     if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
//         }
//         {
//             vector<std::string> foo (4, "abd");
//             vector<std::string> bar (4, "abc");

//             if (foo==bar) std::cout << "foo and bar are equal\n";
//             if (foo!=bar) std::cout << "foo and bar are not equal\n";
//             if (foo< bar) std::cout << "foo is less than bar\n";
// //             if (foo> bar) std::cout << "foo is greater than bar\n";
//             // if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
// //             if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
//         }
//         {
//             vector<std::string> foo (4, "abd");
//             vector<std::string> bar (3, "abc");

//             if (foo==bar) std::cout << "foo and bar are equal\n";
//             if (foo!=bar) std::cout << "foo and bar are not equal\n";
//             if (foo< bar) std::cout << "foo is less than bar\n";
// //             if (foo> bar) std::cout << "foo is greater than bar\n";
//             // if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
// //             if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
//         }
//     }
    return 0;
}

