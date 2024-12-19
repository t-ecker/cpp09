/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:18 by tecker            #+#    #+#             */
/*   Updated: 2024/12/19 02:12:18 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool check_args(int argc, char **argv)
{
    if (argc < 3)
        return (std::cerr << "wrong amount of arguments!" << std::endl, false);
    try
    {
        for (int i = 1; i < argc - 1; i++)
        {
            long num = std::atol(argv[i]);
            if (num < 0)
                throw std::invalid_argument("negative number!");
            if (num > INT_MAX)
                throw std::invalid_argument("too large number");
            for (int j = 1; j < argc - 1; j++)
            {
                if (i != j && i > 1)
                {
                    if (num == std::atoi(argv[j]))
                        throw std::invalid_argument("duplicated numbers!");
                }
                
            }        
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error! reason: " << e.what() << std::endl;
        return (false);
    }
    return (true);
}



int main(int argc, char **argv)
{
    // if (!check_args(argc, argv))
    //     return (1);
    (void) argc;
    try
    {
        PmergeMe sort(argv);
        Display("Before: ", sort.getInput());
        std::vector<int> vec = sort.sort_vec();
        Display("After: ", vec);        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    
}