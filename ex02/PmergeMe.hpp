/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:14 by tecker            #+#    #+#             */
/*   Updated: 2024/12/19 02:12:25 by tomecker         ###   ########.fr       */
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
    private:
        std::vector<int> _input;
    public:
        PmergeMe();
        PmergeMe(char **argv);
        ~PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        std::vector<int> sort_vec(void);
        std::deque<int> sort_deq(void);
        std::vector<int> getInput() const;
};

void Display(const std::string& message, std::vector<int> container);

template<typename T>
void debugDisplay(const std::string& message, T container);
void debugDisplay(const std::string& message);

#endif