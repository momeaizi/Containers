/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:12:01 by momeaizi          #+#    #+#             */
/*   Updated: 2023/03/08 16:19:27 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <vector>
#include "../vector/vector.hpp"


int	vector_tests()
{
std::cout << std::endl << "[[" << std::setw(40) << "assign			]]" << std::endl << std::endl;
// vector assign

{
  ft::vector<int> first;
  ft::vector<int> second;
  ft::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  ft::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
  }
std::cout << std::endl << "[[" << std::setw(40) << "at			]]" << std::endl << std::endl;
// vector::at

{
  ft::vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "back			]]" << std::endl << std::endl;
// vector::back

{
  ft::vector<int> myvector;

  myvector.push_back(10);

  while (myvector.back() != 0)
  {
    myvector.push_back ( myvector.back() -1 );
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size() ; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "begin			]]" << std::endl << std::endl;
// vector::begin/end

{
  ft::vector<int> myvector;
  for (size_t i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "capacity			]]" << std::endl << std::endl;
// comparing size, capacity and max_size

{
  ft::vector<int> myvector;

  // set some content in the vector:
  for (size_t i=0; i<100; i++) myvector.push_back(i);

  std::cout << "size: " << (int) myvector.size() << '\n';
  std::cout << "capacity: " << (int) myvector.capacity() << '\n';
  std::cout << "max_size: " << (int) myvector.max_size() << '\n';
  }
std::cout << std::endl << "[[" << std::setw(40) << "clear			]]" << std::endl << std::endl;
// clearing vectors

{
  ft::vector<int> myvector;
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  myvector.clear();
  myvector.push_back (1101);
  myvector.push_back (2202);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "empty			]]" << std::endl << std::endl;
// vector::empty

{
  ft::vector<int> myvector;
  int sum (0);

  for (size_t i=1;i<=10;i++) myvector.push_back(i);

  while (!myvector.empty())
  {
     sum += myvector.back();
     myvector.pop_back();
  }

  std::cout << "total: " << sum << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "end			]]" << std::endl << std::endl;
// vector::begin/end

{
  ft::vector<int> myvector;
  for (size_t i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "end			]]" << std::endl << std::endl;
// vector::begin/end

{
  ft::vector<int> myvector;
  for (size_t i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "erase			]]" << std::endl << std::endl;
// erasing from vector

{
  ft::vector<int> myvector;

  // set some values (from 1 to 10)
  for (size_t i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  myvector.erase (myvector.begin()+5);

  // erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "front			]]" << std::endl << std::endl;
// vector::front

{
  ft::vector<int> myvector;

  myvector.push_back(78);
  myvector.push_back(16);

  // now front equals 78, and back 16

  myvector.front() -= myvector.back();

  std::cout << "myvector.front() is now " << myvector.front() << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "get_allocator			]]" << std::endl << std::endl;
// vector::get_allocator

{
  ft::vector<int> myvector;
  int * p;
  unsigned int i;

  // allocate an array with space for 5 elements using vector's allocator:
  p = myvector.get_allocator().allocate(5);

  // construct values in-place on the array:
  for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

  std::cout << "The allocated array contains:";
  for (i=0; i<5; i++) std::cout << ' ' << p[i];
  std::cout << '\n';

  // destroy and deallocate:
  for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
  myvector.get_allocator().deallocate(p,5);

  }
std::cout << std::endl << "[[" << std::setw(40) << "insert			]]" << std::endl << std::endl;
// inserting into a vector

{
  ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  ft::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "max_size			]]" << std::endl << std::endl;
// comparing size, capacity and max_size

{
  ft::vector<int> myvector;

  // set some content in the vector:
  for (size_t i=0; i<100; i++) myvector.push_back(i);

  std::cout << "size: " << myvector.size() << "\n";
  std::cout << "capacity: " << myvector.capacity() << "\n";
  std::cout << "max_size: " << myvector.max_size() << "\n";
  }
std::cout << std::endl << "[[" << std::setw(40) << "operator[]			]]" << std::endl << std::endl;
// vector::operator[]

{
  ft::vector<int> myvector (10);   // 10 zero-initialized elements

  ft::vector<int>::size_type sz = myvector.size();

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

  }
std::cout << std::endl << "[[" << std::setw(40) << "operator=			]]" << std::endl << std::endl;
// vector assignment

{
  ft::vector<int> foo (3,0);
  ft::vector<int> bar (5,0);

  bar = foo;
  foo = ft::vector<int>();

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';
  }
std::cout << std::endl << "[[" << std::setw(40) << "pop_back			]]" << std::endl << std::endl;
// vector::pop_back

{
  ft::vector<int> myvector;
  int sum (0);
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  while (!myvector.empty())
  {
    sum+=myvector.back();
    myvector.pop_back();
  }

  std::cout << "The elements of myvector add up to " << sum << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "push_back			]]" << std::endl << std::endl;
// vector::push_back

{
  ft::vector<int> myvector;
  int myint = 365;

  std::cout << "Please enter some integers (enter 0 to end):\n";

  do {
    myvector.push_back (myint--);
  } while (myint);

  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";

  }
std::cout << std::endl << "[[" << std::setw(40) << "rbegin			]]" << std::endl << std::endl;
// vector::rbegin/rend

{
  ft::vector<int> myvector (5);  // 5 default-constructed ints

  int i=0;

  ft::vector<int>::reverse_iterator rit = myvector.rbegin();
  for (; rit!= myvector.rend(); ++rit)
    *rit = ++i;

  std::cout << "myvector contains:";
  for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "rend			]]" << std::endl << std::endl;
// vector::rbegin/rend

{
  ft::vector<int> myvector (5);  // 5 default-constructed ints

  ft::vector<int>::reverse_iterator rit = myvector.rbegin();

  int i=0;
  for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
    *rit = ++i;

  std::cout << "myvector contains:";
  for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "reserve			]]" << std::endl << std::endl;
// vector::reserve

{
  ft::vector<int>::size_type sz;

  ft::vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (size_t i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  ft::vector<int> bar;
  sz = bar.capacity();
  bar.reserve(100);   // this is the only difference with foo above
  std::cout << "making bar grow:\n";
  for (size_t i=0; i<100; ++i) {
    bar.push_back(i);
    if (sz!=bar.capacity()) {
      sz = bar.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
  }
std::cout << std::endl << "[[" << std::setw(40) << "resize			]]" << std::endl << std::endl;
// resizing vector

{
  ft::vector<int> myvector;

  // set some initial content:
  for (size_t i=1;i<10;i++) myvector.push_back(i);

  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);

  std::cout << "myvector contains:";
  for (size_t i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "size			]]" << std::endl << std::endl;
// vector::size

{
  ft::vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (size_t i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.insert (myints.end(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';

  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "swap			]]" << std::endl << std::endl;
// swap vectors

{
  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';

  }
std::cout << std::endl << "[[" << std::setw(40) << "operators			]]" << std::endl << std::endl;
// vector comparisons

{
  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (2,200);   // two ints with a value of 200

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

  }
std::cout << std::endl << "[[" << std::setw(40) << "swap-free			]]" << std::endl << std::endl;
// swap (vector overload)

{
  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  }
  return 0;
}
