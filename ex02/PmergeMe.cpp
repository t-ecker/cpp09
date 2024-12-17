/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:10 by tecker            #+#    #+#             */
/*   Updated: 2024/12/17 22:50:04 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void merge(std::vector<int> vec, int start, int end, int middle)
{
    
}

void merge_sort(std::vector<int> vec, int start, int end)
{
    if (start < end)
    {
        int middle = start + (end - start) / 2;
        merge_sort(vec, start, middle);   
        merge_sort(vec, middle + 1, end);
        merge(vec, start, end, middle);   
    }
}

void PmergeMe::sort_vec()
{   
    std::vector<int> main;
    std::vector<int> pend;
    
    for (std::vector<int>::iterator it = _input.begin(); it != _input.end(); it++)
    {
        if (it + 1 != _input.end())
        {
            pend.push_back(std::min(*it, *(it + 1)));
            main.push_back(std::max(*it, *(it + 1)));
            it++;
        }
        else
            pend.push_back(*it);
    }
    
    merge_sort(main, 0, main.size() - 1);
    insert_sort(main, pend);
    
    return (main);
}

void PmergeMe::display()
{
    std::vector<int>::iterator it = _input.begin();
    std::cout << "values:";
    while (it != _input.end())
    {
        std::cout << " " << *it;
        it++;
    }
    std::cout << std::endl;
} 

PmergeMe::PmergeMe()
    : _n(0)
{
}
PmergeMe::PmergeMe(char **argv)
{
    for (int i = 1; argv[i]; i++)
        _input.push_back(std::atoi(argv[i]));
    _n = _input.size();
}
PmergeMe::~PmergeMe()
{
}
PmergeMe::PmergeMe(const PmergeMe &src)
    : _input(src._input), _n(src._n)
{
}
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        _input = src._input;
        _n = src._n;
    }
    return (*this);
}