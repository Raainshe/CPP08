/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:52:03 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/23 14:50:35 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack
{
    private:
        std::list<T> _list;
    public:
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack &other);
        ~MutantStack();

        typedef typename std::list<T>::iterator iterator;
        typedef typename std::list<T>::const_iterator const_iterator;
        
        iterator begin() { return _list.begin(); }
        iterator end() { return _list.end(); }
        const_iterator begin() const { return _list.begin(); }
        const_iterator end() const { return _list.end(); }

        void push(const T &value) { _list.push_front(value); }
        void push_back(const T &value) { _list.push_back(value); }
        void pop_back() { _list.pop_back(); }
        void pop() { _list.pop_front(); }
        T &top() { return _list.front(); }
        const T &top() const { return _list.front(); }
        bool empty() const { return _list.empty(); }
        size_t size() const { return _list.size(); }

        // Convert to std::stack
        operator std::stack<T>() const {
            std::stack<T> result;
            // Add elements in reverse order to maintain stack behavior
            for (auto it = _list.rbegin(); it != _list.rend(); ++it) {
                result.push(*it);
            }
            return result;
        }

};

// Template implementations
template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : _list(other._list) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other) {
    if (this != &other) {
        _list = other._list;
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {};

#endif