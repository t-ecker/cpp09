/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:10 by tecker            #+#    #+#             */
/*   Updated: 2024/12/16 12:01:14 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void sort()
{
    
}

void display()
{
    
}

void check_args(char **argv)
{
    
}

PmergeMe::PmergeMe()
    :   _stack()
{
}
PmergeMe::PmergeMe(char **argv)
{
    check_args(argv);
    
}
PmergeMe::~PmergeMe()
{
}
PmergeMe::PmergeMe(const PmergeMe &src)
    : _stack()
{
    _str = src._str;
    _stack = src._stack;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        _str = src._str;
        _stack = src._stack;
    }
    return (*this);
}