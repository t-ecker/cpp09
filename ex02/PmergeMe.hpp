/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:14 by tecker            #+#    #+#             */
/*   Updated: 2024/12/19 14:45:50 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string.h>
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

template<typename T>
void debugDisplay(const std::string& message, T container);
void debugDisplay(const std::string& message);

#endif