/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:22:14 by momeaizi          #+#    #+#             */
/*   Updated: 2023/03/04 05:17:14 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP


#include <memory>
#include <stdexcept>
#include <iostream>
#include "../utils/pair.hpp"
#include "../red_black_tree/red_black_tree.hpp"

namespace ft
{
    template < class Key, class T, class Compare, class Alloc>
    class map;

    template <class Key, class T, class Compare, class Alloc>
    void    swap (ft::map<Key, T, Compare, Alloc> &x, ft::map<Key, T, Compare, Alloc> &y);
}


template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class ft::map
{
    private:
        typedef typename redBlackTree<Key, T, Compare, Alloc>::Node                     node;
    public:
        typedef Key                                                                             key_type;
        typedef T                                                                               mapped_type;
        typedef ft::pair<const key_type, mapped_type>                                           value_type;
        typedef Compare                                                                         key_compare;
        typedef Alloc                                                                           allocator_type;
        typedef typename allocator_type::reference                                              reference;
        typedef typename allocator_type::const_reference                                        const_reference;
        typedef typename allocator_type::pointer                                                pointer;
        typedef typename allocator_type::const_pointer                                          const_pointer;
        typedef typename redBlackTree<Key, T, Compare, Alloc>::iterator                         iterator;
        typedef typename redBlackTree<Key, T, Compare, Alloc>::const_iterator                   const_iterator;
        typedef typename redBlackTree<Key, T, Compare, Alloc>::reverse_iterator                 reverse_iterator;
        typedef typename redBlackTree<Key, T, Compare, Alloc>::const_reverse_iterator           const_reverse_iterator;
        typedef std::ptrdiff_t                                                                  difference_type;
        typedef std::size_t                                                                     size_type;

        class value_compare
        {
            friend class map;
            protected:
                Compare comp;
                value_compare (Compare c) : comp(c) {}
            public:
                typedef bool            result_type;
                typedef value_type      first_argument_type;
                typedef value_type      second_argument_type;

                bool operator() (const value_type& x, const value_type& y) const
                {
                  return comp(x.first, y.first);
                }
        };




        explicit map (const key_compare& comp = key_compare(), 
                        const allocator_type& alloc = allocator_type())
        {
            (void)comp;
            (void)alloc;
        }

        template <class InputIterator>
        map (InputIterator first, InputIterator last,
                const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type())
        {
            (void)comp;
            (void)alloc;

            for (; first != last; ++first)
               tree.insert(*first);
        }

        map (const map &x) : tree (x.tree) {}

        ~map() { }

        void                    clear() { tree.clear(); }
        size_type               count (const key_type &k) const
        {
            if (tree.find(k) != tree.nil)
                return 1;
            return 0;
        }
        bool                    empty() const
        {
            return tree.empty();
        }
        allocator_type          get_allocator() const
        {
            return allocator_type();
        }
        mapped_type             &operator[] (const key_type &k)
        {
            node    *n = tree.find(k);
            if (n != tree.nil)
                return  n->value->second;
            tree.insert(ft::make_pair(k, mapped_type()));
            return tree.find(k)->value->second;
        }
        size_type               size() const
        {
            return tree.size();
        }
        iterator                begin()
        {
            return tree.begin();
        }
        const_iterator          begin() const
        {
            return tree.begin();
        }
        reverse_iterator        rbegin()
        {
            return tree.rbegin();
        }
        const_reverse_iterator  rbegin() const
        {
            return tree.rbegin();
        }
        iterator                end()
        {
            return tree.end();
        }
        const_iterator          end() const
        {
            return tree.end();
        }
        reverse_iterator        rend()
        {
            return tree.rend();
        }
        const_reverse_iterator  rend() const
        {
            return tree.rend();
        }
        iterator                find (const key_type &k)
        {
            return iterator(tree.find(k), tree.nil, tree.root());
        }
        const_iterator          find (const key_type &k) const
        {
            return const_iterator(tree.find(k), tree.nil, tree.root());
        }
        ft::pair<iterator,bool> insert(const value_type &val)
        {
            node    *p = tree.find(val.first);

            if (p != tree.nil)
                return ft::make_pair(iterator(p, tree.nil, tree.root()), false);
            tree.insert(val);
            p = tree.find(val.first);
            
            return ft::make_pair(iterator(p, tree.nil, tree.root()), true);
        }
        iterator                insert (iterator position, const value_type& val)
        {
            (void) position;
            node    *p = tree.find(val.first);

            if (p != tree.nil)
                return iterator(p, tree.nil, tree.root());
            tree.insert(val);
            p = tree.find(val.first);
            
            return iterator(p, tree.nil, tree.root());
        }
        template <class InputIterator>
        void                    insert (InputIterator first, InputIterator last)
        {
            for (; first != last; ++first)
            {
                if (tree.find(first->first) == tree.nil)
                    tree.insert(*first);
            }
        }
        void                    erase (iterator position)
        {
            erase(position->first);
        }
        size_type               erase (const key_type& k)
        {
            node    *z = tree.find(k);

            if (z != tree.nil)
            {
                tree.erase(z);
                return 1;
            }
            return 0;
        }
        void                    erase (iterator first, iterator last)
        {
            while (first != last)
				erase((first++)->first);
        }
        key_compare             key_comp() const
        {
            return key_compare();
        }
        value_compare           value_comp() const
        {
            return value_compare(key_comp());
        }
        void                    swap (map &x)
        {
            tree.swap(x.tree);
        }
        size_type               max_size() const
        {
            return tree.max_size();
        }
        iterator                lower_bound (const key_type& k)
        {
            node    *p = tree.lower_bound(k);
            return iterator(p, tree.nil, tree.root());
        }
        const_iterator          lower_bound (const key_type& k) const
        {
            node    *p = tree.lower_bound(k);
            return const_iterator(p, tree.nil, tree.root());
        }
        iterator                upper_bound (const key_type& k)
        {
            node    *p = tree.upper_bound(k);
            return iterator(p, tree.nil, tree.root());
        }
        const_iterator          upper_bound (const key_type& k) const
        {
            node    *p = tree.upper_bound(k);
            return const_iterator(p, tree.nil, tree.root());
        }
        ft::pair<const_iterator, const_iterator> equal_range (const key_type &k) const
        {
            return ft::make_pair(lower_bound(k), upper_bound(k));
        }
        ft::pair<iterator, iterator>             equal_range (const key_type &k)
        {
            return ft::make_pair(lower_bound(k), upper_bound(k));
        }
    private:
        redBlackTree<Key, T, Compare, Alloc>    tree;
        
};




template <class Key, class T, class Compare, class Alloc>
void    ft::swap (ft::map<Key, T, Compare, Alloc> &x, ft::map<Key, T, Compare, Alloc> &y)
{
    x.swap(y);
}

template <class Key, class T, class Compare, class Alloc>
    bool    operator== ( const ft::map<Key, T, Compare, Alloc>& lhs,
                        const ft::map<Key, T, Compare, Alloc>& rhs )
{
    if (lhs.size() != rhs.size())
        return false;

    typename ft::map<Key, T, Compare, Alloc>::const_iterator   it = lhs.begin();
    typename ft::map<Key, T, Compare, Alloc>::const_iterator   it1 = rhs.begin();
    
    while (it != lhs.end())
    {
        if (*it != *it1)
            return false;
        ++it;
        ++it1;
    }
    return true;
}

template <class Key, class T, class Compare, class Alloc>
    bool    operator!= ( const ft::map<Key, T, Compare, Alloc>& lhs,
                        const ft::map<Key, T, Compare, Alloc>& rhs )
{
    return !(lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
    bool    operator<  ( const ft::map<Key, T, Compare, Alloc>& lhs,
                        const ft::map<Key, T, Compare, Alloc>& rhs )
{
    typename ft::map<Key, T, Compare, Alloc>::const_iterator   it = lhs.begin();
    typename ft::map<Key, T, Compare, Alloc>::const_iterator   it1 = rhs.begin();

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

template <class Key, class T, class Compare, class Alloc>
    bool    operator<= ( const ft::map<Key, T, Compare, Alloc>& lhs,
                        const ft::map<Key, T, Compare, Alloc>& rhs )
{
    return !(rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
    bool    operator>  ( const ft::map<Key, T, Compare, Alloc>& lhs,
                        const ft::map<Key, T, Compare, Alloc>& rhs )
{
    return rhs < lhs;
}

template <class Key, class T, class Compare, class Alloc>
    bool operator>= ( const ft::map<Key,T,Compare,Alloc>& lhs,
                        const ft::map<Key,T,Compare,Alloc>& rhs )
{
    return !(lhs < rhs);
}









#endif