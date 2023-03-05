/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 05:28:18 by momeaizi          #+#    #+#             */
/*   Updated: 2023/03/05 12:04:52 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <memory>
#include <iostream>
#include "red_black_tree.hpp"
#include "../iterator/iterator.hpp"
#include "../iterator/reverse_iterator.hpp"

namespace ft
{
    template < class T, class Compare, class Alloc>
    class set;

    template <class T, class Compare, class Alloc>
    void    swap (ft::set<T, Compare, Alloc> &x, ft::set<T, Compare, Alloc> &y);
}


template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
class ft::set
{
    private:
        redBlackTree<T, Compare, Alloc>     tree;
        typedef typename redBlackTree<T, Compare, Alloc>::Node                             node;
    public:
        typedef T                                                                               key_type;
        typedef T                                                                               value_type;
        typedef Compare                                                                         key_compare;
        typedef Alloc                                                                           allocator_type;
        typedef typename allocator_type::reference                                              reference;
        typedef typename allocator_type::const_reference                                        const_reference;
        typedef typename allocator_type::pointer                                                pointer;
        typedef typename allocator_type::const_pointer                                          const_pointer;
        typedef typename redBlackTree<T, Compare, Alloc>::iterator                              iterator;
        typedef typename redBlackTree<T, Compare, Alloc>::const_iterator                        const_iterator;
        typedef typename redBlackTree<T, Compare, Alloc>::reverse_iterator                      reverse_iterator;
        typedef typename redBlackTree<T, Compare, Alloc>::const_reverse_iterator                const_reverse_iterator;
        typedef std::ptrdiff_t                                                                  difference_type;
        typedef std::size_t                                                                     size_type;
        class value_compare
        {
            friend class set;
            protected:
                Compare comp;
                value_compare (Compare c) : comp(c) {}
            public:
                typedef bool            result_type;
                typedef value_type      first_argument_type;
                typedef value_type      second_argument_type;

                bool operator() (const value_type& x, const value_type& y) const
                {
                  return comp(x, y);
                }
        };


    public:
        explicit set (const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type())
        {
            (void)comp;
            (void)alloc;
        }

        template <class InputIterator>
        set (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type())
        {
            (void)comp;
            (void)alloc;

            for (; first != last; ++first)
            {
                if (tree.find(*first) == tree.nil)
                    tree.insert(*first);
            }
        }

        set (const set& x) : tree (x.tree) {}

        set &operator= (const set &x)
        {
            tree = x.tree;
            return *this;
        }

        ~set() {}

        iterator                        begin()
        {
            return tree.begin();
        }
        const_iterator                  begin() const
        {
            return tree.begin();
        }
        iterator                        end()
        {
            return tree.end();
        }
        const_iterator                  end() const
        {
            return tree.end();
        }
        void                            clear()
        {
            tree.clear();
        }
        size_type                       count (const value_type &val) const
        {
            if (tree.find(val) != tree.nil)
                return 1;
            return 0;
        }
        bool                            empty() const
        {
            return tree.empty();
        }
        ft::pair<iterator, iterator>    equal_range (const value_type &val) const
        {
            return ft::make_pair(lower_bound(val), upper_bound(val));
        }
        void                            erase (iterator position)
        {
            erase(*position);
        }
        size_type                       erase (const value_type &val)
        {
            node    *z = tree.find(val);

            if (z != tree.nil)
            {
                tree.erase(z);
                return 1;
            }
            return 0;
        }
        void                            erase (iterator first, iterator last)
        {
            while (first != last)
				erase(*(first++));
        }
        iterator                        find (const value_type &val) const
        {
            return iterator(tree.find(val), tree.nil, tree.max());
        }
        allocator_type                  get_allocator() const
        {
            return allocator_type();
        }
        ft::pair<iterator,bool>         insert (const value_type &val)
        {
            node    *p = tree.find(val);

            if (p != tree.nil)
                return ft::make_pair(iterator(p, tree.nil, tree.max()), false);
            tree.insert(val);
            p = tree.find(val);
            
            return ft::make_pair(iterator(p, tree.nil, tree.max()), true);
        }
        iterator                        insert (iterator position, const value_type &val)
        {
            (void) position;
            node    *p = tree.find(val);

            if (p != tree.nil)
                return iterator(p, tree.nil, tree.max());
            tree.insert(val);
            p = tree.find(val);
            
            return iterator(p, tree.nil, tree.max());
        }
        template <class InputIterator>
        void                            insert (InputIterator first, InputIterator last)
        {
            for (; first != last; ++first)
            {
                if (tree.find(*first) == tree.nil)
                    tree.insert(*first);
            }
        }
        key_compare                     key_comp() const
        {
            return key_compare();
        }
        iterator                        lower_bound (const value_type &val) const
        {
            node    *p = tree.lower_bound(val);
            return iterator(p, tree.nil, tree.max());
        }
        size_type                       max_size() const
        {
            return tree.max_size();
        }
        reverse_iterator                rbegin()
        {
            return tree.rbegin();
        }
        const_reverse_iterator          rbegin() const
        {
            return tree.rbegin();
        }
        reverse_iterator                rend()
        {
            return tree.rend();
        }
        const_reverse_iterator          rend() const
        {
            return tree.rend();
        }
        size_type                       size() const
        {
            return tree.size();
        }
        void                            swap (set &x)
        {
            tree.swap(x.tree);
        }
        iterator                        upper_bound (const value_type &val) const
        {
            node    *p = tree.upper_bound(val);
            return iterator(p, tree.nil, tree.max());
        }
        value_compare                   value_comp() const
        {
            return value_compare(key_compare());
        }

};


template <class T, class Compare, class Alloc>
void    ft::swap (ft::set<T, Compare, Alloc> &x, ft::set<T, Compare, Alloc> &y)
{
    x.swap(y);
}

template <class T, class Compare, class Alloc>
    bool    operator== ( const ft::set<T, Compare, Alloc>& lhs,
                        const ft::set<T, Compare, Alloc>& rhs )
{
    if (lhs.size() != rhs.size())
        return false;

    typename ft::set<T, Compare, Alloc>::const_iterator   it = lhs.begin();
    typename ft::set<T, Compare, Alloc>::const_iterator   it1 = rhs.begin();
    
    while (it != lhs.end())
    {
        if (*it != *it1)
            return false;
        ++it;
        ++it1;
    }
    return true;
}

template <class T, class Compare, class Alloc>
    bool    operator!= ( const ft::set<T, Compare, Alloc>& lhs,
                        const ft::set<T, Compare, Alloc>& rhs )
{
    return !(lhs == rhs);
}

template <class T, class Compare, class Alloc>
    bool    operator<  ( const ft::set<T, Compare, Alloc>& lhs,
                        const ft::set<T, Compare, Alloc>& rhs )
{
    typename ft::set<T, Compare, Alloc>::const_iterator   it = lhs.begin();
    typename ft::set<T, Compare, Alloc>::const_iterator   it1 = rhs.begin();

    while (it != lhs.end() && it1 != rhs.end())
    {
        if (*it < *it1) return true;
        if (*it > *it1) return false;
        ++it;
        ++it1;
    }
    if (lhs.size() < rhs.size())
        return true;
    return false;
}

template <class T, class Compare, class Alloc>
    bool    operator<= ( const ft::set<T, Compare, Alloc>& lhs,
                        const ft::set<T, Compare, Alloc>& rhs )
{
    return !(rhs < lhs);
}

template <class T, class Compare, class Alloc>
    bool    operator>  ( const ft::set<T, Compare, Alloc>& lhs,
                        const ft::set<T, Compare, Alloc>& rhs )
{
    return rhs < lhs;
}

template <class T, class Compare, class Alloc>
    bool operator>= ( const ft::set<T,Compare,Alloc>& lhs,
                        const ft::set<T,Compare,Alloc>& rhs )
{
    return !(lhs < rhs);
}



#endif
