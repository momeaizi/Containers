/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:22:14 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/25 15:48:33 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP


#include <memory>
#include <stdexcept>
#include <iostream>
#include "../utils/pair.hpp"
#include "../red_black_tree/red_black_tree.hpp"


template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class map
{

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
               tree.insert(first->first, first->seconst);
        }

        map (const map &x) : tree (x.tree) {}

        ~map() { }

        void clear() { tree.clear(); }
        size_type   count (const key_type &k) const
        {
            if (tree.findKey(k))
                return 1;
            return 0;
        }
        bool    empty() const
        {
            return tree.empty();
        }
        allocator_type  get_allocator() const
        {
            return allocator_type();
        }
        
    private:
        redBlackTree<Key, T, Compare, Alloc>    tree;
};



#endif