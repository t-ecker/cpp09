/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:14 by tecker            #+#    #+#             */
/*   Updated: 2024/12/16 12:00:42 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string.h>
#include <iostream>
#include <stdexcept>
#include <stack>

int is_operator(char c);

class PmergeMe
{
    private:
        std::string _str;
        std::stack<double> _stack;
    public:
        PmergeMe();
        PmergeMe(char **argv);
        ~PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        void sort();
        void display();
        void check_args(char **argv);
};


#endif