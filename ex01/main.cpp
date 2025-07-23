/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:32:17 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/23 14:59:22 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void personal_tests()
{
    Span sp = Span(100000);
    for (int i = 0; i < 100000; i++)
    {
        sp.addNumber(rand() % 100000);
    }
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

int main()
{
    Span sp = Span(5);
    sp.addNumber(17);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "--------------------------------" << std::endl;

    //personal tests
    std::cout << "Personal tests" << std::endl;
    personal_tests();
}