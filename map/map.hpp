/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:22:14 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/26 18:23:09 by momeaizi         ###   ########.fr       */
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
}


template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class ft::map
{
    private:
        typedef typename redBlackTree<Key, T, Compare, Alloc>::Node                     node;
    public:
        typedef Key                                                                     key_type;
        typedef T                                                                       mapped_type;
        typedef ft::pair<const key_type, mapped_type>                                   value_type;
        typedef Compare                                                                 key_compare;
        // typedef Compare                                 value_compare; // need to be done soon
        typedef Alloc                                                                   allocator_type;
        typedef typename allocator_type::reference                                      reference;
        typedef typename allocator_type::const_reference                                const_reference;
        typedef typename allocator_type::pointer                                        pointer;
        typedef typename allocator_type::const_pointer                                  const_pointer;
        typedef typename redBlackTree<Key, T, Compare, Alloc>::iterator                 iterator;
        typedef typename redBlackTree<Key, T, Compare, Alloc>::const_iterator           const_iterator;
        typedef typename redBlackTree<Key, T, Compare, Alloc>::reverse_iterator         reverse_iterator;
        typedef typename redBlackTree<Key, T, Compare, Alloc>::const_reverse_iterator   const_reverse_iterator;
        typedef std::ptrdiff_t                                                          difference_type;
        typedef std::size_t                                                             size_type;


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
            if (tree.find(k))
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
            if (n)
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
        ft::pair<iterator,bool> insert(const value_type &val)
        {
            node    *p = tree.find(val.first);

            if (p)
                return ft::make_pair(iterator(p), false);
            tree.insert(val);
            p = tree.find(val.first);
            
            return ft::make_pair(iterator(p), true);
        }

        iterator end()
        {
            return tree.end();
        }
        const_iterator end() const
        {
            return tree.end();
        }


        iterator        find (const key_type &k)
        {
            return iterator(tree.find(k));
        }
        const_iterator  find (const key_type &k) const
        {
            return const_iterator(tree.find(k));
        }
        
        iterator                insert (iterator position, const value_type& val)
        {
            (void) position;
            node    *p = tree.find(val.first);

            if (p)
                return iterator(p);
            tree.insert(val);
            p = tree.find(val.first);
            
            return iterator(p);
        }

        template <class InputIterator>
        void                    insert (InputIterator first, InputIterator last)
        {
            for (; first != last; ++first)
            {
                if (!tree.find(first->first))
                    tree.insert(*first);
            }
        }



    private:
        redBlackTree<Key, T, Compare, Alloc>    tree;
        
};



#endif