/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:14 by tecker            #+#    #+#             */
/*   Updated: 2024/12/19 01:29:30 by tomecker         ###   ########.fr       */
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
        void sort_deq(void);
};

template <typename T>
void display(T container)
{
    typename T::iterator it = container.begin();
    while (it != container.end() - 1)
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << container.back() << std::endl;
}

template<typename T>
void debugDisplay(const std::string& message, T container);
void debugDisplay(const std::string& message);

#endif