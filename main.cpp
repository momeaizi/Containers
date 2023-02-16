/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
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
#include "iterator/iterators.hpp"


class   A
{
    public:
        static  int i;
        int id;
        A() {
            id = i++;
            // std::cout << "default constructor -> " << id<< std::endl;
        }
        ~A() {
            // std::cout << "destructor -> " << id << std::endl; 
            }
        A(const A &x) {
            // std::cout << "copy constructor -> " << x.id << std::endl;
            id = x.id;
            }
        A &operator=(const A &x) {
            // std::cout << "copy assignement operator -> " << x.id << std::endl;
            id = x.id;
            return *this;
            }
};

int A::i = 0;


    std::string b_string[64] = {                                                                   \
        "uvg6KqtcgduR31n3ajsv", "wbiAcjgojb9JOagZwyMn", "ATZKCzaPOqgkhPjwuGlf",                    \
        "MOhaJs56yjOw8f6nLPRA", "0gyB2Tr42v6awMw2nK7J", "e6GsiLFUuoDpVFEhJKZ1",                    \
        "z0jXAhiV9keBsaLOY0Xf", "P68p2ZAosHJdmoZh1C7N", "Pu3EuZVeY0TCO3ojdK0t",                    \
        "z7jCHMooHCS73M8GygKB", "uT4KoK83JrZxZjkul7ty", "g8gfrZoY5XwfzRusvHvv",                    \
        "7PGmkM0OSRnYREt9mFIP", "q1od7mBIpPEsCtpF9kdw", "XQo0LWId5TdZnLnpUNOb",                    \
        "U0m1R0kFFhAFyS6hmHHw", "K0lPKfxJxIOnE8QB90xn", "cZ5xyQifMJhrKxqBK9A7",                    \
        "cFBiwjfYw7Js6qEGy5Kt", "1tW0KWfXxeFO69tByqcE", "3Fvq9NxBrhPXHe0IlIVx",                    \
        "MSRDjdFRvHAhFGhiMtDe", "zGm2joMh71jQkYzg5L4V", "Mq4RRaeLvSAO0z2ibp8Q",                    \
        "WnLFYnQKP8TNJkqVVbUg", "E98UphbbVSzrW5Mzurmg", "F8HRxeEcaTZDkFPkioij",                    \
        "jmUVl4Q8X5BwVNzXN219", "n7Xp4w4FwzGKit7AI4SO", "4MxXYr6rKOcXLt9UkVd2",                    \
        "4RVTDsADtRyboaai9d29", "XaSqsrrtdhAfFoJIc5KK", "9Z9jdVCrTT09bg348ceb",                    \
        "I6uqLG9dO5mfNdSMwOYm", "UwMTzJPlbnhgwbHpDi6w", "DebjMP9afncYE6GhhO00",                    \
        "YGPuscYDiGfAjY1UWST0", "K6gbvgGjVZgEFUDlkdSk", "8xCBPI0w6TpC0RA62c2W",                    \
        "fYMxkNwmKg3moP8KvD9v", "QpPdhwhEYjIugg3OPcPH", "qQBXjSn43I3EMP54SyxZ",                    \
        "7qvdKwoW1CQEZTWPvuSC", "rCT212rdYO0zTGHXesKg", "dBHvlHsBwcR9MkkenYYG",                    \
        "NQiSlergqR8fVbOeivLj", "xYVqsV147UIe7jVBVwXo", "tcxayO4DdEJ885TbqUMy",                    \
        "9TGSMTD8U8ksRpHqq0cL", "TIJ16jCv9BSUiWvhbF9T", "BM9GL2ig1hePkA6lM6Ck",                    \
        "TfJTYB9JQMU6CGcYg20Q", "Fg6e5YT2FQbpTZNTDqdo", "LI5q6ml40MeE9H1dPb93",                    \
        "OaxJUSm3nYN9Y8Ela7sS", "BgBeODAwXz7xJo50Rwqd", "xdkgKj1dEoJ6zuVhkvvo",                    \
        "olIewtUEvXJgs1lB9bCn", "dTsPDS0x2uXtcgOIJHb8", "DYvJ2phLppGNZKboTBrd",                    \
        "DjNFMtt9PxkzqvWBHI6j", "1Z3YkeTFlPniKnzFhzgu", "76XqQg6hqMf5IXxKPOEs",                    \
        "gzaapTWW7i9EZjjzLeK6"                                                                     \
    }; 

int main() {
    std::vector<A>    v;

    v.push_back(A());
    v.push_back(A());
    v.push_back(A());
    A     arr[] = {A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A(), A()};
    std::cout << "*******************************" << std::endl;
    v.insert(v.begin() + 1, input_iterator<A>(arr), input_iterator<A>(arr + 60));
    std::cout << "*******************************\n\n" << std::endl;

    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i].id << " ";
    std::cout << std::endl;
}
