/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:10 by tecker            #+#    #+#             */
/*   Updated: 2024/12/18 01:04:17 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void merge(std::vector<std::pair<int, int>> &vec, int start, int end, int middle)
{
    int n1 = middle - start + 1;
    int n2 = end - middle;

    std::vector<std::pair<int, int>> left(vec.begin() + start, vec.begin() + start + n1);
    std::vector<std::pair<int, int>> right(vec.begin() + middle + 1, vec.begin() + middle + 1 + n2);

    int i = 0;
    int j = 0;
    int k = start;

    while (i < n1 && j < n2)
    {
        if (left[i].second <= right[j].second)
            vec[k++] = left[i++];
        else
            vec[k++] = right[j++];
    }

    while (i < n1)
        vec[k++] = left[i++];
    while (j < n2)
        vec[k++] = right[j++];
    
}

void merge_sort(std::vector<std::pair<int, int>> &vec, int start, int end)
{
    if (start < end)
    {
        int middle = start + (end - start) / 2;
        merge_sort(vec, start, middle);   
        merge_sort(vec, middle + 1, end);
        merge(vec, start, end, middle);   
    }
}

void insertion_sort(std::vector<int> &main, std::vector<int> pend)
{
    main.insert(main.begin(), *pend.begin());
    // int size = pend.size() - 1;
    // while (size > 0)
    // {
        
    // }
}

void PmergeMe::sort_vec()
{   
    std::vector<std::pair<int, int>> pairs;
    std::vector<int> main;
    std::vector<int> pend;
    int rest = -1;
    
    if (_input.size() % 2 != 0)
        rest = _input.back();
    
    for (size_t i = 0; i + 1 < _input.size(); i += 2)
    {
        if (_input[i] > _input[i + 1])
            std::swap(_input[i], _input[i + 1]);
        pairs.push_back(std::make_pair(_input[i], _input[i + 1]));
    }

    merge_sort(pairs, 0, pairs.size() - 1);
    
    for (std::pair<int, int> &pair : pairs)
    {
        pend.push_back(pair.first);
        main.push_back(pair.second);
    }
    if (rest != -1)
        pend.push_back(rest);

    insertion_sort(main, pend);
    
    _input = main;
    display();
    _input = pend;
    display();
    
    // return (main);
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
{
}
PmergeMe::PmergeMe(char **argv)
{
    for (int i = 1; argv[i]; i++)
        _input.push_back(std::atoi(argv[i]));
}
PmergeMe::~PmergeMe()
{
}
PmergeMe::PmergeMe(const PmergeMe &src)
    : _input(src._input)
{
}
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
        _input = src._input;
    return (*this);
}