/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:17:06 by tecker            #+#    #+#             */
/*   Updated: 2024/12/19 14:38:47 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


template<typename T>
void debugDisplay(const std::string& message, T container)
{
    #ifdef DEBUG
    std::cout << message;

    if constexpr (std::is_same<typename T::value_type, std::pair<int, int>>::value)
    {
        for (const auto& pair : container)
            std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    else
    {
        typename T::iterator it = container.begin();
        while (it != container.end() - 1)
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << *it;
    }
    std::cout << "\n" << std::endl;
    #endif
    (void)message;
    (void)container;
}

void debugDisplay(const std::string& message)
{
    #ifdef DEBUG
    std::cout << message << std::endl;
    #endif
    (void)message;
}