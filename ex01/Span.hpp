/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:31:14 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/23 13:43:54 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _vec;

    public:
        Span();
        Span(unsigned int N);
        ~Span();
        Span(const Span &other);
        Span &operator=(const Span &other);
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();

    class SpanIsFull : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return "Span is full";
            }
    };
};

#endif