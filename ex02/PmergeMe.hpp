/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:14 by tecker            #+#    #+#             */
/*   Updated: 2024/12/19 17:43:22 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>

class PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        std::vector<int> sort_vec(std::vector<int> input);
        std::deque<int> sort_deq(std::deque<int> input);
};

void debugDisplay_text(const std::string& message);

template<typename T>
void debugDisplay_container(const std::string& message, T container)
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
#endif