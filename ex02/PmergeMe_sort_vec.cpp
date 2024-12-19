/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_sort_vec.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:16:23 by tecker            #+#    #+#             */
/*   Updated: 2024/12/19 14:42:14 by tecker           ###   ########.fr       */
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
    // debugDisplay("jacob numbers: ", jacob);

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
    // debugDisplay("main: ", main);
    // debugDisplay("pend: ", pend);
    
    std::vector<int> insertion_order = get_order(pend);
    // debugDisplay("insertion order (indexes): ", insertion_order);    
    
    for (int index : insertion_order)
        binary_insert(main, pend[index].first, std::find(main.begin(), main.end(), pend[index].second));

    if (rest != -1)
    {
        binary_insert(main, rest, main.end());
        // debugDisplay("+ added odd number at the end\n");
    }
}

std::vector<int> PmergeMe::sort_vec(std::vector<int> input)
{   
    std::vector<std::pair<int, int>> pairs;
    std::vector<int> main;
    std::vector<std::pair<int, int>> pend;
    int rest = -1;
    
    if (input.size() % 2 != 0)
        rest = input.back();
    
    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        if (input[i] > input[i + 1])
            std::swap(input[i], input[i + 1]);
        pairs.push_back(std::make_pair(input[i], input[i + 1]));
    }

    // debugDisplay("pairs before merging: ", pairs);
    merge_sort(pairs, 0, pairs.size() - 1);
    // debugDisplay("pairs after merging: ", pairs);
    
    pend.reserve(pairs.size());
    main.reserve(input.size());
    for (std::pair<int, int> pair : pairs)
        main.push_back(pair.second);
    pend = pairs;

    insertion_sort(main, pend, rest);
    
    return (main);
}