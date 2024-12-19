/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:10 by tecker            #+#    #+#             */
/*   Updated: 2024/12/19 01:46:25 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename T>
void debugDisplay(const std::string& message, T container)
{
    #ifdef DEBUG
    std::cout << message;

    // Check if the container holds pairs (for containers like std::map or std::vector<std::pair<int, int>>)
    if constexpr (std::is_same<typename T::value_type, std::pair<int, int>>::value) {
        // If it holds pairs, print as pairs
        for (const auto& pair : container) {
            std::cout << "(" << pair.first << ", " << pair.second << ") ";
        }
    } else {
        // Otherwise, print the individual elements
        typename T::iterator it = container.begin();
        while (it != container.end() - 1) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << *it;  // Print the last element
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

void binary_insert(std::vector<int> &main, const int val, std::vector<int>::iterator R)
{
    std::vector<int>::iterator L = main.begin();
    
    while (L < R)
    {
        std::vector<int>::iterator mid = L + (R - L) / 2;
        if (val <= *mid)
            R = mid;
        else
            L = mid + 1;
    }
    main.insert(L, val);
}

std::vector<int> get_order(const std::vector<std::pair<int, int>>& pend)
{
    std::vector<int> order;
    std::vector<int> jacob;

    jacob.push_back(1);
    if (pend.size() > 1)
        jacob.push_back(3);
    while (jacob.back() < (int)pend.size())
        jacob.push_back(2 * jacob[jacob.size() - 2] + jacob.back());
    debugDisplay("jacob numbers: ", jacob);

    size_t i = 0;
    while (i < jacob.size() && jacob[i] <= (int)pend.size())
    {
        order.push_back(jacob[i] - 1);

        if (i > 0)
        {
            for (int j = jacob[i] - 2; j >= jacob[i - 1]; j--)
                order.push_back(j);
        }
        i++;
    }

    for (size_t j = jacob[i - 1]; j < pend.size(); j++)
        order.push_back(j);

    return (order);
}


void insertion_sort(std::vector<int> &main, const std::vector<std::pair<int, int>> pend, int rest)
{
    debugDisplay("main: ", main);
    debugDisplay("pend: ", pend);
    
    std::vector<int> insertion_order = get_order(pend);
    debugDisplay("insertion order (indexes): ", insertion_order);    
    
    for (int index : insertion_order)
        binary_insert(main, pend[index].first, std::find(main.begin(), main.end(), pend[index].second));

    if (rest != -1)
    {
        binary_insert(main, rest, main.end());
        debugDisplay("+ added odd number at the end\n");
    }
}

std::vector<int> PmergeMe::sort_vec()
{   
    std::vector<std::pair<int, int>> pairs;
    std::vector<int> main;
    std::vector<std::pair<int, int>> pend;
    int rest = -1;
    
    if (_input.size() % 2 != 0)
        rest = _input.back();
    
    for (size_t i = 0; i + 1 < _input.size(); i += 2)
    {
        if (_input[i] > _input[i + 1])
            std::swap(_input[i], _input[i + 1]);
        pairs.push_back(std::make_pair(_input[i], _input[i + 1]));
    }

    debugDisplay("pairs before merging: ", pairs);
    merge_sort(pairs, 0, pairs.size() - 1);
    debugDisplay("pairs after merging: ", pairs);
    
    pend.reserve(pairs.size());
    main.reserve(_input.size());
    for (std::pair<int, int> pair : pairs)
        main.push_back(pair.second);
    pend = pairs;

    insertion_sort(main, pend, rest);
    
    return (main);
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