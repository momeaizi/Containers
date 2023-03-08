/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:12:09 by momeaizi          #+#    #+#             */
/*   Updated: 2023/03/08 16:19:27 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <stack>
#include "../stack/stack.hpp"

int stack_tests()
{
std::cout << std::endl << "[[" << std::setw(40) << "empty			]]" << std::endl << std::endl;
// stack::empty

{
  ft::stack<int> mystack;
  int sum (0);

  for (size_t i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "pop			]]" << std::endl << std::endl;
// stack::push/pop

{
  ft::stack<int> mystack;

  for (size_t i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "top			]]" << std::endl << std::endl;
// stack::top

{
  ft::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "push			]]" << std::endl << std::endl;
// stack::push/pop

{
  ft::stack<int> mystack;

  for (size_t i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "size			]]" << std::endl << std::endl;
// stack::size

{
  ft::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (size_t i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "operators			]]" << std::endl << std::endl;
{
  ft::stack<int> foo;
  ft::stack<int> bar;

  for (size_t i = 0; i < 25; ++i)
  {
    foo.push(i * i);
    bar.push((i * i) / 25);
  }

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

  }
  return 0;
}
