/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:39:42 by momeaizi          #+#    #+#             */
/*   Updated: 2023/02/14 16:48:03 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <vector>

namespace ft
{
    template <class T, class Container = std::vector<T> >
    class   stack;
}

template <class T, class Container>
class ft::stack
{
    typedef T           value_type;
    typedef Container   container_type;
    typedef size_t      size_type;
    
    protected:
        container_type  ctnr;
    public:
        explicit stack (const container_type &ctnr = container_type()) : ctnr(ctnr) {}

        value_type          &top() { return ctnr.back(); }
        
        const value_type    &top() const { return ctnr.back(); }

        size_type           size() const { return ctnr.size(); }

        void                push (const value_type &val) { ctnr.push_back(val); }

        void                pop() { ctnr.pop_back(); }
        
        bool                empty() const { return ctnr.empty(); }


    template <class _Tp, class _Container>
    friend bool    operator== (const ft::stack<_Tp,_Container> &lhs, const ft::stack<_Tp,_Container> &rhs);

    template <class _Tp, class _Container>
    friend bool    operator!= (const ft::stack<_Tp,_Container> &lhs, const ft::stack<_Tp,_Container> &rhs);

    template <class _Tp, class _Container>
    friend bool    operator<  (const ft::stack<_Tp,_Container> &lhs, const ft::stack<_Tp,_Container> &rhs);

    template <class _Tp, class _Container>
    friend bool    operator<= (const ft::stack<_Tp,_Container> &lhs, const ft::stack<_Tp,_Container> &rhs);

    template <class _Tp, class _Container>
    friend bool    operator>  (const ft::stack<_Tp,_Container> &lhs, const ft::stack<_Tp,_Container> &rhs);

    template <class _Tp, class _Container>
    friend bool    operator>= (const ft::stack<_Tp,_Container> &lhs, const ft::stack<_Tp,_Container> &rhs);

};



template <class _Tp, class _Container>
bool    operator== (const ft::stack<_Tp,_Container> &lhs, const ft::stack<_Tp,_Container> &rhs) { return lhs.ctnr == rhs.ctnr; }

template <class _Tp, class _Container>
bool    operator!= (const ft::stack<_Tp,_Container> &lhs, const ft::stack<_Tp,_Container> &rhs) { return lhs.ctnr != rhs.ctnr; }

template <class _Tp, class _Container>
bool    operator<  (const ft::stack<_Tp,_Container> &lhs, const ft::stack<_Tp,_Container> &rhs) { return lhs.ctnr < rhs.ctnr; }

template <class _Tp, class _Container>
bool    operator<= (const ft::stack<_Tp,_Container> &lhs, const ft::stack<_Tp,_Container> &rhs) { return lhs.ctnr <= rhs.ctnr; }

template <class _Tp, class _Container>
bool    operator>  (const ft::stack<_Tp,_Container> &lhs, const ft::stack<_Tp,_Container> &rhs) { return lhs.ctnr > rhs.ctnr; }

template <class _Tp, class _Container>
bool    operator>= (const ft::stack<_Tp,_Container> &lhs, const ft::stack<_Tp,_Container> &rhs) { return lhs.ctnr >= rhs.ctnr; }

#endif