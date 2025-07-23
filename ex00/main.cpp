/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:18:31 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/23 13:27:07 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);
    try {
        std::cout << easyfind(vec, 3) << std::endl;
        std::cout << easyfind(vec, 2) << std::endl;
        std::cout << easyfind(vec, 10) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;

}