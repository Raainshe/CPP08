/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:33:50 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/23 14:58:12 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span()
{
    std::cout << "Span default constructor called" << std::endl;
    _N = 0;
}

Span::Span(unsigned int N) : _N(N)
{
    std::cout << "Span constructor called" << std::endl;
}

Span::~Span()
{
    std::cout << "Span destructor called" << std::endl;
}

Span::Span(const Span &other) : _N(other._N)
{
    std::cout << "Span copy constructor called" << std::endl;
    _vec = other._vec;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _N = other._N;
        _vec = other._vec;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (_vec.size() >= _N)
        throw SpanIsFull();
    _vec.push_back(number);
}

int Span::shortestSpan()
{
    if (_vec.size() < 2)
        throw std::runtime_error("Not enough numbers to find shortest span");
    std::sort(_vec.begin(), _vec.end());
    int shortest = _vec[_vec.size() - 1] - _vec[0];
    for (size_t i = 0; i < _vec.size() - 1; i++)
    {
        if (_vec[i + 1] - _vec[i] < shortest)
            shortest = _vec[i + 1] - _vec[i];
    }
    return shortest;
}

int Span::longestSpan()
{
    if (_vec.size() < 2)
        throw std::runtime_error("Not enough numbers to find longest span");
    
    int largest = *std::max_element(_vec.begin(), _vec.end());
    int smallest = *std::min_element(_vec.begin(), _vec.end());
    return largest - smallest;
}