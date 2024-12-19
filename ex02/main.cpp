/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:18 by tecker            #+#    #+#             */
/*   Updated: 2024/12/19 17:42:33 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <chrono>
#include <unordered_set>

template<typename T>
void Display(const std::string& message, T container)
{
    std::cout << message;
    typename T::iterator it = container.begin();
    while (it != container.end() - 1)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << *it;
    std::cout << std::endl;
}

void debugDisplay_text(const std::string& message)
{
    #ifdef DEBUG
    std::cout << message << std::endl;
    #endif
    (void)message;
}

std::vector<int> check_args(int argc, char **argv)
{
    std::vector<int> vec;
    if (argc < 3)
        throw std::out_of_range("wrong amount of arguments!");

    for (int i = 1; argv[i]; i++)
    {
        long num = std::atol(argv[i]);
        if (num < 0)
            throw std::invalid_argument("negative number found!");
        if (num > INT_MAX)
            throw std::invalid_argument("too large number found!");
        vec.push_back(std::atoi(argv[i]));
    }
    // std::unordered_set<int> set;
    // for (int num : vec)
    // {
    //     if (set.find(num) != set.end())
    //     {
    //         std::cout << "found num: " << num << " at " << *(set.find(num)) << std::endl;
    //         throw std::invalid_argument("duplicate values found!");
    //     }
    //     set.insert(num);
    // }
    return (vec);
}

int main(int argc, char **argv)
{
    try
    {
        PmergeMe sort;
        std::vector<int> vec;
        std::deque<int> deq;

        vec = check_args(argc, argv);
        std::copy(vec.begin(), vec.end(), std::back_inserter(deq));
        
        Display("Before: ", vec);
        
        std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
        vec = sort.sort_vec(vec);
        std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> duration_vec = end - start;
        start = std::chrono::high_resolution_clock::now();
        deq = sort.sort_deq(deq);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> duration_deq = end - start;
        Display("After (vector): ", vec);
        Display("After (deque): ", deq);
        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << duration_vec.count() << " µs" << std::endl;
        std::cout << "Time to process a range of " << vec.size() << " elements with std::deque : " << std::fixed << duration_deq.count() << " µs" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "[Error]: " << e.what() << std::endl;
    }
}

//  ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`